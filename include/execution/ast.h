/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:40:48 by tripham           #+#    #+#             */
/*   Updated: 2025/03/15 13:58:12 by tripham          ###   ########.fr       */
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

typedef enum s_type
{
	NONE,
	CMD,
	PIPE
}	t_type;

typedef struct s_token
{
	t_type	type;
	char	*value;
}	t_token;

int		token_size_export(t_token *token);
t_token	*token_extraction(t_token *tokens, int begin, int last);
void	free_token(t_token **token);
t_ast	*ast_init(t_token *token);
int		oprt_location(t_token *token, int token_size);

#endif
