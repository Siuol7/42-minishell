/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_call.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:33:58 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/18 19:31:14 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*expand_titled(t_shell *mns, char *arg)
{
	char	*home;
	char	*expanded;

	if (!arg || arg[0] != '~')
		return (arg);
	if (arg[1] == '\0' || arg[1] == '/')
	{
		home = get_env_val(mns, "HOME");
		if (!home)
			return (arg);
		expanded = ft_strjoin(home, arg + 1);
		if (!expanded)
			return (arg);
		return (expanded);
	}
	return (arg);
}

static void	printf_echo_arg(t_shell *mns, char *arg)
{
	char	*expanded;

	expanded = expand_titled(mns, arg);
	ft_printf_fd(1, "%s", expanded);
	if (expanded != arg)
		free(expanded);
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
