/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classify_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:41:54 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/16 02:22:23 by caonguye         ###   ########.fr       */
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
		|| !ft_strcmp(str, ">>") || !ft_strcmp(str, "<<"))
		return (1);
	return (0);
}

t_token_type	lx_oprt_type(char *str)
{
	if (!ft_strcmp(str, "|"))
		return (OP_PIPE);
	else if (!ft_strcmp(str, "||"))
		return (OP_OR);
	else
		return (OP_AND);
}

t_token_type	lx_rd_type(char *str)
{
	if (!ft_strcmp(str, "<"))
		return (RD_IN);
	else if (!ft_strcmp(str, ">"))
		return (RD_OUT);
	else if (!ft_strcmp(str, ">>"))
		return (RD_APPEND);
	else
		return (RD_HEREDOC);
}
