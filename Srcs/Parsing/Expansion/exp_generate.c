/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_generate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:35:59 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/11 20:48:08 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exp_check(t_shell *mns, char *str, int size)
{
	int		i;
	char	open;
	char	*key;
	char	*res;

	i = 0;
	res = "";
	open = 'e';
	while (i < size)
	{
		exp_check_open(str[i], &open);
		if (str[i] == '$')
		{
			key = ep_getkey(mns, str, &i);
			//if (ep_validation(key))
			printf("KEY%s-%ld\n", key, ft_strlen(key));
			free(key);
		}
		else
			i++;
	}
	(void)res;
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
			exp_check(mns, mns->cmd_group[i].token[j],
				ft_strlen(mns->cmd_group[i].token[j]));
			j++;
		}
	}
}
