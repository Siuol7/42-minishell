/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rd_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:32:58 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/09 03:24:10 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_rd_op(char *str, int id)
{
	int	size;

	size = ft_strlen(str);
	if (!str[id])
		return (0);
	if (id < size && (str[id] == '|' || str[id] == '&'
			|| str[id] == '<' || str[id] == '>'))
	{
		if (id + 1 < size && (((str[id + 1] && str[id + 1] == str[id])
			|| (str[id + 1] && str[id] == '<' && str[id + 1] == '>'))))
			return (2);
		else if (id + 2 < size && str[id + 2] == str[id]
			&& str[id + 1] == str[id] && str[id] == '<')
			return (3);
		else if (id + 2 < size && str[id + 2] == str[id]
			&& str[id + 1] == str[id] && str[id] == '>')
			return (0);
		return (1);
	}
	return (0);
}
