/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_call.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:34:33 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/14 16:59:52 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exit_standalone(t_shell *mns)
{
	printf("exit\n");
	env_shlvl_down(mns);
	shell_clean(mns);
	exit(0);
}

void	bi_exit(t_shell *mns, t_cmd *cmd)
{
	if (cmd->arg_cnt == 1)
		exit_standalone(mns);
}
