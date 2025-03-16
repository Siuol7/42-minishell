/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:40:48 by tripham           #+#    #+#             */
/*   Updated: 2025/03/16 23:28:49 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include "minishell.h"

typedef struct s_ast
{
	t_token			token;
	struct s_ast	*right;
	struct s_ast	*left;
}	t_ast;

void	ast_free_node(t_ast *node);
t_ast	*ast_init(t_token *token);
int		find_priority(t_token *token, int size);

t_ast	*ast_init(t_token *token);
t_ast	*ast_handle_pipe(t_ast *node);
t_ast	*ast_handle_rd(t_ast *node, t_token *token);

t_ast	*ast_handle_pipe_build(t_ast *root, t_token *token,
			int size, int op_index);
int		ast_build_tree(t_ast *root, t_token *token, int size, int op_index);
t_ast	*ast_handle_rd_build(t_ast *node, t_token *token,
			int size, int op_index);
t_ast	*ast_root_init(t_token *token, int size);
#endif
