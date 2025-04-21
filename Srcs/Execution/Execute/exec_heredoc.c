/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:58:07 by tripham           #+#    #+#             */
/*   Updated: 2025/04/21 05:03:24 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	print_heredoc(t_shell *mns, int fd, char *limiter, int is_exp)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			ft_printf_fd(STDERR_FILENO, "bash: warning: here-document "
				"delimited by end-of-file (wanted `%s')\n", limiter);
			return (1);
		}
		if (!line || !ft_strcmp(line, limiter))
			break ;
		if (is_exp == 0)
			hd_expansion_gen(mns, &line);
		ft_printf_fd (fd, "%s\n", line);
		free(line);
	}
	free(line);
	return (0);
}
static void	printf_hd_helper(t_shell *mns, char *filename, char *lim_copy, int fd)
{
	mns->exitcode = 1;
	unlink(filename);
	free(filename);
	free(lim_copy);
	close(fd);
	signals_initialize();
}
char	*heredoc_tmp(t_shell *mns, char *limiter, int index)
{
	char	*filename;
	char	*lim_copy;
	int		fd;
	int		is_exp;

	lim_copy = ft_strdup(limiter);
	filename = heredoc_filename(index);
	if (filename == NULL)
		return (perror("heredoc_tmp failed"), NULL);
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		return (perror("open failed"), free(filename), NULL);
	signals_configure(SIGINT, handle_sigint_heredoc);
	is_exp = exp_check_quotes(mns, &lim_copy);
	if (print_heredoc(mns, fd, lim_copy, is_exp))
	{
		printf_hd_helper(mns, filename, lim_copy, fd);
		return (NULL);
	}
	close(fd);
	free(lim_copy);
	signals_initialize();
	return (filename);
}

static void	printf_wrong_eof(char *limiter)
{
	ft_printf_fd(2, "bash: ");
	ft_printf_fd(2,
		"unxpected EOF while looking for matching `%c'\n",
		which_quote(limiter));
}

void	heredoc_expand_all(t_shell *mns)
{
	int		i;
	char	*tmpfile;

	i = 0;
	while (i < mns->group_cnt)
	{
		if (exp_hd_check_nl(mns->cmd_group[i].in.val) == 1)
		{
			printf_wrong_eof(mns->cmd_group[i].in.val);
			return ;
		}
		if (mns->cmd_group[i].in.type == RD_HEREDOC)
		{
			tmpfile = heredoc_tmp(mns, mns->cmd_group[i].in.val, i);
			if (!tmpfile)
				return ;
			free(mns->cmd_group[i].in.val);
			mns->cmd_group[i].in.val = tmpfile;
		}
		i++;
	}
}
// chua cap nhat exit_code