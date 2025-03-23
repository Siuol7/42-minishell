/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub_2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 01:27:13 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/23 06:02:03 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sub_2d(char **org, char **des, int start, int len)
{
	int	i;

	i = 0;
	if (!org || !des)
		return (0);
	while (i < len && org[start + i])
	{
		des[i] = ft_strdup(org[start + i]);
		if (!des[i])
		{
			ft_free_process_2d(des, i);
			return (0);
		}
		i++;
		start++;
	}
	while (i < len)
		des[i++] = NULL;
	des[i] = NULL;
	return (1);
}
