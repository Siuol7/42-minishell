/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:06:39 by tripham           #+#    #+#             */
/*   Updated: 2025/04/02 20:41:15 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redirect_fd(int from_fd, int to_fd)
{
	if (dup2(from_fd, to_fd) == -1)
	{
		perror("dup2 failed");
		close(from_fd);
		exit(EXIT_FAILURE);
	}
	close(from_fd);
}

void	free_all(t_ast **ast, t_shell **mns)
{
	if (ast && *ast)
	{
		//ast_free_node(*ast);
		*ast = NULL;
	}
	if (mns && *mns)
	{
		shell_clean(*mns);
		*mns = NULL;
	}
}

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
			printf("\n");
		update_status(mns, 128 + WTERMSIG(status));
	}
	signals_initialize();
}
