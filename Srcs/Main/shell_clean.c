/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:24:53 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/01 18:42:11 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static void	free_list(t_token *list, int size)
// {
// 	int	i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		if (list[i].val)
// 		{
// 			free(list[i].val);
// 			list[i].val = NULL;
// 		}
// 		i++;
// 	}
// }

// static void	free_cmd_group(t_cmd *group, int id)
// {
// 	if (group[id].list)
// 		free_list(group[id].list, group[id].token_cnt);
// 	if (group[id].cmd)
// 		free(group[id].cmd);
// 	if (group[id].cmd_arg)
// 		ft_free_2d((void **)group[id].cmd_arg);
// 	if (group[id].heredoc)
// 		ft_free_2d((void **)group[id].heredoc);
// 	if (group[id].out)
// 		free_list(group[id].out, group[id].out_cnt);
// 	if (group[id].in.val)
// 		free(group[id].in.val);
// }

// static void	free_group(t_cmd *group, int size)
// {
// 	int	i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		free_cmd_group(group, i);
// 		i++;
// 	}
// 	free(group);
// }

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
	// if (mns->cmd_group)
	// {
	// 	free_group(mns->cmd_group, mns->group_cnt);
	// 	mns->cmd_group = NULL;
	// }
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
	// if (mns->cmd_group)
	// {
	// 	free_group(mns->cmd_group, mns->group_cnt);
	// 	mns->cmd_group = NULL;
	// }
	if (mns->env)
		ft_free_2d((void **)mns->env);
	free(mns);
}
