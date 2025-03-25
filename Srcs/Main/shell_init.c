/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:30:39 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/25 17:23:45 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	shell_init(t_shell *mns, char **env)
{
	ft_memset(mns, 0, sizeof(t_shell));
	shell_env_gen(mns, env);
	return (1);
}
