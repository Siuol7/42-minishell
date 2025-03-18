/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:26:37 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/18 13:43:22 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include "system_lib.h"
# include "error.h"
# include "../../library/libft/libft.h"
# include "../parsing/shell_token_type.h"
# include "../parsing/shell_token_ft.h"
# include "../execution/ast.h"
# include "../execution/execution.h"

typedef struct s_shell
{
	int		token_cnt;
	int		cmd_cnt;
	char	*full_cmd_line;
	char	**splitted_cmd;
	t_token	*list;
	t_cmd	*cmd;
	t_error	shell_err;
}	t_shell;

//OPERATION
int		shell_init(t_shell *mns, char **env);
void	shell_pre_input(t_shell *mns);
int		shell_implement(char **env);
void	shell_clean(t_shell *mns);

//PARSING
void	shell_input(t_shell	*mns);
void	shell_token_gen(t_shell *mns, char *input);

//ERROR HANDLING
void	ft_bad_alloc(t_shell *mns);

#endif