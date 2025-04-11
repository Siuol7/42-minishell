/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_generate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:35:59 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/11 19:48:21 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exp_check(t_shell *mns, char *str, int size)
{
	int		i;
	char	open;
	char	*name;
	char	*res;

	i = 0;
	res = "";
	while (i < size)
	{
		exp_check_open(str[i], &open);
		if (str[i] == '$' && exp_validation(str, open, i + 1))

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
