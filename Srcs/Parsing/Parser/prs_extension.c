/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_extension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 01:59:48 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/27 11:25:10 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	prs_extra_arg(t_shell *mns, char c)
{
	int		i;
	int		c_cnt;
	char	*new;

	c_cnt = 1;
	while (1)
	{
		new = readline("> ");
		i = 0;
		while (new[i])
		{
			if (new[i] == c)
				c_cnt++;
			i++;
		}
		new = ft_strjoin_free("\n", new);
		mns->full_cmd_line = ft_strjoin_free(new, mns->full_cmd_line);
		free(new);
		if (c_cnt % 2 == 0)
			break ;
	}
}

static void	prs_extra_cmd(t_shell *mns)
{
	char	*new;

	new = readline("> ");
	new = ft_strjoin_free(" ", new);
	mns->full_cmd_line = ft_strjoin_free(new, mns->full_cmd_line);
	free(new);
}

void	prs_extra_check(t_shell *mns)
{
	int		i;
	char	open;

	i = 0;
	open = 'e';
	while (mns && mns->full_cmd_line[i])
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
