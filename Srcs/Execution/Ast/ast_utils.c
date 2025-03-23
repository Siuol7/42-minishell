/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:56:17 by tripham           #+#    #+#             */
/*   Updated: 2025/03/23 02:51:37 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/Main/minishell.h"

void	ast_free_node(t_ast *node)
{
	if (!node)
		return ;
	if (node->left)
		ast_free_node(node->left);
	if (node->right)
		ast_free_node(node->right);
	if (node->token.val)
		free(node->token.val);
	free(node);
}

int	find_priority(t_token *token, int size)
{
	int	index;
	int	index_pipe;
	int	index_rd;

	index = 0;
	index_pipe = -1;
	index_rd = -1;
	while (index < size)
	{
		if (token[index].type == OP_PIPE)
			index_pipe = index;
		else if (token[index].type == RD_IN || token[index].type == RD_OUT
			|| token[index].type == RD_APPEND
			|| token[index].type == RD_HEREDOC)
			index_rd = index;
		index++;
	}
	if (index_pipe != -1)
		return (index_pipe);
	return (index_rd);
}

// void	ast_clean_all(t_ast **ast)
// {
// 	if (!ast || !*ast)
// 		return ;
// 	if ((*ast)->left)
// 		ast_clean_all(&(*ast)->left);
// 	if ((*ast)->right)
// 		ast_clean_all(&(*ast)->right);
// 	free(*ast);
// 	*ast = NULL;
// }