TCSANOW/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_token_type.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:54:31 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/31 15:54:39 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_TOKEN_TYPE_H

# define SHELL_TOKEN_TYPE_H
# include "../Main/minishell.h"

typedef enum s_type
{
	CMD,
	ARG,
	OP_PIPE,
	OP_AND,
	OP_OR,
	RD_IN,          
	SIGN,
	RD_IN,
	RD_OUT,
	RD_APPEND,
	RD_HEREDOC,
	RD_RNW
}	t_type;

typedef struct s_rd
{
	t_type	type;
	char	*val;
}	t_rd;

typedef struct s_token
{
	t_type	type;
	char	*val;
}	t_token;

typedef struct s_cmd
{
	int		token_cnt;
	char	**token;
	t_token	*list;
	int		out_cnt;
	int		heredoc_cnt;
	char	*cmd;
	char	**cmd_arg;
	t_rd	in;
	t_rd	*out;
	char	**heredoc;
}	t_cmd;

#endif