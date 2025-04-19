/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_call.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:00:53 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/19 14:36:00 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ep_add(t_shell *mns, char *str, int pos)
{
	char	*temp;

	temp = ft_strdup(str + 2);
	printf("HERE pos %d str %s\n", pos, mns->env[pos]);
	if (!str || !str[0])
	{
		free(temp);
		return ;
	}
	if (!ft_append(&mns->env[pos], &temp))
		ft_bad_alloc(mns);
}

static void	ep_variable(t_shell *mns, t_cmd *cmd)
{
	int		i;
	int		pos;
	char	**temp;

	i = 1;
	while (i < cmd->arg_cnt)
	{
		temp = ep_split(mns, cmd->cmd_arg[i]);
		if (!temp)
			ft_bad_alloc(mns);
		if (!ep_validation(mns, temp[0], 0, ft_strlen(temp[0])))
			return ;
		pos = ep_check_exist(mns, temp[0], &temp);
		if (temp[1][0] == '+' && pos > -1)
			ep_add(mns, temp[1], pos);
		else if (pos > -1)
			ep_replace(mns, cmd->cmd_arg[i], pos);
		else
			env_append(mns, cmd->cmd_arg[i]);
		i++;
		ft_free_2d((void **)temp);
	}
}

void	bi_export(t_shell *mns, t_cmd *cmd)
{
	if (cmd->arg_cnt == 1)
		ep_standalone(mns);
	else if (cmd->arg_cnt > 1)
		ep_variable(mns, cmd);
}
