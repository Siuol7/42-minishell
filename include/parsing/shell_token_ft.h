/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_token_ft.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:55:24 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/16 04:40:03 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_TOKEN_FT_H

# define SHELL_TOKEN_FT_H

//STRUCT FORWARD DECLARATION
typedef struct s_shell	t_shell;

int				lx_is_oprt(char *str);
int				lx_is_rd(char *str);
int				lx_skip_space(char *input, int index);
int				lx_skip_dquote(char *input, int index);
int				lx_skip_word(char *input, int index);
int				lx_cmd_cnt(t_shell *mns, int j);
int				lx_cmd_group_cnt(t_shell *mns);
int				lx_split_word(char *in, char **res, int *start, int *i);
int				lx_split_dquote(char *in, char **res, int *start, int *i);
void			lx_cmd_grouping(t_shell *mns);
t_token_type	lx_oprt_type(char *str);
t_token_type	lx_rd_type(char *str);
void			lx_cmd_grouping(t_shell *mns);
#endif