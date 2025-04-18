/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_functions.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 04:02:14 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/18 21:42:57 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_FUNCTIONS_H
# define BUILTIN_FUNCTIONS_H
# include "minishell.h"

int		bi_cd(t_shell *mns, t_cmd *cmd);
int		bi_echo(t_shell *mns, t_cmd *cmd);
void	bi_env(t_shell *mns, t_cmd *cmd);
void	bi_exit(t_shell *mns, t_cmd *cmd);
void	bi_export(t_shell *mns, t_cmd *cmd);
void	bi_pwd(t_shell *mns, t_cmd *cmd);
int		bi_unset(t_shell *mns, t_cmd *cmd);

//EXPORT
void	ep_standalone(t_shell *mns);
int		ep_validation(t_shell *mns, char *str, int i, int size);
int		ep_exist(t_shell *mns, char *str);
void	ep_replace(t_shell *mns, char *str, int i);

//ENV
void	env_standalone(t_shell *mns);
void	env_append(t_shell *mns, char *str);
char	*resolve_logic_pwd(const char *old, const char *target);
void	env_append(t_shell *mns, char *str);

void	unset_env_var(char *key, char ***env);

#endif