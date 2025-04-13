/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_shlvl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 14:45:20 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/14 01:57:21 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	env_shlvl_gen(t_shell *mns)
{
	int	pos;

	pos = ep_exist(mns, "SHLVL");
	ep_replace(mns, ft_itoa(mns->shlvl), pos);
}

static void	env_shlvl_check(t_shell *mns)
{
	char	*shlvl;

	shlvl = get_env_val(mns, "SHLVL");
	if (!shlvl)
		mns->shlvl = 2;
	mns->shlvl = ft_atoi(shlvl) + 1;
}

void	env_shlvl(t_shell *mns)
{
	env_shlvl_check(mns);
	env_shlvl_gen(mns);
}
