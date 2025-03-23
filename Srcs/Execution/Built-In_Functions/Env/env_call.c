/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_call.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:23:09 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/23 04:42:48 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bi_env(t_shell *mns, t_token token)
{
	int	id;

	id = token.id;
	if (mns->cmd[id].size == 1)
		env_standalone(mns);
}
