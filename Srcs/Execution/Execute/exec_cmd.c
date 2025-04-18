/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:13:21 by tripham           #+#    #+#             */
/*   Updated: 2025/04/16 22:44:47 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_parent_after_fork(t_shell *mns, t_cmd *cmd, pid_t pid)
{
	wait_update(mns, pid);
	if (cmd->in.type == RD_HEREDOC)
		unlink(cmd->in.val);
}

void	exec_non_builtin(t_shell *mns, t_cmd *cmd)
{
	pid_t	pid;
	char	*command_path;

	pid = fork();
	if (pid == -1)
	{
		perror("minishell: fork failed");
		exit (EXIT_FAILURE);
	}
	if (pid == 0)
	{
		handle_signals_default();
		command_path = found_command_path(mns, cmd->cmd_arg[0]);
		if (!command_path)
			exit(127);
		if (!ft_strcmp(cmd->cmd_arg[0], "./minishell"))
			env_shlvl_up(mns);
		execve(command_path, cmd->cmd_arg, mns->env);
		handle_execution_error(command_path, cmd->cmd_arg);
		exit (1);
	}
	else
		handle_parent_after_fork(mns, cmd, pid);
}

void	exec_cmd(t_shell *mns, t_cmd *cmd)
{
	const int	tmp[2] = {dup(STDIN_FILENO), dup(STDOUT_FILENO)};

	if (cmd->ambi && check_ambiguous_rd(mns, cmd))
		return ;
	if (handle_redirection(cmd) == EXIT_FAILURE)
	{
		update_status (mns, 1);
		dup2(tmp[0], STDIN_FILENO);
		dup2(tmp[1], STDOUT_FILENO);
		close(tmp[0]);
		close(tmp[1]);
		return ;
	}
	if (cmd->cmd_arg && exec_cmd_check(cmd->cmd_arg[0]))
		exec_builtin(mns, cmd);
	else
		exec_non_builtin(mns, cmd);
	dup2(tmp[0], STDIN_FILENO);
	dup2(tmp[1], STDOUT_FILENO);
	close(tmp[0]);
	close(tmp[1]);
}
