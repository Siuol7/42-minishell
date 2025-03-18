/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:24:53 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/18 12:07:26 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_cmd(t_shell *mns)
{
	int	i;

	i = 0;
	while (i < mns->cmd_cnt)
	{
		if (mns->cmd[i].cmd)
			free(mns->cmd[i].cmd);
		if (mns->cmd[i].cmd_gr)
			ft_free_2d((void **)mns->cmd[i].cmd_gr);
	}
	free(mns->cmd);
}

static void	free_list(t_shell *mns)
{
	int	i;

	i = 0;
	while (i < mns->token_cnt)
	{
		if (mns->list[i].val)
			free(mns->list[i].val);
		i++;
	}
	free(mns->list);
}

void	shell_clean(t_shell *mns)
{
	if (!mns)
		return ;
	if (mns->full_cmd_line)
	{
		free(mns->full_cmd_line);
		mns->full_cmd_line = NULL;
	}
	if (mns->splitted_cmd)
	{
		ft_free_2d(mns->splitted_cmd);
		mns->splitted_cmd = NULL;
	}
	if (mns->list)
	{
		free_list(mns);
		mns->list = NULL;
	}
	if (mns->cmd)
	{
		free_cmd(mns);
		mns->cmd = NULL;
	}
	free(mns);
}
