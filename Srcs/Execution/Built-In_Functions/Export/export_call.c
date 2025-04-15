/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_call.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:00:53 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/15 20:33:55 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ep_variable(t_shell *mns, t_cmd *cmd)
{
	int	i;
	int	pos;

	i = 1;
	while (i < cmd->arg_cnt)
	{
		if (!ep_validation(mns, cmd->cmd_arg[i]))
			return ;
		pos = ep_exist(mns, cmd->cmd_arg[i]);
		if (pos > -1)
			ep_replace(mns, cmd->cmd_arg[i], pos);
		else
			env_append(mns, cmd->cmd_arg[i]);
		i++;
	}
}

void	bi_export(t_shell *mns, t_cmd *cmd)
{
	if (cmd->arg_cnt == 1)
		ep_standalone(mns);
	else if (cmd->arg_cnt > 1)
		ep_variable(mns, cmd);
}
