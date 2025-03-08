#ifndef AST_H
# define AST_H

#include "minishell.h"


typedef struct	s_ast
{
	t_token_type		token;
	struct s_ast		*left;
	struct s_ast		*left;
}	t_ast;


#endif
