/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:30:39 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/12 00:38:50 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	shell_init(t_shell *mns, char **env)
{
	ft_memset(mns, 0, sizeof(t_shell));
	(void)env;
	return (0);
}
