/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_list_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:39:01 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/09 17:54:04 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	prs_list_check(t_shell *mns)
{
	int	i;
	int	j;

	i = 0;
	while (i < mns->group_cnt)
	{
		j = 0;
		while (j < mns->cmd_group[i].token_cnt)
		{
			if (mns->cmd_group[i].list[j].type == SIGN_ERR)
			{
				printf("bash: syntax error near unexpected token '%s'",
					mns->cmd_group[i].list[j].val);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
