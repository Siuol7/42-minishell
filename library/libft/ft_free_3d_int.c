/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_3d_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:32:04 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/12 13:35:10 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_3d_int(int ***arr, int size)
{
	if (!*arr)
		return ;
	ft_free_2d_int(*arr, size);
	*arr = NULL;
}
