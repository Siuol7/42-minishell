/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_call.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:00:53 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/07 10:54:29 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ep_variable(t_shell *mns, t_cmd *cmd)
{
	int	i;

	i = 1;
	while (i < cmd->arg_cnt)
	{
		if (!ep_validation(cmd->cmd_arg[i]))
			
	}
}

void	bi_export(t_shell *mns, t_cmd *cmd)
{
	if (cmd->arg_cnt == 1)
		ep_standalone(mns);
	else if (cmd->arg_cnt > 1)
		ep_variable(mns, cmd);
}
