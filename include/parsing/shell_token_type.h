/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_token_type.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:54:31 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/15 13:57:21 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_TOKEN_TYPE_H

# define SHELL_TOKEN_TYPE_H
# include "minishell.h"

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

typedef struct s_cmd
{
	char	*cmd;
	char	**full;
}	t_cmd;

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
	int		cmd_size;
	int		oprt_size;
	int		rd_size;
	t_cmd	**cmd;
	t_oprt	**oprt;
	t_rd	**rd;
}	t_token;

#endif