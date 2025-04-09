/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 00:05:14 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/09 11:11:27 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_append(t_shell *mns, char *str)
{
	if (!ft_append_2d(&mns->env, str))
		ft_bad_alloc(mns);
}

char	**env_sorting(t_shell *mns)
{
	int		size;
	char	**sorted_env;

	size = ft_2d_len(mns->env);
	sorted_env = (char **)malloc((size + 1) * sizeof(char *));
	if (!sorted_env)
		ft_bad_alloc(mns);
	ft_sub_2d(mns->env, sorted_env, 0, size);
	sorted_env[size] = NULL;
	if (!merge_sort(sorted_env, 0, size - 1))
	{
		ft_free_2d((void **)sorted_env);
		ft_bad_alloc(mns);
	}
	return (sorted_env);
}

void	shell_env_gen(t_shell *mns, char **env)
{
	int	size;

	size = ft_2d_len(env);
	mns->env = (char **)malloc((size + 1) * sizeof(char *));
	if (!mns->env)
		ft_bad_alloc(mns);
	ft_sub_2d(env, mns->env, 0, size);
}
