/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:58:07 by tripham           #+#    #+#             */
/*   Updated: 2025/04/19 04:41:07 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exp_check_quotes(t_shell *mns, char **limiter)
{
	int i;
	char *temp;

	i = 0;
	while (*limiter[i])
	{
		if (*limiter[i] == '\'' || *limiter[i] == '\"')
		{
			temp = lx_qmarks_eli(mns, *limiter, 0 , 0);
			free(*limiter);
			*limiter = temp;
			return (1);
		}
		i++;
	}
	return (0);
}

static int exp_hd_check_nl(char *limiter)
{
	int i;

	i = 0;
	if (!limiter)
		return (0);
	while (limiter[i])
	{
		if (limiter[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char which_quote(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			return ('\'');
		else if (str[i] == '\"')
			return ('\"');
		i++;
	}
	return (0);
}

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


static int	print_heredoc(int fd, char *limiter, int is_exp)
{
	char	*line;

	(void)is_exp;
	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			ft_printf_fd(STDERR_FILENO, "bash: warning: here-document "
				"delimited by end-of-file (wanted `%s')\n", limiter);
			return (0);
		}
		if (!line || !ft_strcmp(line, limiter))
			break ;
		// if (is_exp == 0)
		// 	exp_hd_gen(&line);
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
	int 	is_exp;

	filename = heredoc_filename(index);
	if (filename == NULL)
		return (perror("heredoc_tmp failed"), NULL);
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		return (perror("open failed"), free(filename), NULL);
	signals_configure(SIGINT, handle_sigint_heredoc);
	is_exp = exp_check_quotes(mns, &limiter);
	if (print_heredoc(fd, limiter, is_exp))
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
	char	c;
	i = 0;
	while (i < mns->group_cnt)
	{
		if (exp_hd_check_nl(mns->cmd_group[i].in.val) == 1)
		{
			c = which_quote(mns->cmd_group[i].in.val);
			ft_printf_fd(2, "bash: unxpected EOF while looking for matching `%c'\n", c);
			return ;
		}
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
