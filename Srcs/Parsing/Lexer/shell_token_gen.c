/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_token_gen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:45:13 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/01 01:18:51 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static int	lx_qmarks_cnt(char *str)
// {
// 	int		i;
// 	int		cnt;
// 	char	sign;

// 	sign = 'e';
// 	i = 0;
// 	cnt = 0;
// 	while (str[i])
// 	{
// 		if (ft_is_dquote(str[i]) && sign == 'e')
// 			sign = str[i];
// 		else if (str[i] == sign && sign != 'e')
// 			sign = 'e';
// 		else
// 			cnt++;
// 		i++;
// 	}
// 	return (cnt);
// }

static char	*lx_qmarks_eli(t_shell *mns, char *str, int i, int j)
{
	int		size;
	char	sign;
	char	*res;

	sign = 'e';
	size = lx_qmarks_cnt(str);
	res = malloc(size + 1);
	if (!res)
		ft_bad_alloc(mns);
	while (str[i] && j < size)
	{
		if (ft_is_dquote(str[i]) && sign == 'e')
			sign = str[i];
		else if (str[i] == sign && sign != 'e')
			sign = 'e';
		else
		{
			res[j] = str[i];
			j++;
		}
		i++;
	}
	res[size] = '\0';
	return (res);
}

static void	lx_typize_token(t_type *list, char **str)
{
	if (lx_is_oprt(str[i]))
	{
		mns->list[i].type = lx_op;
		mns->list[i].val = lx_qmarks_eli(mns, str[i], 0, 0);
	}
	else if (lx_is_rd(str[i]))
	{
		mns->list[i].type = lx_rd_type(str[i]);
		mns->list[i].val = lx_qmarks_eli(mns, str[i], 0, 0);
		if (i + 1 < mns->token_cnt)
		{
			i++;
			mns->list[i].type = FD;
			if (mns->list[i - 1].type == RD_HEREDOC && i + 1 != mns->token_cnt)
				mns->list[i].type = LIM;
			mns->list[i].val = lx_qmarks_eli(mns, str[i], 0, 0);
		}
	}
	else
	{
		mns->list[i].type = CMD;
		mns->list[i].val = lx_qmarks_eli(mns, str[i], 0, 0);
	}
}

static void	lx_token_listing(t_shell *mns)
{
	int	i;

	i = 0;
	while (i < mns->group_cnt)
	{
		mns->cmd_group[i].list = malloc(mns->cmd_group[i].token_cnt
			* sizeof(t_token));
		if (!mns->cmd_group[i].list)
			ft_bad_alloc(mns);
		i++;
	}
	i = 0;
	while (i < mns->group_cnt)
	{
		lx_typize_token(mns->cmd_group[i].list, mns->cmd_group[i].token);
		i++;
	}
}

void	shell_token_gen(t_shell *mns, char *input)
{
	int	i;

	i = 0;
	mns->cmd_str = lx_group_split(mns, input);
	if (!mns->cmd_str)
		ft_bad_alloc(mns);
	mns->cmd_group = malloc(mns->group_cnt * sizeof(t_cmd));
	if (!mns->cmd_group)
		ft_bad_alloc(mns);
	while (i < mns->group_cnt)
	{
		mns->cmd_group[i].token = lx_token_split(mns, mns->cmd_str[i], i);
		if(!mns->cmd_group[i].token)
			ft_bad_alloc(mns);
		i++;
	}
	// lx_token_listing(mns);
}
