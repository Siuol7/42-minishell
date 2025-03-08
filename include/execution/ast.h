#ifndef AST_H
# define AST_H

#include "minishell.h"


typedef struct	s_ast
{
	t_token			token;
	struct s_ast	*right;
	struct s_ast	*left;
}	t_ast;


#endif
