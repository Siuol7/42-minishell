/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_token_gen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:45:13 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/10 10:48:25 by caonguye         ###   ########.fr       */
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

// static char	*lx_qmarks_eli(t_shell *mns, char *str, int i, int j)
// {
// 	int		size;
// 	char	sign;
// 	char	*res;

// 	sign = 'e';
// 	size = lx_qmarks_cnt(str);
// 	res = malloc(size + 1);
// 	if (!res)
// 		ft_bad_alloc(mns);
// 	while (str[i] && j < size)
// 	{
// 		if (ft_is_dquote(str[i]) && sign == 'e')
// 			sign = str[i];
// 		else if (str[i] == sign && sign != 'e')
// 			sign = 'e';
// 		else
// 		{
// 			res[j] = str[i];
// 			j++;
// 		}
// 		i++;
// 	}
// 	res[size] = '\0';
// 	return (res);
// }
void	lx_cmd_group(t_shell *mns)
{
	int	i;

	i = 0;
	while (i < mns->group_cnt)
	{
		lx_cmd_group_gen(mns, mns->cmd_group[i].list, &mns->cmd_group[i]);
		i++;
	}
}

static void	lx_typize_token(t_shell *mns, t_token *list, char **str, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (lx_is_rd(str[i]))
			lx_rd_typize(list, str, &i, size);
		else if (i == 0)
		{
			list[i].type = CMD;
			list[i].val = ft_strdup(str[i]);
		}
		else
		{
			list[i].type = ARG;
			list[i].val = ft_strdup(str[i]);
		}
	}
	(void)mns;
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
		lx_typize_token(mns, mns->cmd_group[i].list, mns->cmd_group[i].token,
			mns->cmd_group[i].token_cnt);
		i++;
	}
	prs_list_check(mns);
}

void	shell_token_gen(t_shell *mns, char *input, int i)
{
	mns->cmd_str = lx_group_split(mns, input);
	if (!mns->cmd_str)
	{
		if (mns->shell_err == -2)
			return ;
		ft_bad_alloc(mns);
	}
	mns->cmd_group = malloc(mns->group_cnt * sizeof(t_cmd));
	if (!mns->cmd_group)
		ft_bad_alloc(mns);
	while (++i < mns->group_cnt)
		ft_bzero(&mns->cmd_group[i], sizeof(t_cmd));
	i = -1;
	while (++i < mns->group_cnt)
	{
		mns->cmd_group[i].token = lx_token_split(mns, mns->cmd_str[i], i);
		if (!mns->cmd_group[i].token)
			ft_bad_alloc(mns);
	}
	lx_token_listing(mns);
	if (mns->shell_err == -3)
		return ;
	lx_cmd_group(mns);
}
