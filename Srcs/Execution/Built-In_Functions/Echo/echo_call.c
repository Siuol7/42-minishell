/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_call.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:33:58 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/09 00:09:28 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	bi_echo(t_shell *mns, t_cmd *cmd)
{
	int		i;
	int		j;
	bool	newline;

	(void)mns;
	i = 1;
	newline = true;
	while (cmd->cmd_arg[i])
	{
		j = 1;
		if (cmd->cmd_arg[i][0] == '-'
			&& cmd->cmd_arg[i][1] == 'n')
		{
			while (cmd->cmd_arg[i][j] == 'n')
				j++;
			if (cmd->cmd_arg[i][j] == '\0')
			{
				newline = false;
				i++;
				continue ;
			}
		}
		break ;
	}
	while (cmd->cmd_arg[i])
	{
		ft_printf_fd(1, "%s", cmd->cmd_arg[i]);
		if (cmd->cmd_arg[i + 1])
			ft_printf_fd(1, " ");
		i++;
	}
	if (newline)
		ft_printf_fd(1, "\n");
	return (0);
}
