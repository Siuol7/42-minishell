/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:24:53 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/12 10:59:42 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_clean(t_shell *mns)
{
	if (!mns)
		return ;
	if (mns->full_cmd_line)
		free(mns->full_cmd_line);
	if (mns->token_list)
		free(mns->token_list);
	free(mns);
}
