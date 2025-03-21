/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 00:05:14 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/20 11:20:13 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// char	**env_dup(char **env)
// {
// 	int		i;
// 	int		size;
// 	char	**final;

// 	i = 0;
// 	size = ft_2d_len(env);
// 	final = (char **)malloc((size + 1) * sizeof(char *));
// 	if (!final)
// 		return (NULL);
// 	while (env[i] && i < size)
// 	{
// 		final[i] = ft_strdup(env[i]);
// 		i++;
// 	}
// 	final[size] = NULL;
// 	return (final);
// }

char	**env_sorting(t_shell *mns)
{
	int		size;
	char	**sorted_env;

	size = ft_2d_len(mns->env);
	sorted_env = (char **)malloc((size + 1) * sizeof(char *));
	if (!sorted_env)
		ft_bad_alloc(mns);
	sorted_env = env_dup(mns->env);
	if (!merge_sort(sorted_env, 0, size - 1))
	{
		ft_bad_alloc(mns);
		ft_free_2d((void **)sorted_env);
	}
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
