/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_standalone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 04:12:53 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/09 19:44:11 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_standalone(t_shell *mns)
{
	int	i;
	int	size;

	i = 0;
	size = ft_2d_len(mns->env);
	while (i < size)
	{
		printf("%s\n", mns->env[i]);
		i++;
	}
}
