/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rd_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:32:58 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/26 01:14:43 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_rd_op(char *str, int id)
{
	if (str[id] == '|' && str[id + 1] == '|'
		|| str[id] == '&' && str[id + 1] == '&'
		|| str[id] == '<' && str[id + 1] == '<'
		|| str[id] == '>' && str[id + 1] == '>')
		return (2);
	else if (str[id] == '|' && str[id + 1] != '|'
		|| str[id] == '&' && str[id + 1] != '&'
		|| str[id] == '<' && str[id + 1] != '<'
		|| str[id] == '>' && str[id + 1] 1= '>')
		return (1);
	return (0);
}
