/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:26:37 by caonguye          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/03/31 22:19:51 by tripham          ###   ########.fr       */
=======
/*   Updated: 2025/04/01 18:37:17 by caonguye         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include "system_lib.h"
# include "error.h"
# include "../../Library/libft/libft.h"
# include "../../Library/ft_printf_fd/ft_printf.h"
# include "../Parsing/shell_token_type.h"
# include "../Parsing/shell_token_ft.h"
# include "../Parsing/shell_env_ft.h"
# include "../Execution/ast.h"
# include "../Execution/execution.h"
# include "../Execution/builtin_functions.h"

typedef struct s_shell
{
<<<<<<< HEAD
	int			group_cnt;
	int			exitcode;
	int			shlvl;
	char		*full_cmd_line;
	char		**cmd_str;
	char		**env;

	t_cmd		*cmd_group;
	t_error		shell_err;
	t_ast		*ast;
=======
	int		group_cnt;
	int		exitcode;
	int		shlvl;
	char	*full_cmd_line;
	char	**cmd_str;
	char	**env;
	t_list	**list;
	t_cmd	*cmd_group;
	int		shell_err;
	t_ast	*ast;
>>>>>>> main
}	t_shell;

//OPERATION
int		shell_init(t_shell *mns, char **env);
void	shell_pre_input(t_shell *mns);
int		shell_implement(char **env);
void	shell_clean(t_shell *mns);
void	shell_env_gen(t_shell *mns, char **env);

//PARSING
void	shell_input(t_shell	*mns);
void	shell_token_gen(t_shell *mns, char *input);

//ERROR HANDLING
void	ft_bad_alloc(t_shell *mns);

#endif