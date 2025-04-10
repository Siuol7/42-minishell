/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:35:59 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/10 11:12:51 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exp_check(t_shell *mns, t_cmd *gr)
{
}

void	exp_generate(t_shell *mns)
{
	int	i;
	int	j;

	i = -1;
	while (++i < mns->group_cnt)
	{
		j = 0;
		while (j < mns->cmd_group[i].token_cnt)
		{
			
		}
}
