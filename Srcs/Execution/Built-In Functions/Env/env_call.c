/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_call.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:23:09 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/23 04:00:02 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bi_env(t_shell *mns, t_token token)
{
	int	id;

	id = token.id;
	if (ft_2d_len(mns->cmd->cmd_gr[id]) == 1)
		env_standalone(mns);
}
