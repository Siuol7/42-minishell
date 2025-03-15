/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:58:02 by tripham           #+#    #+#             */
/*   Updated: 2025/03/15 13:58:35 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ast_intit_root(t_ast *ast, t_token *token, int token_size, int index)
{
	t_token	*ast_left;
	t_token	*ast_right;

	if (index >= token_size || index < 0 || !token || !ast)
		return (0);
	ast_left = tokes_extraction(token, 0, index);
	ast_right = tokes_extraction(token, index + 1, token_size);
	ast->token = token[index];
	ast->left = ast_init(ast_left);
	ast->left = ast_init(ast_right);
	if (ast_left)
		free_token(ast_left);
	if (ast_right)
		free_token(ast_right);
	return (1);
}

t_ast	*ast_init(t_token *token)
{
	t_ast	*ast;
	int		size;

	if (!token)
		return (NULL);
	size = token_size_export(token);
	if (size <= 0)
		return (NULL);
	ast = (t_ast *)malloc(sizeof(t_ast));
	if (!ast)
	{
		ft_printt_fd(STDERR_FILENO, "minishell: Malloc failed!\n");
		return (NULL);
	}
}