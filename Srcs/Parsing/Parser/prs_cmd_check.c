/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_cmd_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 02:39:14 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/26 11:36:41 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	prs_cmd_check(t_shell *mns)
{
	int	i;

	i = 0;
	while (i < mns->token_cnt)
	{
		if (3 < mns->list[i].type && mns->list[i].type < 8
			&& (i == (mns->token_cnt - 1)))
		{
			ft_printf_fd(2,
				"minishell: syntax error near unexpected token `newline'\n");
			return (0);
		}
		else if ((3 < mns->list[i].type && mns->list[i].type < 8)
			&& mns->list[i + 1].type != CMD)
		{
			ft_printf_fd(2,
				"minishell: syntax error near unexpected token `%s'\n",
				mns->list[i + 1].val);
			return (0);
		}
		i++;
	}
	return (1);
}
