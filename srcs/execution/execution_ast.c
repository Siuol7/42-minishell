/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_ast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:27:56 by tripham           #+#    #+#             */
/*   Updated: 2025/03/18 19:49:18 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	execute_cmd(t_shell *mns, t_token token)
{
	(void)mns;
	ft_printf_fd(STDOUT_FILENO, "Executing command: %s\n", token.val);
}

static void	execute_rd()
{
	
}

static void	execute_pipe(t_shell *mns, t_ast *ast)
{
	int		pipe_fd[2];
	pid_t	pid[2];

	if (pipe(pipe_fd) == -1)
	{
		perror("pipe failed");
		return ;
	}
	pid[0] = fork();
	if (pid[0] == -1)
	{
		perror("fork failed");
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		return ;
	}
	if (pid[0] == 0)
	{
		close(pipe_fd[0]);
		redirect_fd(pipe_fd[1], STDOUT_FILENO);
		execute_ast(mns, ast->left);
		exit (0);
	}
	pid[1] = fork();
	if (pid[1] == -1)
	{
		perror("fork failed");
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		return ;
	}
	if (pid[1] == 0)
	{
		close(pipe_fd[1]);
		redirect_fd(pipe_fd[0], STDIN_FILENO);
		execute_ast(mns, ast->right);
		exit (0);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
}

void	execute_ast(t_shell *mns, t_ast *ast)
{
	if (!ast)
		return ;
	if (ast->token.type == OP_PIPE)
		execute_pipe(mns, ast);
	else if (ast->token.type == RD_IN || ast->token.type == RD_OUT
		|| ast->token.type == RD_APPEND || ast->token.type == RD_HEREDOC)
		execute_rd(mns, ast);
	else if (ast->left)
		execute_ast(mns, ast->left);
	else if (ast->right)
		execute_ast(mns, ast->right);
	else if (ast->token.type == CMD)
		execute_cmd(mns, ast->token);
}
