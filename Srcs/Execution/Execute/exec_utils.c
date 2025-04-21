/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:06:39 by tripham           #+#    #+#             */
/*   Updated: 2025/04/21 17:40:50 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	update_status(t_shell *mns, int new_status)
{
	if (new_status >= 0)
		mns->exitcode = new_status;
	return (mns->exitcode);
}

void	wait_update(t_shell *mns, pid_t pid)
{
	int	status;

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		update_status(mns, WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGINT)
			ft_printf_fd(2, "\n");
		update_status(mns, 128 + WTERMSIG(status));
	}
	signals_initialize();
}

void	exec_error(t_shell *mns, char *cmd_path, char *ms1, char *ms2)
{
	if (ms1 && ms2)
		ft_printf_fd(STDERR_FILENO, "%s: %s\n", ms1, ms2);
	if (cmd_path)
		free(cmd_path);
	shell_clean(mns);
	exit(126);
}

int	check_ambiguous_rd(t_shell *mns, t_cmd *cmd)
{
	if (cmd->ambi)
	{
		ft_printf_fd(2, "bash: %s: ambiguous redirect\n", cmd->ambi);
		update_status(mns, 1);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	print_fault(t_shell *mns)
{
	if (mns->exitcode - 128 == SIGQUIT)
		ft_printf_fd(2, "Quit (core dumped)\n");
	else if (mns->exitcode - 128 == SIGSEGV)
		ft_printf_fd(2, "Segmentation fault (core dumped)\n");
}