/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_classify_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:41:54 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/09 03:09:04 by caonguye         ###   ########.fr       */
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
		|| !ft_strcmp(str, "<>") || !ft_strcmp(str, "<<<"))
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
	else if (!ft_strcmp(str, "<<<"))
		return (RD_HERESTR);
	else
		return (RD_RNW);
}
