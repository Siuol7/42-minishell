/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 00:05:14 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/19 01:02:45 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**env_dup(char **env)
{
	int		i;
	int		size;
	char	**final;

	i = 0;
	size = ft_2d_len(env);
	final = (char **)malloc((size + 1) * sizeof(char *));
	if (!final)
		return (NULL);
	while (i < size && env[i])
	{
		final[i] = ft_strdup(env[i]);
		i++;
	}
	final[size] = NULL;
	return (final);
}

void	shell_env_gen(t_shell *mns, char **env)
{
	mns->env = env_dup(env);
	if (!mns->env)
		ft_bad_alloc(mns);
}
