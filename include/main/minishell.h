/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:26:37 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/15 14:27:25 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include "system_lib.h"
# include "error.h"
# include "../../library/libft/libft.h"
# include "../parsing/shell_token_type.h"
# include "../parsing/shell_token_ft.h"

typedef struct s_shell
{
	int		token_len;
	char	*full_cmd_line;
	char	**splitted_cmd;
	t_cmd	*cmd;
	t_error	shell_err;
	t_token	*list;
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