/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:17:55 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/25 13:40:12 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lx_skip_space(char *input, int index)
{
	while (ft_isallspace(input[index]) && input[index])
		index++;
	return (index);
}

int	lx_skip_dquote(char *input, int *index)
{
	(*index)++;
	while (input[*index])
	{
		if (!ft_is_dquote(input[*index]))
			(*index)++;
		else if (ft_is_dquote(input[*index])
			&& ft_is_dquote(input[*index + 1]))
			(*index) += 2;
		else
			break ;
	}
	return (++(*index));
}

int	lx_skip_word(char *input, int index)
{
	while (input[index] && !ft_isallspace(input[index]))
	{
		if (ft_is_dquote(input[index]))
			lx_skip_dquote(input, &index);
		else
			index++;
	}
	return (index);
}

int	lx_split_word(char *in, char **res, int *start, int *i)
{
	int	end;

	end = lx_skip_word(in, *start);
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
