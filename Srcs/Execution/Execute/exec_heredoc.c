/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:58:07 by tripham           #+#    #+#             */
/*   Updated: 2025/04/18 20:06:52 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*heredoc_filename(int index)
{
	char	*filename;
	char	*index_str;

	index_str = ft_itoa(index);
	if (index_str == NULL)
	{
		perror("heredoc_filename failed");
		return (NULL);
	}
	filename = ft_strjoin(".heredoc_tmp_", index_str);
	if (filename == NULL)
	{
		free(index_str);
		perror("heredoc_filename failed");
		return (NULL);
	}
	free(index_str);
	return (filename);
}

static int	print_heredoc(int fd, char *limiter)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			ft_printf_fd(STDERR_FILENO, "minishell: warning: here-document "
				"delimited by end-of-file (wanted `%s')\n", limiter);
			return (0);
		}
		if (!line || !ft_strcmp(line, limiter))
			break ;
		ft_printf_fd (fd, "%s\n", line);
		free(line);
	}
	free(line);
	return (0);
}

char	*heredoc_tmp(t_shell *mns, char *limiter, int index)
{
	char	*filename;
	int		fd;

	filename = heredoc_filename(index);
	if (filename == NULL)
		return (perror("heredoc_tmp failed"), NULL);
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		return (perror("open failed"), free(filename), NULL);
	signals_configure(SIGINT, handle_sigint_heredoc);
	if (print_heredoc(fd, limiter))
	{
		mns->exitcode = 1;
		unlink(filename);
		free(filename);
		close(fd);
		signals_initialize();
		return (NULL);
	}
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
			tmpfile = heredoc_tmp(mns, mns->cmd_group[i].in.val, i);
			if (!tmpfile)
			{
				ft_printf_fd(STDERR_FILENO, "heredoc error\n");
				mns->exitcode = 1;
				return ;
			}
			free(mns->cmd_group[i].in.val);
			mns->cmd_group[i].in.val = tmpfile;
		}
		i++;
	}
}
