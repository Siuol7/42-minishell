/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_token_gen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:45:13 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/16 03:53:44 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	lx_token_listing(t_shell *mns, char **str)
{
	int	i;

	i = 0;
	while (str[i] && i < mns->token_cnt)
	{
		if (lx_is_oprt(str[i]))
		{
			mns->list[i].type = lx_oprt_type(str[i]);
			mns->list[i].val = str[i];
		}
		else if (lx_is_rd(str[i]))
		{
			mns->list[i].type = lx_rd_type(str[i]);
			mns->list[i].val = str[i];
			i++;
			mns->list[i].type = FD;
			mns->list[i].val = str[i];
		}
		else
		{
			mns->list[i].type = CMD;
			mns->list[i].val = str[i];
		}
		i++;
	}
}

void	shell_token_gen(t_shell *mns, char *input)
{
	mns->splitted_cmd = ft_token_split(mns, input);
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
