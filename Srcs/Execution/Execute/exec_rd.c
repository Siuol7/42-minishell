/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:39:39 by tripham           #+#    #+#             */
/*   Updated: 2025/04/04 17:21:59 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_redirection(t_cmd *cmd)
{
	int	fd;
	int	i;

	if (cmd->in.type == RD_IN)
	{
		fd = open(cmd->in.val, O_RDONLY);
		if (fd < 0)
		{
			perror(cmd->in.val);
			return (EXIT_FAILURE);
		}
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	else if (cmd->in.type == RD_HEREDOC)
	{
		fd = open(cmd->in.val, O_RDONLY);
		if (fd < 0)
		{
			perror("heredoc temp");
			return (EXIT_FAILURE);
		}
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
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
			perror(cmd->out[i].val);
			return (EXIT_FAILURE);
		}
		dup2(fd, STDOUT_FILENO);
		close(fd);
		i++;
	}
	return (EXIT_SUCCESS);
}
