/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:27:56 by tripham           #+#    #+#             */
/*   Updated: 2025/04/03 20:06:14 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	left_pid = fork();
	if (left_pid == 0)
	{
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		exec_ast(node->left, mns);
		exit(mns->exitcode);
	}
	right_pid = fork();
	if (right_pid == 0)
	{
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		exec_ast(node->right, mns);
		exit(mns->exitcode);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(left_pid, NULL, 0);
	waitpid(right_pid, NULL, 0);
}