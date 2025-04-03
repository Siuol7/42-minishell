/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:39:39 by tripham           #+#    #+#             */
/*   Updated: 2025/04/02 20:13:58 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static int	exec_rd_in(t_ast *token)
// {
// 	int	fd;

// 	fd = open(token->token.val, O_RDONLY);
// 	if (fd == -1)
// 	{
// 		ft_printf_fd(2, "minishell: %s: %s\n", token->token.val, strerror(errno));
// 		return (-1);
// 	}
// 	redirect_fd(fd, STDIN_FILENO);
// 	return (0);
// }

// static int exec_rd_out(t_ast *token)
// {
//     int fd;

//     fd = open(token->token.val, O_CREAT | O_WRONLY | O_TRUNC, 0644);
//     if (fd < 0)
//     {
//         perror("open failed");
//         return (-1);
//     }
//     redirect_fd(fd, STDOUT_FILENO);
//     return (0);
// }

// static void	my_putstr_fd(char *s, int fd)
// {
// 	while (*s)
// 	{
// 		ft_printf_fd(fd, "%s", s);
// 		s++;
// 	}
// }

// static int	exec_open_hd(char *heredoc)
// {
// 	int	pipe_fd[2];

// 	if (pipe(pipe_fd) == -1)
// 	{
// 		ft_printf_fd(2, "minishell: pipe error: %s\n", strerror(errno));
// 		return (-1);
// 	}
// 	my_putstr_fd(heredoc, pipe_fd[1]);
// 	close(pipe_fd[1]);
// 	return (pipe_fd[0]);
// }


// static int	exec_rd_heredoc(t_ast *token)
// {
// 	int	fd;

// 	fd = exec_open_hd(token->token.val);
// 	if (fd == -1)
// 	{
// 		ft_printf_fd(2, "minishell: heredoc error\n");
// 		return (-1);
// 	}
// 	redirect_fd(fd, STDIN_FILENO);
// 	return (0);
// }

// static int	exec_rd_append(t_ast *token)
// {
// 	int	fd;

// 	fd = open(token->token.val, O_CREAT | O_RDWR | O_APPEND, 0644);
// 	if (fd == -1)
// 	{
// 		ft_printf_fd(2, "minishell: %s: %s\n", token->token.val, strerror(errno));
// 		return (-1);
// 	}
// 	redirect_fd(fd, STDOUT_FILENO);
// 	return (0);
// }

// int	exec_rd_process(t_ast *token)
// {
// 	if (token->token.type == RD_IN)
// 		return (exec_rd_in(token));
// 	else if (token->token.type == RD_OUT)
// 		return (exec_rd_out(token));
// 	else if (token->token.type == RD_APPEND)
// 		return (exec_rd_append(token));
// 	else if (token->token.type == RD_HEREDOC)
// 		return (exec_rd_heredoc(token));
// 	return (0);
// }

int	handle_redirection(t_cmd *cmd)
{
	int	fd;
	int	i;

	// Input redirect: <
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
	// Heredoc: <<
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

	// Output redirect: > hoặc >>
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
			continue;
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
