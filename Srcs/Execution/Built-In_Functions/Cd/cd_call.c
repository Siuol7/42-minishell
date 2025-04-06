/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_call.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:33:28 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/07 02:08:44 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	bi_cd(t_shell *mns, t_cmd *cmd)
{
	char	*oldpwd;
	char	*target;
	char	cwd[PATH_MAX];
	char	**args;

	args = cmd->cmd_arg;
	oldpwd = getcwd(NULL, 0);
	if (!oldpwd)
		return (perror("getcwd"), 1);
	if (!args[1] || !ft_strcmp(args[1], "~"))
	{
		target = get_env_val(mns, "HOME");
		if (!target)
			return (free(oldpwd), ft_printf_fd(2, "cd: HOME not set\n"), 1);
	}
	else if (!ft_strcmp(args[1], "-"))
	{
		target = get_env_val(mns, "OLDPWD");
		if (!target)
			return (free(oldpwd), ft_printf_fd(2, "cd: OLDPWD not set\n"), 1);
		printf("%s\n", target);
	}
	else
		target = args[1];
	if (chdir(target) != 0)
		return (perror("cd"), free(oldpwd), 1);
	set_env_val(&mns->env, "OLDPWD", oldpwd);
	if (getcwd(cwd, sizeof(cwd)))
		set_env_val(&mns->env, "PWD", cwd);
	return (free(oldpwd), 0);
}
