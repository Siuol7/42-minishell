/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:24:53 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/18 11:43:32 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_list(t_shell *mns)
{
	int	i;

	i = 0;
	while (i < mns->token_cnt)
	{
		free(mns->list[i].val);
		i++;
	}
}

void	shell_clean(t_shell *mns)
{
	if (!mns)
		return ;
	if (mns->full_cmd_line)
		free(mns->full_cmd_line);
	if (mns->splitted_cmd)
		ft_free_2d(mns->splitted_cmd);
	if (mns->list)
		free_list(mns);
	free(mns);
}
