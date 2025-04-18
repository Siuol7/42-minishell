/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_final.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 00:23:02 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/18 14:33:50 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	prs_init(t_type *a, t_type *b)
{
	*a = *b;
}

static int	prs_val_count(char *input)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (input[i])
	{
		if (ft_isallspace(input[i]))
			i = lx_skip_space(input, i);
		else
		{
			cnt++;
			i = lx_skip_word(input, i);
		}
	}
	return (cnt);
}

static void	prs_final_count(t_cmd *group, t_token *list)
{
	int	i;

	i = 0;
	while (i < group->token_cnt)
	{
		if (list[i].type != SIGN)
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
	if (!res)
		ft_bad_alloc(mns);
	while (i < ft_2d_len(res))
	{
		if (lst->val && lst->val[0])
		{
			gr->final[*k].val = ft_strdup(res[i]);
			if (!gr->final[*k].val)
				ft_bad_alloc(mns);
			gr->final[*k].type = lst->type;
			i++;
			(*k)++;
		}
	}
}

void	prs_final(t_shell *mns)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = 0;
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
			if (mns->cmd_group[i].list[j].type != SIGN)
				prs_final_split(mns, &mns->cmd_group[i],
					&mns->cmd_group[i].list[j], &k);
			else
				prs_init(&mns->cmd_group[i].final[k].type,
					&mns->cmd_group[i].list[j].type);
		}
	}
}
