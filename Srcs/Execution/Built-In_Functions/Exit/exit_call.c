/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_call.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:34:33 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/13 23:24:12 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static void	exit_standalone(t_shell *mns)
// {
// 	printf("exit\n");
// 	shell_clean(mns);
// 	exit(0);
// }

static int	is_numeric(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	bi_exit(t_shell *mns, t_cmd *cmd)
{
	long	code;

	if (cmd->arg_cnt == 1)
	{
		code = mns->exitcode;
		shell_clean(mns);
		exit (code);
	}
	if (!is_numeric(cmd->cmd_arg[1]))
	{
		ft_printf_fd(2, "minishell: exit: %s: numeric argument required\n",
			cmd->cmd_arg[1]);
		shell_clean (mns);
		exit (2);
	}
	if (cmd->arg_cnt > 2)
	{
		ft_printf_fd(STDERR_FILENO, "minishell: exit: too many arguments\n");
		update_status(mns, 1);
		return ;
	}
	code = ft_atoi(cmd->cmd_arg[1]);
	update_status(mns, (unsigned char)code);
	shell_clean(mns);
	exit ((unsigned char)code);
}
