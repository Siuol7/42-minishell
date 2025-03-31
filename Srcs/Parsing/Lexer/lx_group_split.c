/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_group_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 23:27:08 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/31 15:46:57 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	lx_groupcnt(char *input)
{
	int	i;
	int	cnt;
	int	size;

	i = 0;
	cnt = 0;
	size = ft_strlen(input);
	while (i < size)
	{
		if (ft_is_dquote(input[i]))
			lx_skip_dquote(input, &i);
		else if (input[i] == '|')
		{
			cnt++;
			i++;
		}
		else
			i++;
	}
	return (cnt + 1);
}

static char	**lx_splitting(char *in, char **res, int i, int lim)
{
	int	start;

	start = 0;
	while (i < lim && in[start])
		lx_split_group(in, res, &start, &i);
	return (res);
}

char	**lx_group_split(t_shell *mns, char *input)
{
	int		groupcnt;
	char	**final;
	char	**res;

	groupcnt = lx_groupcnt(input);
	final = (char **)malloc((groupcnt + 1) * sizeof (char *));
	if (!final)
		return (NULL);
	res = final;
	if (!lx_splitting(input, res, 0, groupcnt))
	{
		free(final);
		return (NULL);
	}
	final[groupcnt] = NULL;
	mns->group_cnt = groupcnt;
	return (final);
}
