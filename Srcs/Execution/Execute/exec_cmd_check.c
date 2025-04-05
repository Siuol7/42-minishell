/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 01:44:07 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/02 20:44:44 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	exec_builtin(t_shell *mns, t_token token)
// {
// 	if (!ft_strcmp(token.val, "echo"))
// 		bi_echo(mns, token);
// 	else if (!ft_strcmp(token.val, "cd"))
// 		bi_cd(mns, token);
// 	else if (!ft_strcmp(token.val, "pwd"))
// 		bi_pwd(mns, token);
// 	else if (!ft_strcmp(token.val, "export"))
// 		bi_export(mns, token);
// 	else if (!ft_strcmp(token.val, "unset"))
// 		bi_unset(mns, token);
// 	else if (!ft_strcmp(token.val, "env"))
// 		bi_env(mns, token);
// 	else if (!ft_strcmp(token.val, "exit"))
// 		bi_exit(mns, token);
// }

// int	exec_cmd_check(t_token token)
// {
// 	if (!ft_strcmp(token.val, "echo")
// 		|| !ft_strcmp(token.val, "cd")
// 		|| !ft_strcmp(token.val, "pwd")
// 		|| !ft_strcmp(token.val, "export")
// 		|| !ft_strcmp(token.val, "unset")
// 		|| !ft_strcmp(token.val, "env")
// 		|| !ft_strcmp(token.val, "exit"))
// 		return (1);
// 	return (0);
// }

// void	exec_builtin(t_shell *mns, char **cmd_arg)
// {
// 	if (!ft_strcmp(cmd_arg[0], "echo"))
// 		bi_echo(mns, cmd_arg);
// 	else if (!ft_strcmp(cmd_arg[0], "cd"))
// 		bi_cd(mns, cmd_arg);
// 	else if (!ft_strcmp(cmd_arg[0], "pwd"))
// 		bi_pwd(mns, cmd_arg);
// 	else if (!ft_strcmp(cmd_arg[0], "export"))
// 		bi_export(mns, cmd_arg);
// 	else if (!ft_strcmp(cmd_arg[0], "unset"))
// 		bi_unset(mns, cmd_arg);
// 	else if (!ft_strcmp(cmd_arg[0], "env"))
// 		bi_env(mns, cmd_arg);
// 	else if (!ft_strcmp(cmd_arg[0], "exit"))
// 		bi_exit(mns, cmd_arg);
// }

// int	exec_cmd_check(char *cmd_name)
// {
// 	if (!cmd_name)
// 		return (0);
// 	if (!ft_strcmp(cmd_name, "cd")
// 		|| !ft_strcmp(cmd_name, "echo")
// 		|| !ft_strcmp(cmd_name, "pwd")
// 		|| !ft_strcmp(cmd_name, "export")
// 		|| !ft_strcmp(cmd_name, "unset")
// 		|| !ft_strcmp(cmd_name, "env")
// 		|| !ft_strcmp(cmd_name, "exit"))
// 		return (1);
// 	return (0);
// }