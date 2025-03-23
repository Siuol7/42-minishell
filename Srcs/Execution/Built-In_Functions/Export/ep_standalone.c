/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ep_standalone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:22:21 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/23 05:33:51 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ep_standalone(t_shell *mns)
{
	int		size;
	int		i;
	char	**sorted_env;

	i = 0;
	size = ft_2d_len(mns->env);
	sorted_env = env_sorting(mns);
	while (i < size)
	{
		printf("declare -x %s\n", sorted_env[i]);
		i++;
	}
	if (sorted_env)
		ft_free_2d((void **)sorted_env);
}
