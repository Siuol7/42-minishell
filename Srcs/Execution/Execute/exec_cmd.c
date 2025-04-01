/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:13:21 by tripham           #+#    #+#             */
/*   Updated: 2025/03/29 22:08:42 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_non_builtin(t_shell *mns, t_token token)
{
	pid_t	pid;
	char	*command_path;

	(void)token;
	pid = fork();
	if (pid == -1)
	{
		perror("minishell: fork failed");
		exit (EXIT_FAILURE);
	}
	if (pid == 0)
	{
		handle_signals_default();
		command_path = found_command_path(mns, mns->cmd[0].cmd_gr[0]);
		if (!command_path)
		{
			free_all(&mns->ast, &mns);
			exit(127);
		}
		execve(command_path, mns->cmd[0].cmd_gr, mns->env); // check
		handle_execution_error(command_path, mns->cmd[0].cmd_gr);
	}

	wait_update(mns, pid);
}

int exec_rd_io(t_shell *mns, t_ast *rd_ast, int *fd)
{
	int	res;

	if (!rd_ast)
		return (EXIT_FAILURE);
	res = exec_rd_io(mns, rd_ast->left);
	if (res == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (rd_ast->token.type == RD_IN || rd_ast->token.type == RD_OUT
		|| rd_ast->token.type == RD_APPEND || rd_ast->token.type == RD_HEREDOC)
		{
			res = exec_rd_process(rd_ast);
			if (res == -1)
				return (EXIT_FAILURE);
		}
	res = exec_rd_io(mns, rd_ast->right);
	if (res == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	is_rd(t_token_type type)
{
    return (type == RD_IN || type == RD_OUT ||
		type == RD_APPEND || type == RD_HEREDOC);
}

void	exec_cmd(t_shell *mns, t_token token)
{

	// const int	tmp[2] = {dup(STDIN_FILENO), dup(STDOUT_FILENO)};
	
	// if (mns->ast)
	// {
	// 	if (mns->ast->left && is_rd(mns->ast->left->token.type))
	// 	{
	// 		if (exec_rd_io(mns, mns->ast->left) == EXIT_FAILURE)
	// 		{
	// 			redirect_fd(tmp[0], STDIN_FILENO);
	// 			redirect_fd(tmp[1], STDOUT_FILENO);
	// 			return ;	
	// 		}
	// 	}
	// 	if (mns->ast->right && is_rd(mns->ast->right->token.type))
	// 	{
	// 		if (exec_rd_io(mns, mns->ast->right) == EXIT_FAILURE)
	// 		{
	// 			redirect_fd(tmp[0], STDIN_FILENO);
	// 			redirect_fd(tmp[1], STDOUT_FILENO);
	// 			return ;	
	// 		}
	// 	}
	// }
	
	// if (mns->splitted_cmd && mns->splitted_cmd[0])
	// {
	// 	t_token tmp_token;
	// 	tmp_token.val = mns->splitted_cmd[0];
	// 	if (exec_cmd_check(tmp_token))
	// 	{
	// 		exec_builtin(mns, tmp_token);
	// 	}
	// 	else
	// 	{
	// 		exec_non_builtin(mns, tmp_token);
	// 	}
	// }
	// redirect_fd(tmp[0], STDIN_FILENO);
	// redirect_fd(tmp[1], STDOUT_FILENO);
	int			fd[2];
	const int	tmp[2] = {dup(STDIN_FILENO), dup(STDOUT_FILENO)};

	fd[0] = -2;
	fd[1] = -2;
	if (redirect_io(shell, token.redirect, fd) == EXIT_FAILURE)
	{
		redirect_fd(tmp[0], STDIN_FILENO);
		redirect_fd(tmp[1], STDOUT_FILENO);
		return ;
	}
	//env_underscore(shell, token.split_cmd);
	if (token.cmd && token.split_cmd && token.split_cmd[0])
	{
		if (execute_builtin(shell, token.split_cmd) == EXIT_FAILURE)
			execute_non_builtin(shell, token);
	}
	redirect_fd(tmp[0], STDIN_FILENO);
	redirect_fd(tmp[1], STDOUT_FILENO);
}
