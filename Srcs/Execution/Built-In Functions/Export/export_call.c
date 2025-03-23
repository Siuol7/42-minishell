/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_call.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:00:53 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/23 04:00:21 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bi_export(t_shell *mns, t_token token)
{
	int	id;

	id = token.id;
	if (ft_2d_len(mns->cmd[id].cmd_gr) == 1)
		ep_standalone(mns);
}
