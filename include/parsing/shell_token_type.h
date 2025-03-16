/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_token_type.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:54:31 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/16 04:38:43 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_TOKEN_TYPE_H

# define SHELL_TOKEN_TYPE_H
# include "minishell.h"

typedef enum s_token_type
{
	CMD,
	OP_PIPE,
	OP_AND,
	OP_OR,
	RD_IN,
	RD_OUT,
	RD_APPEND,
	RD_HEREDOC,
	FD
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*val;
}	t_token;

typedef struct s_cmd
{
	int		size;
	char	*cmd;
	char	**cmd_gr;
}	t_cmd;

#endif