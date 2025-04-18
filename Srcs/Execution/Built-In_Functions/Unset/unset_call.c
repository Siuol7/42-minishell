/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_call.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:36:23 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/18 20:28:44 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset_env_var(char *key, char ***env)
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

int	bi_unset(t_shell *mns, t_cmd *cmd)
{
	int		i;
	int		error;

	i = 1;
	error = 0;
	while (cmd->cmd_arg[i])
	{
			unset_env_var(cmd->cmd_arg[i], &mns->env);
		i++;
	}
	return (update_status(mns, error));
}
