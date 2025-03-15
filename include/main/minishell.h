/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:26:37 by caonguye          #+#    #+#             */
<<<<<<< HEAD:include/minishell.h
/*   Updated: 2025/03/15 13:56:35 by tripham          ###   ########.fr       */
=======
/*   Updated: 2025/03/15 11:29:18 by caonguye         ###   ########.fr       */
>>>>>>> main:include/main/minishell.h
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include "system_lib.h"
<<<<<<< HEAD:include/minishell.h
# include "../library/libft/libft.h"
# include "parsing/shell_token_type.h"
# include "parsing/shell_token_ft.h"
# include "execution/ast.h"
# include "execution/execution.h"
=======
# include "error.h"
# include "../../library/libft/libft.h"
# include "../parsing/shell_token_type.h"
# include "../parsing/shell_token_ft.h"
>>>>>>> main:include/main/minishell.h

typedef struct s_shell
{
	int		token_len;
	char	*full_cmd_line;
<<<<<<< HEAD:include/minishell.h
	t_token	*token_list;
	t_ast	*ast;
=======
	char	**splitted_cmd;
	t_cmd	*cmd;
	t_error	shell_err;
	t_token	*list;
>>>>>>> main:include/main/minishell.h
}	t_shell;

//OPERATION
int		shell_init(t_shell *mns, char **env);
int		shell_implement(char **env);
void	shell_clean(t_shell *mns);

//PARSING
void	shell_input(t_shell	*mns);
void	shell_token_gen(t_shell *mns, char *input);
char	**ft_token_split(t_shell *mns, char *input);

#endif