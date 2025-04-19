/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_handle_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:46:16 by tripham           #+#    #+#             */
/*   Updated: 2025/04/18 20:36:18 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_execution_error(char *command_path, char **splitted_command)
{
	ft_printf_fd(2, "bash: %s: %s\n", *splitted_command, strerror(errno));
	if (command_path)
		free(command_path);
	exit(126);
}

void	handle_command_error(char **command, char *message)
{
	ft_printf_fd(2, "bash: %s: %s\n", *command, message);
	ft_free_2d((void **)command);
	exit(127);
}

void	handle_open_error(char *file_name, int which_pipe_end)
{
	ft_printf_fd(2, "bash: %s: %s\n", file_name, strerror(errno));
	close(which_pipe_end);
}

void	handle_fork_error(int *pipe)
{
	close(pipe[0]);
	close(pipe[1]);
	perror("bash: fork\n");
	exit (1);
}

// int	check_error(t_shell *mns, char *cmd)
// {
// 	if (!cmd || !cmd[0])
// 	{
// 		ft_printf_fd(STDERR_FILENO, "command '%s' not found\n", cmd);
// 		update_status(mns, 127);
// 		return (EXIT_FAILURE);
// 	}
// 	else if (!ft_strcmp(cmd, "."))
// 	{
// 		ft_printf_fd(STDERR_FILENO,
// 			"bash: .: filename argument required\n"
// 			".: usage: . filename [arguments]\n");
// 		update_status(mns, 2);
// 		return (EXIT_FAILURE);
// 	}
// 	else if (!ft_strcmp(cmd, ".."))
// 	{
// 		ft_printf_fd(STDERR_FILENO, "%s: command not found\n", cmd);
// 		update_status(mns, 127);
// 		return (EXIT_FAILURE);
// 	}
// 	else if (access(cmd, F_OK) != 0)
// 	{
// 		ft_printf_fd(STDERR_FILENO, "%s: No such file or directory\n", cmd);
// 		update_status(mns, 127);
// 		return (EXIT_FAILURE);
// 	}
// 	else if (access(cmd, X_OK) != 0)
// 	{
// 		ft_printf_fd(STDERR_FILENO, "%s: Permission denied\n", cmd);
// 		update_status(mns, 126);
// 		return (EXIT_FAILURE);
// 	}
// 	return (EXIT_SUCCESS);
// }
