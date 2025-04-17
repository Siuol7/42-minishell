/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_final.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 00:23:02 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/17 09:11:45 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	prs_final_count(t_cmd *group, t_token *list)
{
	int	i;

	i = 0;
	while (i < group->token_cnt)
	{
		group->final_cnt += prs_val_count(list[i].val);
		i++;
	}
}

static void	prs_final_split(t_shell *mns, t_cmd *gr, t_token *lst, int *k)
{
	int		i;
	char	**res;

	i = 0;
	res = prs_split_allspace(lst->val);
	while (i < ft_2d_len(res))
	{
		gr->final[*k].val = ft_strdup(res[i]);
		gr->final[*k].type = lst->type;
		i++;
		k++;
	}
}

void	prs_final(t_shell *mns)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < mns->group_cnt)
	{
		prs_final_count(&mns->cmd_group[i], mns->cmd_group[i].list);
		mns->cmd_group[i].final = malloc(mns->cmd_group[i].final_cnt
				* sizeof(t_token));
		if (!mns->cmd_group[i].final)
			ft_bad_alloc(mns);
		ft_bzero(mns->cmd_group[i].final, sizeof(t_token));
		j = -1;
		while (++j < mns->cmd_group[i].token_cnt)
		{
			prs_final_split(mns, &mns->cmd_group[i],
				&mns->cmd_group[i].list[j], &k);
		}
	}
}
