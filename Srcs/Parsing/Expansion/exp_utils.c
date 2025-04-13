/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:31:36 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/13 15:09:31 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exp_validation(char *key)
{
	if (ft_strlen(key) == 0)
		return (0);
	else if (ft_isdigit(key[0]))
		return (1);
	return (2);
}

char	*exp_getkey(t_shell *mns, char *str, int *i)
{
	int		start;
	char	*key;

	start = ++*i;
	while (str[*i])
	{
		if (!ft_isalnum(str[*i]) && str[*i] != '_')
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
