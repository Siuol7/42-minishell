/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_shlvl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 14:45:20 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/31 15:59:27 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

check shlvl exist -> initalize shlvl -> join shlvl=*value* -> strdup -> add to env



static void	env_shlvl_check(t_shell *mns)
{
	char	*shlvl;

	shlvl = getenv("shlvl");
	if (!shlvl)
		mns->shlvl = 2;
	mns->shlvl = ft_atoi(shlvl) + 1;
}

void	env_shlvl(t_shell *mns)
{
	env_shlvl_check(mns);
	env_shlvl_gen(mns);
}