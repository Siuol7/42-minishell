/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_generate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:35:59 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/11 02:17:57 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exp_check(char *str)
{
	int	i;
	int	size;
	int	open;

	i = 0;
	size = ft_strlen(str);
	while (i < size)
	{
		exp_check_open(str[i], &open)
	}
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
			if (exp_check(mns->cmd_group[i].token[j]))
				printf("yes");
			j++;
		}
	}
}
