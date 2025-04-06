/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_call.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:36:00 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/07 02:05:43 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bi_pwd(t_shell *mns, t_cmd *cmd)
{
	char	cwd[PATH_MAX];

	(void)mns;
	(void)cmd;
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		ft_printf_fd(STDOUT_FILENO, "%s\n", cwd);
	else
		perror("pwd");
}
