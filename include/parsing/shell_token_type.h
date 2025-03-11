/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_token_type.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:54:31 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/11 19:18:49 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_TOKEN_TYPE_H

# define SHELL_TOKEN_TYPE_H
# include "minishell.h"

typedef enum s_token_type
{
	CMD,
	OPRT,
	RD
}	t_token_type;

typedef enum s_oprt_type
{
	PIPE,
	AND,
	OR
}	t_oprt_type;

typedef enum s_rd_type
{
	IN,
	OUT,
	APPEND,
	HEREDOC
}	t_rd_type;

typedef struct s_oprt
{
	char		*val;
	t_oprt_type	type;
}	t_oprt;

typedef struct s_rd
{
	int			*fd;
	char		*val;
	t_rd_type	type;
}	t_rd;

typedef struct s_token
{
	int		size;
	int		cmd_size;
	int		oprt_size;
	int		rd_size;
	char	**cmd;
	t_oprt	**oprt;
	t_rd	**rd;

}	t_token;

#endif