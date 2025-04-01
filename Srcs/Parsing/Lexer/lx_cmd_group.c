/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_cmd_group.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:47:55 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/01 15:47:44 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	lx_out_hd_cnt(t_token *list, t_cmd *group)
{
	int	i;

	i = 0;
	while (i < group->token_cnt)
	{
		if (list[i].type == RD_OUT)
			group->out_cnt++;
		else if (list[i].type == RD_HEREDOC)
			group->heredoc_cnt++;
		else if (list[i].type == CMD || list[i].type == ARG)
			group->arg_cnt++;
		else
			continue ;
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
			group->in.val = list[id->id].val;
			group->in.type = list[id->id].type;
		}
		else if (list[id->id].type == RD_OUT || list[id->id].type == RD_APPEND)
		{
			group->out[id->j].val = list[id->id].val;
			group->out[id->j++].type = list[id->id].type;
		}
		else
			continue ;
		id->id++;
	}
}

static void	lx_cmd_group_gen(t_shell *mns, t_token *list, t_cmd *group)
{
	t_sort	id;

	ft_bzero(&id, sizeof(id));
	lx_out_hd_cnt(list, group);
	group->out = malloc(group->out_cnt * sizeof(t_rd));
	if (!group->out)
		ft_bad_alloc(mns);
	group->heredoc = malloc(group->heredoc_cnt * sizeof(t_rd));
	if (!group->heredoc)
		ft_bad_alloc(mns);
	group->cmd_arg = malloc(group->arg_cnt * sizeof(char *));
	if (!group->cmd_arg)
		ft_bad_alloc(mns);
	lx_group_copy(list, group, &id);
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
	printf("Group cnt %d\n", mns->group_cnt);
	printf("Token cnt %d\n", mns->cmd_group[0].token_cnt);
	printf("ARG cnt %d\n", mns->cmd_group[0].arg_cnt);
	printf("OUT cnt %d\n", mns->cmd_group[0].out_cnt);
	printf("HEREDOC cnt %d\n", mns->cmd_group[0].heredoc_cnt);
	// for (int i = 0; i < mns->group_cnt; i++)
	// {
	// 	printf("Group %d : %s\n", i, mns->cmd_str[i]);
	// 	printf("CMD %s\n", mns->cmd_group[i].cmd);
	// 	for (int j = 0; j < mns->cmd_group[i].token_cnt; j++)
	// 		printf("CMD ARG %d : %s\n", j, mns->cmd_group[i].cmd_arg[j]);
	// 	printf("File in %s type %d\n", mns->cmd_group[i].in.val, mns->cmd_group[i].in.type);
	// 	for (int m = 0; m < mns->cmd_group[i].out_cnt; m++)
	// 		printf("File in %s type %d\n", mns->cmd_group[i].out[m].val, mns->cmd_group[i].out[m].type);
	// 	for (int n = 0; n < mns->cmd_group[i].heredoc_cnt; n++)
	// 		printf("HEREDOC in %s\n", mns->cmd_group[i].heredoc[n]);
	// }
}
