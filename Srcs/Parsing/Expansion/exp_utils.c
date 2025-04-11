/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:31:36 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/11 20:35:21 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ep_getkey(t_shell *mns, char *str, int *i)
{
	int		start;
	char	*key;

	start = ++(*i);
	while (str[*i])
	{
		if (str[*i] == ' ' || str[*i] == '$')
			break;
		(*i)++;
	}
	key = ft_substr(str, start, *i - start);
	if (!key)
		ft_bad_alloc(mns);
	return (key);
}

void	exp_check_open(char c, char *open)
{
	if (c == '\'' || c == '\"')
	{
		if (*open == c)
			*open = 'e';
		else if (*open == 'e')
			*open = c;
	}
}
