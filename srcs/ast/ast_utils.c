/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:56:17 by tripham           #+#    #+#             */
/*   Updated: 2025/03/13 17:25:08 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef struct s_token
{
	t_oprt_type	type; 
	char		*value; 
}  t_token;

void	free_token(t_token **token)
{	
	if (!token || !*token)
		return ;	
	if ((*token)->value)
		free((*token)->value);
	free(*token);
	*token = NULL;
}

t_token *tokens_extraction(t_token *tokens, int begin, int last)
{
	t_token	*new_tokens;
	int		index;

	if (last - begin <= 0)
		return (NULL);
	
	new_tokens = (t_token *)malloc(sizeof(t_token) * (last - begin + 1));
	if (!new_tokens)
	{
		ft_printt_fd(STDERR_FILENO, "minishell: Malloc failed!\n"); // add printf_fd
		return (NULL);
	}
	index = 0;
	while (begin < last)
	{
		ft_memcpy(&new_tokens[index], &tokens[begin], sizeof(t_token));
		begin++;
		index++;
	}
	ft_memset(&new_tokens[index], 0, sizeof(t_token));
	return (new_tokens);
}



