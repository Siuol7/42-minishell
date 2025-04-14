/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_call.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:33:58 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/14 22:33:19 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static void	printf_with_escape(char *arg)
// {
// 	int	i;

// 	i = 0;
// 	while (arg[i])
// 	{
// 		if (arg[i] == '\\')
// 		{
// 			i++;
// 			// if (arg[i] == 'n')
// 			// 	ft_printf_fd(1, "\n");
// 			// else if (arg[i] == 't')
// 			// 	ft_printf_fd(1, "\t");
// 			// else if (arg[i] == '\\')
// 			// 	ft_printf_fd(1, "\\");
// 			// else if (arg[i] == 'a')
// 			// 	ft_printf_fd(1, "\a");
// 			// else if (arg[i] == 'b')
// 			// 	ft_printf_fd(1, "\b"); 
// 			// else if (arg[i] == 'f')
// 			// 	ft_printf_fd(1, "\f");
// 			// else if (arg[i] == 'r')
// 			// 	ft_printf_fd(1, "\r");
// 			// else if (arg[i] == 'v')
// 			// 	ft_printf_fd(1, "\v");
// 			if (arg[i] >= 7 && arg[i] <= 13)
// 				ft_printf_fd(1, "%c", arg[i]);
// 		}
// 		else
// 			ft_printf_fd(1, "%c", arg[i]);
// 		if (arg[i])
// 		i++;
// 	}
// }

// static void	printf_echo_arg(t_shell *mns, char *arg, bool escape)
// {
// 	if (arg[0] == '$' && arg[1] == '?' && arg[2] == '\0')
// 		ft_printf_fd(1, "%d", mns->exitcode);
// 	else if (escape)
// 		printf_with_escape(arg);
// 	else
// 		ft_printf_fd(1, "%s", arg);
// }

// static bool	is_echo_flag(char *arg)
// {
// 	int	j;

// 	if (arg[0] != '-' || !arg)
// 		return (false);
// 	j = 1;
// 	while (arg[j])
// 	{
// 		if (arg[j] != 'n' && arg[j] != 'E' && arg[j] != 'e')
// 			return (false);
// 		j++;
// 	}
// 	return (true);
// }

// int	bi_echo(t_shell *mns, t_cmd *cmd)
// {
// 	int		i;
// 	bool	newline;
// 	bool	escape;

// 	(void)mns;
// 	i = 1;
// 	newline = true;
// 	escape = false;
// 	while (cmd->cmd_arg[i] && is_n_flag(cmd->cmd_arg[i]))
// 	{
// 		newline = false;
// 		i++;
// 	}
// 	while (cmd->cmd_arg[i])
// 	{
// 		printf_echo_arg(mns, cmd->cmd_arg[i]);
// 		if (cmd->cmd_arg[i + 1])
// 			ft_printf_fd(1, " ");
// 		i++;
// 	}
// 	if (newline)
// 		ft_printf_fd(1, "\n");
// 	return (0);
// }

static void	printf_echo_arg(t_shell *mns, char *arg)
{
	if (arg[0] == '$' && arg[1] == '?' && arg[2] == '\0')
		ft_printf_fd(1, "%d", mns->exitcode);
	else
		ft_printf_fd(1, "%s", arg);
}

static bool	is_n_flag(char *arg)
{
	int	j;

	if (arg[0] != '-' || arg[1] != 'n')
		return (false);
	j = 2;
	while (arg[j])
	{
		if (arg[j] != 'n')
			return (false);
		j++;
	}
	return (true);
}

int	bi_echo(t_shell *mns, t_cmd *cmd)
{
	int		i;
	bool	newline;

	(void)mns;
	i = 1;
	newline = true;
	while (cmd->cmd_arg[i] && is_n_flag(cmd->cmd_arg[i]))
	{
		newline = false;
		i++;
	}
	while (cmd->cmd_arg[i])
	{
		printf_echo_arg(mns, cmd->cmd_arg[i]);
		if (cmd->cmd_arg[i + 1])
			ft_printf_fd(1, " ");
		i++;
	}
	if (newline)
		ft_printf_fd(1, "\n");
	return (0);
}
