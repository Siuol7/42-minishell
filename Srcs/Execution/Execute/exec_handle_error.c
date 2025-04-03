/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_handle_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:46:16 by tripham           #+#    #+#             */
/*   Updated: 2025/04/02 20:17:10 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_execution_error(char *command_path, char **splitted_command)
{
	ft_printf_fd(2, "minishell: %s: %s\n", *splitted_command, strerror(errno));
	if (command_path)
		free(command_path);
	ft_free_2d((void **)splitted_command);
	exit(126);
}

void	handle_command_error(char **command, char *message)
{
	ft_printf_fd(2, "minishell: %s: %s\n", *command, message);
	ft_free_2d((void **)command);
	exit(127);
}

void	handle_open_error(char *file_name, int which_pipe_end)
{
	ft_printf_fd(2, "minishell: %s: %s\n", file_name, strerror(errno));
	close(which_pipe_end);
}

void	handle_fork_error(int *pipe)
{
	close(pipe[0]);
	close(pipe[1]);
	perror("minishell: fork\n");
	exit (1);
}

int	check_error(char *cmd)
{
	if (!cmd)
		return (EXIT_FAILURE);
	if (cmd && !cmd[0])
		ft_printf_fd(STDERR_FILENO, "command '%s' not found\n", cmd);
	else if (!ft_strcmp(cmd, "."))
		ft_printf_fd(STDERR_FILENO, "minishell: .: filename argument requi"
			"red\n.: usage: . filename [arguments]\n");
	else if (!ft_strcmp(cmd, ".."))
		ft_printf_fd(STDERR_FILENO, "%s: command not found\n", cmd);
	else if (access(cmd, F_OK) != 0)
		ft_printf_fd(STDERR_FILENO, "%s: No such file or directory\n", cmd);
	return (EXIT_FAILURE);
}

void	exec_error(t_shell *mns, char *cmd_path, char *ms1, char *ms2)
{
	if (ms1 && ms2)
		ft_printf_fd(STDERR_FILENO, "%s: %s\n", ms1, ms2);
	if (cmd_path)
		free(cmd_path);
	shell_clean(mns);
	exit(update_status(mns, 126));
}