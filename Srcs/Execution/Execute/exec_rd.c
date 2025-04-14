/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:39:39 by tripham           #+#    #+#             */
/*   Updated: 2025/04/15 00:18:54 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_rd_in(t_cmd *cmd)
{
	int	fd;

	if (cmd->in.type == RD_IN || cmd->in.type == RD_HEREDOC)
	{
		fd = open(cmd->in.val, O_RDONLY);
		if (fd < 0)
		{
			if (cmd->in.type == RD_HEREDOC)
				perror("heredoc temp");
			else
				perror(cmd->in.val);
			return (EXIT_FAILURE);
		}
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	return (EXIT_SUCCESS);
}

static int	handle_rd_out(t_cmd *cmd)
{
	int	fd;
	int	i;

	i = 0;
	while (i < cmd->out_cnt)
	{
		if (cmd->out[i].type == RD_OUT)
			fd = open(cmd->out[i].val, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		else if (cmd->out[i].type == RD_APPEND)
			fd = open(cmd->out[i].val, O_CREAT | O_WRONLY | O_APPEND, 0644);
		else
		{
			i++;
			continue ;
		}
		if (fd < 0)
		{
			ft_printf_fd(STDERR_FILENO, "minishell: %s\n", strerror(errno));
			return (EXIT_FAILURE);
		}
		dup2(fd, STDOUT_FILENO);
		close(fd);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	handle_redirection(t_cmd *cmd)
{
	if (handle_rd_in(cmd) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (handle_rd_out(cmd) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
