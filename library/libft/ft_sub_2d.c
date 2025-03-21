/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub_2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 01:27:13 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/20 11:20:04 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sub_2d(char **org, char **des, int start, int len)
{
	int	i;

	i = 0;
	if (!org || !des)
		return ;
	while (des[start] && i < len)
	{
		org[i] = ft_strdup(des[start]);
		i++;
		start++;
	}
	org[len] = NULL;
}
