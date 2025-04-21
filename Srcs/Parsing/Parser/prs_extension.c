/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_extension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 01:59:48 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/21 15:57:43 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void prs_exit(t_shell *mns, char c)
{
	ft_printf_fd(2, "bash: unexpected EOF while looking for matching `%c'", c);
	shell_clean(mns);
	exit (2);
}

static void	prs_extra_arg(t_shell *mns, char c, int c_cnt)
{
	int		i;
	char	*new;
	char	*temp;

	while (1)
	{
		new = readline("> ");
		i = 0;
		if (!new)
			prs_exit(mns, c);
		while (new[i])
		{
			if (new[i] == c)
				c_cnt++;
			i++;
		}
		temp = new;
		new = ft_strjoin("\n", new);
		free(temp);
		if (!ft_append(&mns->full_cmd_line, &new))
			ft_bad_alloc(mns);
		if (c_cnt % 2 == 0)
			break ;
	}
}

static int	prs_check(t_shell *mns, int i, int alpha, int pipe)
{
	int	size;

	size = ft_strlen(mns->full_cmd_line);
	while (i < size)
	{
		if (ft_is_dquote(mns->full_cmd_line[i]))
			lx_skip_dquote(mns->full_cmd_line, &i);
		if (!ft_isallspace(mns->full_cmd_line[i])
			&& mns->full_cmd_line[i] != '|')
		{
			alpha = 1;
			pipe = 0;
		}
		else if (alpha == 1 && mns->full_cmd_line[i] == '|')
		{
			alpha = 0;
			pipe = 1;
		}
		else if (alpha == 0 && mns->full_cmd_line[i] == '|' )
			return (-2);
		i++;
	}
	if (pipe == 1 && alpha == 0)
		return (prs_extra_cmd(mns));
	return (0);
}

static int	prs_arg_check(t_shell *mns)
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
		prs_extra_arg(mns, open, 1);
	return (0);
}

void	prs_extra_check(t_shell *mns)
{
	int		flag;
	char	*temp;

	temp = ft_strdup(" |");
	while (1)
	{
		prs_arg_check(mns);
		flag = prs_check(mns, 0, 0, 0);
		if (!flag && !prs_arg_check(mns))
		{
			free(temp);
			break ;
		}
		if (flag == -2)
		{
			mns->shell_err = -3;
			free(temp);
			return ;
		}
		if (flag == -1)
		{
			ft_append(&mns->full_cmd_line, &temp);
			return ;
		}
	}
}
