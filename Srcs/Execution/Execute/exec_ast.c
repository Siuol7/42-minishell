/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:27:56 by tripham           #+#    #+#             */
/*   Updated: 2025/04/04 16:47:47 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static pid_t	fork_and_exec(t_ast *node, t_shell *mns, int fd, int std_fd, int pipe_fd[2])
{
	pid_t	pid = fork();

	if (pid == 0)
	{
		handle_signals_default();
		dup2(fd, std_fd);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		exec_ast(node, mns);
		exit(mns->exitcode);
	}
	return (pid);
}

void exec_ast(t_ast *node, t_shell *mns)
{
	int		pipe_fd[2];
	pid_t	left_pid;
	pid_t	right_pid;

	if (!node)
		return ;
	if (node->type == NODE_CMD)
	{
		exec_cmd(mns, &mns->cmd_group[node->cmd_index]);
		return ;
	}
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe error");
		return ;
	}
	left_pid = fork_and_exec(node->left, mns, pipe_fd[1], STDOUT_FILENO, pipe_fd);
	right_pid = fork_and_exec(node->right, mns, pipe_fd[0], STDIN_FILENO, pipe_fd);
	if (left_pid == -1 || right_pid == -1)
	{
		handle_fork_error(pipe_fd);
		return ;
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	wait_update(mns, left_pid);
	wait_update(mns, right_pid);
}

// left_pid = fork();
// 	if (left_pid == 0)
// 	{
// 		handle_signals_default();
// 		dup2(pipe_fd[1], STDOUT_FILENO);
// 		close(pipe_fd[0]);
// 		close(pipe_fd[1]);
// 		exec_ast(node->left, mns);
// 		exit(mns->exitcode);
// 	}
// 	right_pid = fork();
// 	if (right_pid == 0)
// 	{
// 		handle_signals_default();
// 		dup2(pipe_fd[0], STDIN_FILENO);
// 		close(pipe_fd[0]);
// 		close(pipe_fd[1]);
// 		exec_ast(node->right, mns);
// 		exit(mns->exitcode);
// 	}