/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_token_ft.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:55:24 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/31 14:04:21 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_TOKEN_FT_H

# define SHELL_TOKEN_FT_H

//STRUCT FORWARD DECLARATION
typedef struct s_shell	t_shell;

int				prs_cmd_check(t_shell *mns);
int				lx_is_oprt(char *str);
int				lx_is_rd(char *str);
int				lx_skip_space(char *input, int index);
int				lx_skip_dquote(char *input, int *index);
int				lx_skip_word(char *input, int index);
int				lx_skip_cmd(char *input, int index);
int				lx_split_rd_op(char *in, char **res, int *start, int *i);
int				lx_split_word(char *in, char **res, int *start, int *i);
int				lx_split_group(char *in, char **res, int *start, int *i);
t_type			lx_rd_type(char *str);
void			prs_extra_check(t_shell *mns);
char			**lx_token_split(t_shell *mns, char *input, int i);
char			**lx_group_split(t_shell *mns, char *input);
#endif