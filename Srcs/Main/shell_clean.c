/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:24:53 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/31 01:26:29 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_pre_input(t_shell *mns)
{
	if (!mns)
		return ;
	if (mns->full_cmd_line)
	{
		free(mns->full_cmd_line);
		mns->full_cmd_line = NULL;
	}
	if (mns->cmd_str)
	{
		ft_free_2d((void **)mns->cmd_str);
		mns->cmd_str = NULL;
	}
	if (mns->cmd_group)
	{
		mns->cmd_group = NULL;
	}
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
	if (mns->cmd_str)
	{
		ft_free_2d((void **)mns->cmd_str);
		mns->cmd_str = NULL;
	}
	if (mns->cmd_group)
	{
		mns->cmd_group = NULL;
	}
	if (mns->env)
		ft_free_2d((void **)mns->env);
	free(mns);
}
