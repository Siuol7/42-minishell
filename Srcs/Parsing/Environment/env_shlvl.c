/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_shlvl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 14:45:20 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/01 15:09:29 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
