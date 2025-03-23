/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_cmd_group_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:47:55 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/23 04:38:32 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lx_cmd_group_cnt(t_shell *mns)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < mns->token_cnt)
	{
		if (mns->list[i].type == CMD)
		{
			cnt++;
			while (i < mns->token_cnt
				&& mns->list[i].type == CMD)
				i++;
		}
		else
			i++;
	}
	return (cnt);
}

int	lx_cmd_cnt(t_shell *mns, int j)
{
	int	cnt;

	cnt = 0;
	while (j < mns->token_cnt
		&& mns->list[j].type == CMD)
	{
		cnt++;
		j++;
	}
	return (cnt);
}

static void	lx_group(t_shell *mns, int *j, int i)
{
	int		k;
	int		size;

	k = 0;
	size = lx_cmd_cnt(mns, *j);
	mns->cmd[i].cmd_gr = malloc((size + 1) * sizeof(t_cmd));
	if (!mns->cmd[i].cmd_gr)
		(ft_bad_alloc(mns));
	while (k < size && *j < mns->token_cnt)
	{
		mns->cmd[i].cmd_gr[k] = mns->list[*j].val;
		k++;
		(*j)++;
	}
	mns->cmd[i].cmd_gr[k] = NULL;
	mns->cmd[i].size = size;
}

void	lx_cmd_grouping(t_shell *mns)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < mns->cmd_cnt && j < mns->token_cnt)
	{
		if (mns->list[j].type == CMD)
		{
			mns->cmd[i].cmd = mns->list[j].val;
			lx_group(mns, &j, i);
			i++;
		}
		else
			j++;
	}
}
