/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_cmd_group.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:47:55 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/09 20:38:21 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	lx_out_hd_cnt(t_token *list, t_cmd *group)
{
	int	i;

	i = 0;
	while (i < group->token_cnt)
	{
		if (list[i].type == RD_OUT || list[i].type == RD_APPEND)
			group->out_cnt++;
		else if (list[i].type == RD_HEREDOC)
			group->heredoc_cnt++;
		else if (list[i].type == CMD || list[i].type == ARG)
			group->arg_cnt++;
		i++;
	}
}

static void	lx_group_copy(t_token *list, t_cmd *group, t_sort *id)
{
	while (id->id < group->token_cnt)
	{
		if (list[id->id].type == CMD)
		{
			group->cmd = list[id->id].val;
			group->cmd_arg[id->i++] = list[id->id].val;
		}
		else if (list[id->id].type == ARG)
			group->cmd_arg[id->i++] = list[id->id].val;
		else if (list[id->id].type == RD_IN || list[id->id].type == RD_HEREDOC)
		{
			if (group->in.val)
				free(group->in.val);
			group->in.val = ft_strdup(list[id->id].val);
			group->in.type = list[id->id].type;
			if (list[id->id].type == RD_HEREDOC)
				group->heredoc[id->k++] = ft_strdup(list[id->id].val);
		}
		else if (list[id->id].type == RD_OUT || list[id->id].type == RD_APPEND)
		{
			group->out[id->j].val = list[id->id].val;
			group->out[id->j++].type = list[id->id].type;
		}
		id->id++;
	}
}

static void	lx_cmd_group_gen(t_shell *mns, t_token *list, t_cmd *group)
{
	t_sort	id;

	ft_bzero(&id, sizeof(id));
	lx_out_hd_cnt(list, group);
	group->out = malloc(group->out_cnt * sizeof(t_token));
	if (!group->out)
		ft_bad_alloc(mns);
	group->heredoc = malloc((group->heredoc_cnt + 1) * sizeof(char *));
	if (!group->heredoc)
		ft_bad_alloc(mns);
	group->cmd_arg = malloc((group->arg_cnt + 1) * sizeof(char *));
	if (!group->cmd_arg)
		ft_bad_alloc(mns);
	lx_group_copy(list, group, &id);
	group->heredoc[group->heredoc_cnt] = NULL;
	group->cmd_arg[group->arg_cnt] = NULL;
}

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
