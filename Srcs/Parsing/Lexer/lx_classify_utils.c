/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_classify_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:41:54 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/09 20:56:08 by caonguye         ###   ########.fr       */
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

void	lx_rd_typize(t_token *list, char **str, int *id, int size)
{
	if (*id + 1 < size && !lx_is_rd(str[*id + 1]))
	{
		list[*id].type = SIGN;
		*id += 1;
		list[*id].type = lx_rd_type(str[*id - 1]);
		list[*id].val = ft_strdup(str[*id]);
	}
	else if (*id + 2 < size && !ft_strcmp(str[*id], "<<")
		&& !ft_strcmp(str[*id + 1], "<") && str[*id + 2])
	{
		list[*id].type = SIGN;
		list[*id + 1].type = SIGN;
		list[*id + 2].type = RD_HERESTR;
		list[*id + 2].val = ft_strdup(str[*id + 2]);
		*id += 2;
	}
	else if (*id + 2 < size && lx_is_rd(str[*id]) && lx_is_rd(str[*id + 1]))
	{
		list[*id].type = SIGN;
		list[*id + 1].type = SIGN_ERR;
		list[*id + 1].val = ft_strdup(str[*id + 1]);
		*id += 2;
	}
}
