/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_call.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:33:28 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/10 22:02:06 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_cd_target(t_shell *mns, char **args)
{
	char	*target;

	if (!args[1] || !ft_strcmp(args[1], "~"))
	{
		target = get_env_val(mns, "HOME");
		if (!target)
		{
			ft_printf_fd(2, "cd: HOME not set\n");
			return (NULL);
		}
	}
	else if (!ft_strcmp(args[1], "-"))
	{
		target = get_env_val(mns, "OLDPWD");
		if (!target)
		{
			ft_printf_fd(2, "cd: OLDPWD not set\n");
			return (NULL);
		}
		printf("%s\n", target);
	}
	else
		target = args[1];
	return (target);
}

static void	update_pwd(t_shell *mns, char *target)
{
	char	*logic_pwd;
	char	*cur_pwd;
	char	cwd[PATH_MAX];

	if (getcwd(cwd, sizeof(cwd)))
		set_env_val(&mns->env, "PWD", cwd);
	else
	{
		ft_printf_fd(2, "cd: error retrieving current directory:");
		ft_printf_fd(2, " getcwd: cannot access parent directories:");
		ft_printf_fd(2, " No such file or directory\n");
		cur_pwd = get_env_val(mns, "PWD");
		logic_pwd = resolve_logic_pwd(cur_pwd, target);
		if (logic_pwd)
		{
			set_env_val(&mns->env, "PWD", logic_pwd);
			free(logic_pwd);
		}
	}
}

int	bi_cd(t_shell *mns, t_cmd *cmd)
{
	char	*oldpwd;
	char	*target;
	char	**args;

	args = cmd->cmd_arg;
	oldpwd = getcwd(NULL, 0);
	if (!oldpwd)
		oldpwd = ft_strdup(get_env_val(mns, "PWD"));
	if (!oldpwd)
		return (perror("getcwd"), 1);
	target = get_cd_target(mns, args);
	if (!target)
		return (update_status(mns, 1), free(oldpwd), 1);
	if (!target)
		return (update_status(mns, 1), free(oldpwd), 1);
	if (chdir(target) != 0)
		return (perror("cd"), update_status(mns, 1), free(oldpwd), 1);
	set_env_val(&mns->env, "OLDPWD", oldpwd);
	update_pwd(mns, target);
	return (free(oldpwd), 0);
}
