/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:13:21 by tripham           #+#    #+#             */
/*   Updated: 2025/03/25 18:04:34 by tripham          ###   ########.fr       */
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
		command_path = found_command_path(mns->splitted_cmd, mns->env);
		if (!command_path)
		{
			free_all(&mns->ast, &mns);
			exit(127);
		}
		execve(command_path, mns->splitted_cmd, mns->env);
		handle_execution_error(command_path, mns->splitted_cmd);
	}
	wait_update(mns, pid);
}

void	exec_cmd(t_shell *mns, t_token token)
{
	if (exec_cmd_check(token))
		exec_builtin(mns, token);
	else
	{
		exec_non_builtin(mns, token);
	}
}
