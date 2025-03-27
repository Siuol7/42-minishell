/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_extension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 01:59:48 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/27 10:16:38 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prs_extra_check(t_shell *mns)
{
	int		i;
	char	open;

	i = 0;
	open = 'e';
	while (ms && mns->full_cmd_line[i])
	{
		if ((mns->full_cmd_line[i] == '\''
			|| mns->full_cmd_line[i] == '\"') && open == 'e')
			open = mns->full_cmd_line[i];
		else if ((mns->full_cmd_line[i] == '\''
			|| mns->full_cmd_line[i] == '\"')
			&& open == mns->full_cmd_line[i])
			open = 'e';
		i++;
	}
	if (open != 'e')
		prs_extra_arg(mns, open);
	else if (mns->full_cmd_line[i - 1] == '|')
		prs_extra_cmd(mns);
}
