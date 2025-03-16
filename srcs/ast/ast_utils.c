/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:56:17 by tripham           #+#    #+#             */
/*   Updated: 2025/03/15 14:06:09 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_token(t_token **token)
{
	if (!token || !*token)
		return ;
	if ((*token)->value)
		free((*token)->value);
	free(*token);
	*token = NULL;
}

t_token	*token_extraction(t_token *token, int begin, int last)
{
	t_token	*new_token;
	int		index;

	if (last - begin <= 0)
		return (NULL);
	new_token = (t_token *)malloc(sizeof(t_token) * (last - begin + 1));
	if (!new_token)
	{
		ft_printt_fd(STDERR_FILENO, "minishell: Malloc failed!\n");
		return (NULL);
	}
	index = 0;
	while (begin < last)
	{
		ft_memcpy(&new_token[index], &token[begin], sizeof(t_token));
		begin++;
		index++;
	}
	ft_memset(&new_token[index], 0, sizeof(t_token));
	return (new_token);
}

int	token_size_export(t_token *token)
{
	int	size;

	size = 0;
	if (!token)
		return (0);
	while (token[size].value)
		size++;
	return (size);
}

int	oprt_location(t_token *token, int token_size)
{
	int	index;

	index = -1;
	while (index < token_size)
	{
		if (token[index].type == PIPE)
			return (index);
		index++;
	}
	return (-1);
}
