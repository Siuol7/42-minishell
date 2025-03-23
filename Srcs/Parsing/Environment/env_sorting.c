/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:53:29 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/23 01:57:37 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	fill_right(char **env, char **left
		, char **right, t_sort *id)
{
	while (id->j < id-> rs)
	{
		env[id->k] = right[id->j];
		id->k++;
		id->j++;
	}
}

static void	fill_left(char **env, char **left
		, char **right, t_sort *id)
{
	while (id->i < id->ls)
	{
		env[id->k] = left[id->i];
		id->i++;
		id->k++;
	}
}

static void	merge(char **env, char **left,
	char **right, t_sort *id)
{
	while (id->i < id->ls && id->j < id->rs)
	{
		if (ft_strcmp(left[id->i], right[id->j]) <= 0)
		{
			env[id->k] = left[id->i];
			id->i++;
			id->k++;
		}
		else
		{
			env[id->k] = right[id->j];
			id->j++;
			id->k++;
		}
	}
	fill_left(env, left, right, id);
	fill_right(env, left, right, id);
}

static int	merge_set_up(char **env, int l, int mid, int r)
{
	t_sort	id;
	char	**left;
	char	**right;

	ft_bzero(&id, sizeof(id));
	left = (char **)malloc((mid - l + 2) * sizeof(char *));
	if (!left)
		return (0);
	right = (char **)malloc((r - mid + 1) * sizeof(char *));
	if (!right)
	{
		ft_free_2d(left);
		return (0);
	}
	ft_sub_2d(env, left, l, mid - l + 1);
	ft_sub_2d(env, right, r, r - mid);
	id.ls = mid - l + 1;
	id.rs = r - mid;
	merge(env, left, right, &id);
	ft_free_2d((void **)left);
	ft_free_2d((void **)right);
	left = NULL;
	right = NULL;
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
