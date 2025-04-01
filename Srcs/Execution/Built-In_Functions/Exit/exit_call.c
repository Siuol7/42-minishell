/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_call.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:34:33 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/28 11:06:17 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exit_standalone(t_shell *mns)
{
	printf("exit\n");
	shell_clean(mns);
	exit(0);
}

void	bi_exit(t_shell *mns, t_token token)
{
	int	id;

	id = token.id;
	if (mns->cmd[id].size == 1)
		exit_standalone(mns);
}
