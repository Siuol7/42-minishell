/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_token_type.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2025/03/07 10:54:31 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/31 22:16:19 by tripham          ###   ########.fr       */
=======
/*   Created: 2025/04/01 01:28:19 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/01 18:32:51 by caonguye         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_TOKEN_TYPE_H

# define SHELL_TOKEN_TYPE_H
# include "../Main/minishell.h"

typedef enum s_type
{
	CMD,
	ARG,
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
<<<<<<< HEAD
	t_token_type	type;
	char			*val;
=======
	t_type	type;
	char	*val;
>>>>>>> main
}	t_token;

typedef struct s_cmd
{
<<<<<<< HEAD
	int			token_cnt;
	char		**token;
	t_token		*list;

	int			out_cnt;
	int			heredoc_cnt;

	char		*cmd;
	char		**cmd_arg;

	t_rd		in;
	t_rd		*out;
	char		**heredoc;
=======
	int		token_cnt;
	char	**token;
	t_token	*list;
	int		arg_cnt;
	int		out_cnt;
	int		heredoc_cnt;
	char	*cmd;
	char	**cmd_arg;
	t_token	in;
	t_token	*out;
	char	**heredoc;
>>>>>>> main
}	t_cmd;

#endif