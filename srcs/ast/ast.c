/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:58:02 by tripham           #+#    #+#             */
/*   Updated: 2025/03/13 17:12:48 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ast_intit_root(t_ast *ast, t_token *tokens, int token_size, int index)
{
	t_token	*ast_left;
	t_token	*ast_right;

	if (index >= token_size || index < 0 || !tokens || !ast)
		return (0);
	ast_left = tokes_extraction(tokens, 0, index);
	ast_right = tokes_extraction(tokens, index + 1, token_size);
	ast->token = tokens[index];
	ast->left = ast_init(ast_left, index);
	ast->left = ast_init(ast_right, token_size - index - 1);

	if (ast_left)
		free_token(ast_left);
	if (ast_right)
		free_token(ast_right);
	return (1);
}

t_ast	*ast_init(t_token *tokens, int token_size)
{
	
}