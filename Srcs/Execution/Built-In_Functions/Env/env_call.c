/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_call.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:23:09 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/09 11:12:49 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_append(t_shell *mns, char *str)
{
	if (!ft_append_2d(&mns->env, str))
		ft_bad_alloc(mns);
}

void	bi_env(t_shell *mns, t_cmd *cmd)
{
	int	id;

	id = token.id;
	if (mns->cmd[id].size == 1)
		env_standalone(mns);
}
