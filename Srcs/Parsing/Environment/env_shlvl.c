/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_shlvl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 14:45:20 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/14 03:20:02 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_shlvl_gen(t_shell *mns)
{
	int	pos;

	pos = ep_exist(mns, "SHLVL=");
	if (pos != -1)
		ep_replace(mns, ft_strjoin("SHLVL=", ft_itoa(mns->shlvl)), pos);
	else
		env_append(mns, ft_strjoin("SHLVL=", ft_itoa(mns->shlvl)));
}

void	env_shlvl_check(t_shell *mns)
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
