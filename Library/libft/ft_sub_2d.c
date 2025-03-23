/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub_2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 01:27:13 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/23 03:42:10 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sub_2d(char **org, char **des, int start, int len)
{
	int	i;

	i = 0;
	if (!org || !des)
		return ;
	while (org[start] && i < len)
	{
		des[i] = ft_strdup(org[start]);
		i++;
		start++;
	}
	des[len] = NULL;
}
