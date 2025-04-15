/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_token_ft.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:55:24 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/15 22:42:52 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_TOKEN_FT_H

# define SHELL_TOKEN_FT_H

//STRUCT FORWARD DECLARATION
typedef struct s_shell	t_shell;
typedef struct s_point	t_point;

int				prs_cmd_check(t_shell *mns);
int				lx_qmarks_cnt(char *str);
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
void			lx_rd_typize(t_token *list,
					char **str, t_point *p);
void			prs_extra_check(t_shell *mns);
int				prs_list_check(t_shell *mns);
void			lx_cmd_group(t_shell *mns);
void			lx_cmd_group_gen(t_shell *mns, t_token *list, t_cmd *group);
char			**lx_token_split(t_shell *mns, char *input, int i);
char			**lx_group_split(t_shell *mns, char *input);
char			*lx_qmarks_eli(t_shell *mns, char *str, int i, int j);
int				prs_extra_cmd(t_shell *mns);
#endif