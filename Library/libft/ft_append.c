/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:13:21 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/20 00:14:13 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_append(char **s1, char **s2)
{
	*s1 = ft_strjoin_free(*s1, *s2);
	free(*s2);
	if (!(*s1))
		return (0);
	return (1);
}
