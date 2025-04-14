/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_generate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:35:59 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/14 23:40:53 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exp_subjoin(t_shell *mns, t_point p, char *str)
{
	char	*temp;

	temp = ft_substr(str, p.start, p.end - p.start);
	if (!temp)
		ft_bad_alloc(mns);
	if (!ft_append(&mns->post_expansion, &temp))
		ft_bad_alloc(mns);
}

static void	exp_check(t_shell *mns, t_token *str, int size, int i)
{
	t_point		p;
	char		open;
	char		*key;

	ft_bzero(&p, sizeof(t_point));
	open = 'e';
	while (i < size)
	{
		exp_check_open(str->val[i], &open);
		if (i + 1 < size && str->val[i] == '$' && str->val[i + 1] != ' ')
		{
			p.end = i;
			exp_subjoin(mns, p, str->val);
			key = exp_getkey(mns, str->val, &i);
			p.start = i;
			exp_expand(mns, &key, open, str);
		}
		else
			i++;
	}
	p.end = i;
	if (p.start != p.end)
		exp_subjoin(mns, p, str->val);
}

void	exp_generate(t_shell *mns, int i)
{
	int	j;

	while (++i < mns->group_cnt)
	{
		j = -1;
		while (++j < mns->cmd_group[i].token_cnt)
		{
			mns->post_expansion = ft_strdup("");
			if (!mns->post_expansion)
				ft_bad_alloc(mns);
			if (mns->cmd_group[i].list[j].type == SIGN)
				continue ;
			exp_check(mns, &mns->cmd_group[i].list[j],
				ft_strlen(mns->cmd_group[i].list[j].val), 0);
			free(mns->cmd_group[i].list[j].val);
			mns->cmd_group[i].list[j].val = ft_strdup(mns->post_expansion);
			if (!mns->cmd_group[i].list[j].val)
			{
				free(mns->post_expansion);
				ft_bad_alloc(mns);
			}
			free(mns->post_expansion);
			mns->post_expansion = NULL;
		}
	}
}
