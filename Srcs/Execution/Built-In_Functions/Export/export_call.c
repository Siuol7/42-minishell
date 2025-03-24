/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_call.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:00:53 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/23 05:12:07 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bi_export(t_shell *mns, t_token token)
{
	int	id;

	id = token.id;
	if (mns->cmd[id].size == 1)
		ep_standalone(mns);
}
