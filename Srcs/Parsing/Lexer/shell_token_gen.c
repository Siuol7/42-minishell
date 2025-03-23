/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_token_gen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:45:13 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/23 03:18:41 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	lx_qmarks_cnt(char *str)
{
	int		i;
	int		cnt;
	char	sign;

	sign = 'e';
	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (ft_is_dquote(str[i]) && sign == 'e')
			sign = str[i];
		else if (str[i] == sign && sign != 'e')
			sign = 'e';
		else
			cnt++;
		i++;
	}
	return (cnt);
}

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

static void	lx_typize_token(t_shell *mns, char **str, int i, int *cmd)
{
	if (lx_is_oprt(str[i]))
	{
		mns->list[i].id = 0;
		mns->list[i].type = lx_oprt_type(str[i]);
		mns->list[i].val = lx_qmarks_eli(mns, str[i], 0, 0);
	}
	else if (lx_is_rd(str[i]))
	{
		mns->list[i].id = 0;
		mns->list[i].type = lx_rd_type(str[i]);
		mns->list[i].val = lx_qmarks_eli(mns, str[i], 0, 0);
		i++;
		mns->list[i].id = 0;
		mns->list[i].type = FD;
		mns->list[i].val = lx_qmarks_eli(mns, str[i], 0, 0);
	}
	else
	{
		mns->list[i].id = ++cmd;
		mns->list[i].type = CMD;
		mns->list[i].val = lx_qmarks_eli(mns, str[i], 0, 0);
	}
}

static void	lx_token_listing(t_shell *mns, char **str)
{
	int	i;
	int	cmd;

	i = 0;
	cmd = 0;
	while (str[i] && i < mns->token_cnt)
	{
		lx_typize_toke(mns, str, i, &cmd);
		i++;
	}
}

void	shell_token_gen(t_shell *mns, char *input)
{
	mns->splitted_cmd = lx_token_split(mns, input);
	if (!mns->splitted_cmd)
		ft_bad_alloc(mns);
	mns->list = malloc(mns->token_cnt * sizeof(t_token));
	if (!mns->list)
		ft_bad_alloc(mns);
	lx_token_listing(mns, mns->splitted_cmd);
	mns->cmd_cnt = lx_cmd_group_cnt(mns);
	mns->cmd = malloc(mns->cmd_cnt * sizeof(t_cmd));
	if (!mns->cmd)
		ft_bad_alloc(mns);
	lx_cmd_grouping(mns);
}
