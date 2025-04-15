/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ep_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:39:38 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/15 20:33:46 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ep_exist(t_shell *mns, char *str)
{
	int	i;
	int	size;
	int	len;

	i = 0;
	size = ft_2d_len(mns->env);
	len = ft_strichr(str, '=');
	while (i < size)
	{
		if (!ft_strncmp(mns->env[i], str, len))
			return (i);
		i++;
	}
	return (-1);
}

int	ep_validation(t_shell *mns, char *str)
{
	int	i;
	int	size;
	int	err;

	i = 0;
	err = 1;
	size = ft_strlen(str);
	while (i < size && str[i] != '=' && err != 0)
	{
		if (i == 0 && !ft_isalpha(str[i]) && str[i] != '_')
			err = 0;
		else if (i > 0 && !ft_isalnum(str[i]) && str[i] != '_')
			err = 0;
		i++;
	}
	if ((i < size && str[i - 1] == ' ') || err == 0
		|| (i == 0 && str[i] == '='))
	{
		printf("bash: export: '%s': not a valid identifier\n", str);
		update_status(mns, 1);
		return (err);
	}
	return (1);
}
