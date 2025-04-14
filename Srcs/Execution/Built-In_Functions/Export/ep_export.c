/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ep_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:22:21 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/14 02:54:03 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ep_replace(t_shell *mns, char *str, int i)
{
	if (mns->env[i])
		free(mns->env[i]);
	mns->env[i] = ft_strdup(str);
	if (!mns->env[i])
		ft_bad_alloc(mns);
}

void	ep_standalone(t_shell *mns)
{
	int		size;
	int		i;
	char	**sorted_env;

	i = 0;
	size = ft_2d_len(mns->env);
	sorted_env = env_sorting(mns);
	if (!sorted_env)
		ft_bad_alloc(mns);
	while (i < size)
	{
		printf("declare -x %s\n", sorted_env[i]);
		i++;
	}
	ft_free_2d((void **)sorted_env);
}
