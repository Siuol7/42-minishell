/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 01:44:07 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/23 02:51:07 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/Main/minishell.h"

void	exec_builtin(t_shell *mns, t_token token)
{
	if (!ft_strcmp(token.val, "echo"))
		exec_echo(mns, token);
	else if (!ft_strcmp(token.val, "cd"))
		exec_cd(mns, token);
	else if (!ft_strcmp(token.val, "pwd"))
		exec_pwd(mns, token);
	else if (!ft_strcmp(token.val, "export"))
		exec_export(mns, token);
	else if (!ft_strcmp(token.val, "unset"))
		exec_unset(mns, token);
	else if (!ft_strcmp(token.val, "env"))
		exec_env(mns, token);
	else if (!ft_strcmp(token.val, "exit"))
		exec_exit(mns, token);
}

int	exec_cmd_check(t_token token)
{
	if (!ft_strcmp(token.val, "echo")
		|| !ft_strcmp(token.val, "cd")
		|| !ft_strcmp(token.val, "pwd")
		|| !ft_strcmp(token.val, "export")
		|| !ft_strcmp(token.val, "unset")
		|| !ft_strcmp(token.val, "env")
		|| !ft_strcmp(token.val, "exit"))
		return (1);
	return (0);
}
