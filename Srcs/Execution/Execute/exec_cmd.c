/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:13:21 by tripham           #+#    #+#             */
/*   Updated: 2025/04/22 01:00:48 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static void	handle_parent_after_fork(t_shell *mns, t_cmd *cmd, pid_t pid)
// {
// 	wait_update(mns, pid);
// 	//clean_heredoc_files(mns, cmd);
// }

void	exec_non_builtin(t_shell *mns, t_cmd *cmd)
{
	pid_t	pid;
	char	*command_path;

	pid = fork();
	if (pid == -1)
	{
		perror("bash: fork failed");
		exit (EXIT_FAILURE);
	}
	if (pid == 0)
	{
		handle_signals_default();
		command_path = found_command_path(mns, cmd->cmd_arg[0]);
		if (!command_path)
			exit(127);
		execve(command_path, cmd->cmd_arg, mns->env);
		handle_execution_error(command_path, cmd->cmd_arg);
		exit (1);
	}
	else
		wait_update(mns, pid);
	clean_heredoc_files(mns, cmd);
}

void	exec_cmd(t_shell *mns, t_cmd *cmd)
{
	const int	tmp[2] = {dup(STDIN_FILENO), dup(STDOUT_FILENO)};
	char		*target;

	if (cmd->ambi && check_ambiguous_rd(mns, cmd))
		return ;
	if (handle_redirection(cmd) == EXIT_FAILURE)
	{
		update_status(mns, 1);
		return ;
	}
	else if (!cmd->cmd_arg || !cmd->cmd_arg[0])
		update_status(mns, 0);
	else if (!ft_strcmp(cmd->cmd_arg[0], "~"))
	{
		target = get_env_val(mns, "HOME");
		ft_printf_fd(2, "bash: %s: Is a directory\n", target);
		update_status(mns, 126);
	}
	else if (exec_cmd_check(cmd->cmd_arg[0]))
		exec_builtin(mns, cmd);
	else
		exec_non_builtin(mns, cmd);
	dup2(tmp[0], STDIN_FILENO);
	dup2(tmp[1], STDOUT_FILENO);
	close(tmp[0]);
	close(tmp[1]);
}
