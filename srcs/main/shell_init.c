/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:30:39 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/12 10:44:47 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	shell_init(t_shell *mns, char **env)
{
	ft_memset(mns, 0, sizeof(t_shell));
	mns->token_list = ft_calloc(1, sizeof(t_token));
	if (!mns->token_list)
		return (0);
	(void)env;
	return (1);
}
