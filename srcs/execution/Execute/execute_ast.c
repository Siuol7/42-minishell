/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_ast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:27:56 by tripham           #+#    #+#             */
/*   Updated: 2025/03/23 01:56:41 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	init_child(int *pipe_fd, pid_t *pid)
{
	*pid = fork();
	if (*pid == -1)
	{
		perror("minishell: fork failed");
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static void	execute_child(t_shell *mns, t_ast *ast, int *pipe_fd, int left)
{
	handle_signals_default();
	if (left)
	{
		close(pipe_fd[0]);
		redirect_fd(pipe_fd[1], STDOUT_FILENO);
		execute_ast(mns, ast->left);
	}
	else
	{
		close(pipe_fd[1]);
		redirect_fd(pipe_fd[0], STDIN_FILENO);
		execute_ast(mns, ast->right);
	}
	free_all(&ast, &mns);
	exit(mns->exitcode);
}

static void	execute_pipe(t_shell *mns, t_ast *ast)
{
	int		pipe_fd[2];
	pid_t	pid[2];

	if (pipe(pipe_fd) == -1)
	{
		perror("minishell: pipe failed");
		exit(EXIT_FAILURE);
	}
	if (init_child(pipe_fd, &pid[0]) == EXIT_FAILURE)
		return ;
	if (pid[0] == 0)
		execute_child(mns, ast, pipe_fd, 1);
	if (init_child(pipe_fd, &pid[1]) == EXIT_FAILURE)
		return ;
	if (pid[1] == 0)
		execute_child(mns, ast, pipe_fd, 0);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	wait_update(mns, pid[1]);
}

static void	execute_cmd(t_shell *mns, t_token token)
{
	(void)mns;
	(void)token;
	printf("command execute\n");
}

void	execute_ast(t_shell *mns, t_ast *ast)
{
	if (ast->token.type == OP_PIPE)
		execute_pipe(mns, ast);
	else if (ast->left)
		execute_ast(mns, ast->left);
	else if (ast->right)
		execute_ast(mns, ast->right);
	else if (ast->token.type == CMD)
		execute_cmd(mns, ast->token);
	while (wait(NULL) > 0)
		;
}
