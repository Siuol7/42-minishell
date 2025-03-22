/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_root_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 22:28:33 by tripham           #+#    #+#             */
/*   Updated: 2025/03/23 01:12:02 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast	*ast_handle_pipe_build(t_ast *root, t_token *token,
		int size, int op_index)
{
	root->left = ast_root_init(token, op_index);
	root->right = ast_root_init(token + op_index + 1, size - op_index - 1);
	if (!root->left || !root->right)
	{
		ast_free_node(root);
		return (NULL);
	}
	return (root);
}

int	ast_build_tree(t_ast *root, t_token *token, int size, int op_index)
{
	root->left = ast_root_init(token, op_index);
	root->right = ast_root_init(token + op_index + 1, size - op_index - 1);
	if (!root->left || !root->right)
	{
		ast_free_node(root);
		return (0);
	}
	return (1);
}

t_ast	*ast_handle_rd_build(t_ast *node, t_token *token,
		int size, int op_index)
{
	if (op_index + 1 >= size || (token[op_index + 1].type != CMD
			&& token[op_index + 1].type != FD))
	{
		ft_printf_fd(STDERR_FILENO, "minishell: Redirect error\n");
		ast_free_node(node);
		return (NULL);
	}
	node->right = ast_init(&token[op_index + 1]);
	if (!node->right)
	{
		ast_free_node(node);
		return (NULL);
	}
	return (node);
}

t_ast	*ast_root_init(t_token *token, int size)
{
	t_ast	*root;
	int		op_index;

	if (size <= 0 || !token)
		return (NULL);
	op_index = find_priority(token, size);
	if (op_index == -1)
		return (ast_init(token));
	root = ast_init(&token[op_index]);
	if (!root)
		return (NULL);
	if (token[op_index].type == OP_PIPE)
		return (ast_handle_pipe_build(root, token, size, op_index));
	if (token[op_index].type == RD_IN || token[op_index].type == RD_OUT
		|| token[op_index].type == RD_APPEND
		|| token[op_index].type == RD_HEREDOC)
		return (ast_handle_rd_build(root, token, size, op_index));
	if (!ast_build_tree(root, token, size, op_index))
		return (NULL);
	return (root);
}
