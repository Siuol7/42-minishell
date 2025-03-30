/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_shlvl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 14:45:20 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/30 00:15:49 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

check SHLVL exist -> initalize SHLVL -> join SHLVL=*value* -> strdup -> add to env



static void	env_shlvl_check(t_shell *mns)
{
	char	*shlvl;

	shlvl = getenv("SHLVL");
	if (!shlvl)
		mns->shlvl = 2;
	mns->shlvl = ft_atoi(shlvl) + 1;
}

void	env_shlvl(t_shell *mns)
{
	env_shlvl_check(mns);
	env_shlvl_gen(mns);
}