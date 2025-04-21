/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:39:39 by tripham           #+#    #+#             */
/*   Updated: 2025/04/22 01:04:09 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static int	handle_rd_in(t_cmd *cmd)
// {
// 	int	fd;
// 	int	i;

// 	i = 0;
// 	fd = -1;
// 	while (i < cmd->in_cnt)
// 	{
// 		if (cmd->in[i].type == RD_IN || cmd->in[i].type == RD_HEREDOC)
// 		{
// 			if (fd != -1)
// 				close(fd);
// 			fd = open(cmd->in[i].val, O_RDONLY);
// 			if (fd < 0)
// 			{
// 				if (cmd->in[i].type == RD_IN)
// 					ft_printf_fd(2, "bash: %s: No such file or directory\n", cmd->in[i].val);
// 				return (EXIT_FAILURE);
// 			}
// 		}
// 		i++;
// 	}
// 	if (fd != -1)
// 	{
// 		dup2(fd, STDIN_FILENO);
// 		close(fd);
// 	}
// 	return (EXIT_SUCCESS);
// }

static int	handle_rd_in(t_cmd *cmd)
{
	int	fd;
	int	i;
	int	j;

	i = -1;
	fd = -1;
	j = 0;
	while (++i < cmd->in_cnt)
	{
		if (cmd->in[i].type == RD_IN)
		{
			if (fd != -1)
				close (fd);
			fd = open(cmd->in[i].val, O_RDONLY);
			if (fd < 0)
			{
				ft_printf_fd(2, "bash: %s: No such file or directory\n", cmd->in[i].val);
				return (EXIT_FAILURE);
			}
		}
		else
		{
			if (fd != -1)
				close (fd);
			fd = open(cmd->heredoc[j], O_RDONLY);
			if (fd < 0)
			{
				// perror("heredoc failed\n");
				return (EXIT_FAILURE);
			}
			j++;
		}
	}
	if (fd != -1)
	{
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
			ft_printf_fd(STDERR_FILENO, "bash: %s\n", strerror(errno));
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
