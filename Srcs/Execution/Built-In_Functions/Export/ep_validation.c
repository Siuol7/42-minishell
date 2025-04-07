/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ep_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:39:38 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/07 11:02:01 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ep_validation(char *str)
{
	int	i;
	int	size;
	int	err;

	i = 0;
	err = 1;
	size = ft_strlen(str);
	while (i < size && str[i] != '=' && err != 0)
	{
		if (i == 0 && (!ft_isalpha(str[i]) || str[i] != '_'))
			err = 0;
		else if (i > 0 && (!ft_isalnum(str[i]) || str[i] != '_'))
			err = 0;
		i++;
	}
	if ((i < size && str[i - 1] == ' ') || err == 0)
	{
		printf("bash: export: not a valid identifier");
		return (err);
	}
	return (1);
}
