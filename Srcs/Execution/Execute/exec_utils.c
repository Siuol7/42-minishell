/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:06:39 by tripham           #+#    #+#             */
/*   Updated: 2025/04/13 23:51:36 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	update_status(t_shell *mns, int new_status)
{
	if (new_status >= 0)
		mns->exitcode = new_status;
	return (mns->exitcode);
}

void	wait_update(t_shell *mns, pid_t pid)
{
	int	status;

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		update_status(mns, WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGINT)
			printf("\n");
		update_status(mns, 128 + WTERMSIG(status));
	}
	signals_initialize();
}

char	*heredoc_tmp(char *limiter, int index)
{
	char	*filename;
	int		fd;
	char	*line;

	filename = ft_strjoin(".heredoc_tmp_", ft_itoa(index));
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("open failed");
		return (NULL);
	}
	signals_configure(SIGINT, handle_sigint_heredoc);
	while (1)
	{
		// line = readline("> ");

		//-------------------------------------------------------
		// TESTER
		//-------------------------------------------------------

		if (isatty(fileno(stdin)))
			line = readline("> ");
		else
		{
			char *tmp = get_next_line(fileno(stdin));
			line = ft_strtrim(tmp, "\n");
			free(tmp);
		}
		
		
		if (!line || !ft_strcmp(line, limiter))
			break ;
		ft_printf_fd(fd, line);
		ft_printf_fd(fd, "\n");
		free(line);
	}
	if (!line)
	{
		free(line);
	}
	}
	// while (1)
	// {
	// 	line = readline("> ");
	// 	if (!line || !ft_strcmp(line, limiter))
	// 		break ;
	// 	ft_printf_fd(fd, line);
	// 	ft_printf_fd(fd, "\n");
	// 	free(line);
	// }
	// free(line);
	close(fd);
	signals_initialize();
	return (filename);
}

void	heredoc_expand_all(t_shell *mns)
{
	int		i;
	char	*tmpfile;

	i = 0;
	while (i < mns->group_cnt)
	{
		if (mns->cmd_group[i].in.type == RD_HEREDOC)
		{
			tmpfile = heredoc_tmp(mns->cmd_group[i].in.val, i);
			printf("reach here %s\n", mns->cmd_group[i].in.val);
			if (!tmpfile)
			{
				ft_printf_fd(STDERR_FILENO, "heredoc error\n");
				mns->shell_err = 1;
				return ;
			}
			free(mns->cmd_group[i].in.val);
			mns->cmd_group[i].in.val = tmpfile;
		}
		i++;
	}
}

void	exec_error(t_shell *mns, char *cmd_path, char *ms1, char *ms2)
{
	if (ms1 && ms2)
		ft_printf_fd(STDERR_FILENO, "%s: %s\n", ms1, ms2);
	if (cmd_path)
		free(cmd_path);
	shell_clean(mns);
	exit(update_status(mns, 126));
}

void	cleanup_heredoc_files(void)
{
	int		i;
	char	*filename;
	char	*idx;

	i = 0;
	while (i < 100)
	{
		idx = ft_itoa(i);
		filename = ft_strjoin(".heredoc_tmp_", idx);
		free(idx);
		unlink(filename);
		free(filename);
		i++;
	}
}
