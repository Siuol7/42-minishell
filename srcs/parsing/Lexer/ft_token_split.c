/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:38:56 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/16 02:57:41 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_wordcnt(char	*input)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (input[i])
	{
		if (ft_is_dquote(input[i]))
		{
			cnt++;
			i = lx_skip_dquote(input, ++i);
		}
		else if (ft_isallspace(input[i]))
			i = lx_skip_space(input, i);
		else
		{
			cnt++;
			i = lx_skip_word(input, i);
		}
	}
	return (cnt);
}

char	**ft_splitting(char *in, char **res, int i, int lim)
{
	int		start;

	start = 0;
	while (in[start] && i < lim)
	{
		if (ft_is_dquote(in[start]))
		{
			if (!lx_split_dquote(in, res, &start, &i))
				return (NULL);
		}
		else if (ft_isallspace(in[start]))
			start = lx_skip_space(in, start);
		else
		{
			if (!lx_split_word(in, res, &start, &i))
				return (NULL);
		}
	}
	return (res);
}

char	**ft_token_split(t_shell *mns, char *input)
{
	int		wordcnt;
	char	**final;
	char	**res;

	wordcnt = ft_wordcnt(input);
	final = (char **)malloc((wordcnt + 1) * sizeof (char *));
	if (!final)
		return (NULL);
	res = final;
	if (!ft_splitting(input, res, 0, wordcnt))
	{
		free(final);
		return (NULL);
	}
	final[wordcnt] = NULL;
	mns->token_cnt = wordcnt;
	return (final);
}
