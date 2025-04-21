/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:27:56 by tripham           #+#    #+#             */
/*   Updated: 2025/04/22 00:39:01 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static pid_t	fork_and_exec_left(t_ast *node, t_shell *mns,
								int fd, int pipe_fd[2])
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		handle_signals_default();
		dup2(fd, STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		exec_ast(node, mns);
		exit(mns->exitcode);
	}
	return (pid);
}

static pid_t	fork_and_exec_right(t_ast *node, t_shell *mns,
								int fd, int pipe_fd[2])
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		handle_signals_default();
		dup2(fd, STDIN_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		exec_ast(node, mns);
		exit(mns->exitcode);
	}
	return (pid);
}

void	exec_ast(t_ast *node, t_shell *mns)
{
	int		pipe_fd[2];
	pid_t	left_pid;
	pid_t	right_pid;

	if (!node)
		return ;
	if (node->type == NODE_CMD)
		return (exec_cmd(mns, &mns->cmd_group[node->cmd_index]));
	if (pipe(pipe_fd) == -1)
		return (perror("pipe error"));
	left_pid = fork_and_exec_left(node->left, mns, pipe_fd[1], pipe_fd);
	right_pid = fork_and_exec_right(node->right, mns, pipe_fd[0], pipe_fd);
	if (left_pid == -1 || right_pid == -1)
		return (handle_fork_error(pipe_fd));
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	wait_update(mns, left_pid);
	wait_update(mns, right_pid);
}
