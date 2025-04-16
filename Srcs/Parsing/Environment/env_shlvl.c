/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_shlvl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 14:45:20 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/16 20:27:04 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_shlvl_gen(t_shell *mns)
{
	int	pos;
	char *shlvl;

	shlvl = ft_itoa(mns->shlvl);
	pos = ep_exist(mns, "SHLVL=");
	if (pos != -1)
		ep_replace(mns, ft_strjoin("SHLVL=", shlvl), pos);
	else
		env_append(mns, ft_strjoin("SHLVL=", shlvl));
	free(shlvl);
}

void	env_shlvl_up(t_shell *mns)
{
	char	*shlvl;

	shlvl = get_env_val(mns, "SHLVL");
	if (shlvl == NULL)
	{
		mns->shlvl = 1;
		env_shlvl_gen(mns);
	}
	else
	{
		mns->shlvl = ft_atoi(shlvl) + 1;
		env_shlvl_gen(mns);
	}
}

void	env_shlvl_down(t_shell *mns)
{
	char	*shlvl;

	shlvl = get_env_val(mns, "SHLVL");
	if (!ft_strcmp(shlvl, "1"))
	{
		mns->shlvl = 0;
		unset_env_var("SHLVL", &mns->env);
	}
	else
	{
		mns->shlvl = ft_atoi(shlvl) - 1;
		env_shlvl_gen(mns);
	}
}
