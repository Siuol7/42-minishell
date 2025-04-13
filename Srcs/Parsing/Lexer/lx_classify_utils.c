/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_classify_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:41:54 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/13 20:23:34 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lx_is_oprt(char *str)
{
	if (!ft_strcmp(str, "|") || !ft_strcmp(str, "||")
		|| !ft_strcmp(str, "&&"))
		return (1);
	return (0);
}

int	lx_is_rd(char *str)
{
	if (!ft_strcmp(str, ">") || !ft_strcmp(str, "<")
		|| !ft_strcmp(str, ">>") || !ft_strcmp(str, "<<")
		|| !ft_strcmp(str, "<>"))
		return (1);
	return (0);
}

t_type	lx_rd_type(char *str)
{
	if (!ft_strcmp(str, "<"))
		return (RD_IN);
	else if (!ft_strcmp(str, ">"))
		return (RD_OUT);
	else if (!ft_strcmp(str, ">>"))
		return (RD_APPEND);
	else if (!ft_strcmp(str, "<<"))
		return (RD_HEREDOC);
	else
		return (RD_RNW);
}

void	lx_rd_typize(t_shell *mns, t_token *list, char **str, t_point *p)
{
	if (p->start + 1 < p->end && !lx_is_rd(str[p->start + 1]))
	{
		list[p->start].type = SIGN;
		p->start += 1;
		list[p->start].type = lx_rd_type(str[p->start - 1]);
		list[p->start].val = lx_qmarks_eli(mns, str[p->start], 0, 0);
	}
	else if (p->start + 2 < p->end && !ft_strcmp(str[p->start], "<<")
		&& !ft_strcmp(str[p->start + 1], "<") && str[p->start + 2])
	{
		list[p->start].type = SIGN;
		list[p->start + 1].type = SIGN;
		list[p->start + 2].type = RD_HERESTR;
		list[p->start + 2].val = lx_qmarks_eli(mns, str[p->start], 0, 0);
		p->start += 2;
	}
	else if (p->start + 2 < p->end && lx_is_rd(str[p->start])
			&& lx_is_rd(str[p->start + 1]))
	{
		list[p->start].type = SIGN;
		list[p->start + 1].type = SIGN_ERR;
		list[p->start + 1].val = lx_qmarks_eli(mns, str[p->start], 0, 0);
		p->start += 2;
	}
}
