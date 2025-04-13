/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:30:39 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/14 01:52:15 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	shell_init(t_shell *mns, char **env)
{
	ft_memset(mns, 0, sizeof(t_shell));
	shell_env_gen(mns, env);
	env_shlvl(mns);
	return (1);
}
