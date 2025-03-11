/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:17:55 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/12 00:41:31 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_skip_space(char *input, int index)
{
	while (ft_isallspace(input[index]) && input[index])
		index++;
	return (index);
}

int	ft_skip_dquote(char *input, int index)
{
	while (!ft_is_dquote(input[index]) && input[index])
		index++;
	return (++index);
}

int	ft_skip_word(char *input, int index)
{
	while (!ft_isallspace(input[index])
		&& !ft_is_dquote(input[index])
		&& input[index])
		index++;
	return (index);
}

int	ft_split_word(char *in, char **res, int *start, int *i)
{
	int	end;

	end = ft_skip_word(in, *start);
	res[*i] = ft_substr(in, *start, end - *start);
	if (!res[*i])
	{
		ft_free_process_2d(res, *i);
		return (0);
	}
	*start = end;
	(*i)++;
	return (1);
}

int	ft_split_dquote(char *in, char **res, int *start, int *i)
{
	int	end;

	end = ft_skip_dquote(in, ++(*start));
	res[*i] = ft_substr(in, *start, end - *start - 1);
	if (!res[*i])
	{
		ft_free_process_2d(res, *i);
		return (0);
	}
	*start = end;
	(*i)++;
	return (1);
}
