/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:26:37 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/08 14:14:12 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include "system_lib.h"
# include "parsing/shell_token_type.h"
# include "parsing/shell_token_ft.h"

typedef struct s_shell
{
	char	*full_cmd_line;
	t_token	*token_list;
}	t_shell;

#endif