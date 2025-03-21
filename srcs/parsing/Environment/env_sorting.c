/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:53:29 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/21 03:22:24 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void merge(char ** env, char **L, char **R, t_sort *id)
{
	while (id->i < id->ls && id->j < id->rs)
	{
		
	}
}

static int	merge_set_up(char **env, int l, int mid, int r)
{
	t_sort	id;
	char	**L;
	char	**R;

	ft_bzero(&id, sizeof(id));
	L = (char **)malloc((mid - l + 2) * sizeof(char *));
	if (!L)
		return (0);
	R = (char **)malloc((r - mid + 1) * sizeof(char *));
	if (!R)
	{
		ft_free_2d(L);
		return (0);
	}
	ft_sub_2d(env, L, l, mid - l + 1);
	ft_sub_2d(env, R, r, r - mid);
	id.ls = mid - l + 1;
	id.rs = r - mid;
	merge(env, L, R, &id);
	return (1);
}

int	merge_sort(char **env, int left, int right)
{
	int	mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		if (!merge_sort(env, left, mid))
			return (0);
		if (!merge_sort(env, mid + 1, right))
			return (0);
		if (!merge_set_up(env, left, mid, right))
			return (0);
	}
	return (1);
}
