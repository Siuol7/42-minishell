/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:58:02 by tripham           #+#    #+#             */
/*   Updated: 2025/03/24 00:58:36 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/Main/minishell.h"

static char	*init_token_val(char *src)
{
	char	*dup;

	if (!src)
		return (NULL);
	dup = ft_strdup(src);
	if (!dup)
		ft_printf_fd(STDERR_FILENO, "minishell: Malloc failed!\n");
	return (dup);
}

t_ast	*ast_init(t_token *token)
{
	t_ast	*node;

	if (!token)
		return (NULL);
	node = (t_ast *)malloc(sizeof(t_ast));
	if (!node)
	{
		ft_printf_fd(STDERR_FILENO, "minishell: Malloc failed!\n");
		return (NULL);
	}
	node->token.id = token->id;
	node->token.type = token->type;
	node->token.val = init_token_val(token->val);
	if (token->val && !node->token.val)
	{
		free(node);
		return (NULL);
	}
	node->left = NULL;
	node->right = NULL;
	if (token->type == OP_PIPE)
		return (ast_handle_pipe(node));
	if (RD_IN <= token->type && token->type <= RD_HEREDOC)
		return (ast_handle_rd(node, token));
	return (node);
}

t_ast	*ast_handle_rd(t_ast *node, t_token *token)
{
	if (!token[1].val)
	{
		ft_printf_fd(STDERR_FILENO,
			"minishell: syntax error near unexpected token `newline'\n");
		free(node->token.val);
		free(node);
		return (NULL);
	}
	node->right = ast_init(token + 1);
	if (!node->right)
	{
		free(node->token.val);
		free(node);
		return (NULL);
	}
	return (node);
}

t_ast	*ast_handle_pipe(t_ast *node)
{
	if (!node)
		return (NULL);
	node->left = NULL;
	node->right = NULL;
	return (node);
}
