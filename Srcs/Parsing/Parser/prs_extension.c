/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_extension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 01:59:48 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/03 02:18:30 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	prs_extra_arg(t_shell *mns, char c)
{
	int		i;
	int		c_cnt;
	char	*new;
	char	*temp;

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
		temp = new;
		new = ft_strjoin("\n", new);
		free(temp);
		mns->full_cmd_line = ft_strjoin_free(mns->full_cmd_line, new);
		free(new);
		if (c_cnt % 2 == 0)
			break ;
	}
}

static int	prs_extra_cmd(t_shell *mns)
{
	char	*new;
	char	*temp;

	while (1)
	{
		new = readline("> ");
		if (new[0])
			break ;
	}
	temp = new;
	new = ft_strjoin(" ", new);
	if (!new)
		ft_bad_alloc(mns);
	free(temp);
	mns->full_cmd_line = ft_strjoin_free(mns->full_cmd_line, new);
	free(new);
	if (!mns->full_cmd_line)
		ft_bad_alloc(mns);
	return (1);
}

static int	prs_check(t_shell *mns, int i, int alpha, int pipe)
{
	int	size;

	size = ft_strlen(mns->full_cmd_line);
	while (i < size)
	{
		if (!ft_isallspace(mns->full_cmd_line[i]))
		{
			alpha = 1;
			pipe = 0;
		}
		if (alpha == 1 && mns->full_cmd_line[i] == '|')
		{
			if (i + 1 < size && mns->full_cmd_line[i + 1] == '|')
			{
				mns->shell_err = -2;
				return (0);
			}
			alpha = 0;
			pipe = 1;
		}
		i++;
	}
	if (pipe == 1 && alpha == 0)
		return (prs_extra_cmd(mns));
	return (0);
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
	while (1)
	{
		if (!prs_check(mns, 0, 0, 0))
			break ;
	}
}
