/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ep_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:39:38 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/18 21:30:29 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ep_option(t_shell *mns, char *str, int err, int size)
{
	if (size < 2)
		ft_printf_fd(2, "bash: export: '%s': not a valid identifier\n", str);
	else
	{
		ft_printf_fd(2, "bash: export: '%c%c': not a valid identifier\n",
			str[0], str[1]);
		ft_printf_fd(2,
			"export: usage: export [-fn] [name[=value] ...] or export -p\n");
	}
	update_status(mns, 2);
	return (err);
}

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
		if (len > -1 && !ft_strncmp(mns->env[i], str, len))
			return (i);
		i++;
	}
	return (-1);
}

int	ep_validation(t_shell *mns, char *str, int i, int size)
{
	int	err;

	err = 1;
	while (i < size && str[i] != '=' && err != 0)
	{
		if (str[0] == '-')
			return (ep_option(mns, str, err, size));
		if (i == 0 && !ft_isalpha(str[i]) && str[i] != '_')
			err = 0;
		else if (i > 0 && !ft_isalnum(str[i]) && str[i] != '_')
			err = 0;
		i++;
	}
	if (i < size && str[i - 1] == '+')
	if ((i < size && str[i - 1] == ' ') || err == 0
		|| (i == 0 && str[i] == '='))
	{
		ft_printf_fd(2, "bash: export: '%s': not a valid identifier\n", str);
		update_status(mns, 1);
		return (err);
	}
	return (1);
}
