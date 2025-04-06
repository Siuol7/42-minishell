/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ep_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:39:38 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/06 15:40:21 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ep_validation(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(str);
	while (i < size && str[i] != '=')
	{
		if (i == 0 && (!ft_isalpha(str[i]) || str[i] != '_'))
			return (0);
		else if (i > 0 && (!ft_isalnum(str[i]) || str[i] != '_'))
			return (0);
		i++;
	}
	if (i < size && str[i + 1] == ' ')
		return (0);
	return (1);
}
