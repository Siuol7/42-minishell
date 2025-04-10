/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_call.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:36:23 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/10 20:18:46 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_identifier(char *key)
{
	int	i;

	if (!key || !(ft_isalpha(key[0]) || key[0] == '_'))
		return (0);
	i = 1;
	while (key[i])
	{
		if (!(ft_isalnum(key[i]) || key[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}

static void	unset_env_var(char *key, char ***env)
{
	int		j;
	size_t	keylen;

	j = 0;
	while ((*env)[j])
	{
		keylen = ft_strchr((*env)[j], '=') - (*env)[j];
		if (ft_strncmp((*env)[j], key, keylen) == 0
			&& (*env)[j][keylen] == '=')
		{
			free((*env)[j]);
			while ((*env)[j])
			{
				(*env)[j] = (*env)[j + 1];
				j++;
			}
			(*env)[j] = NULL;
			break ;
		}
		j++;
	}
}

int	bi_unset(char **cmd_group, char ***env)
{
	int		i;

	i = 1;
	while (cmd_group[i])
	{
		if (!is_valid_identifier(cmd_group[i]))
		{
			ft_printf_fd(2, "unset: `%s': not a valid identifier\n",
				cmd_group[i]);
			i++;
			continue ;
		}
		else
			unset_env_var(cmd_group[i], env);
		i++;
	}
	return (0);
}
