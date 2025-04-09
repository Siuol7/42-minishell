/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_functions.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 04:02:14 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/09 21:03:12 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_FUNCTIONS_H

# define BUILTIN_FUNCTIONS_H

# include "minishell.h"

int		bi_cd(t_shell *mns, t_cmd *cmd);
int		bi_echo(t_shell *mns, t_cmd *cmd);
void	bi_env(t_shell *mns, t_cmd *cmd);
void	bi_exit(t_shell *mns, t_cmd *cmd);
void	bi_export(t_shell *mns, t_token token);
void	bi_pwd(t_shell *mns, t_cmd *cmd);

void	ep_standalone(t_shell *mns);
void	env_standalone(t_shell *mns);
char	*resolve_logic_pwd(const char *old, const char *target);
void	env_append(t_shell *mns, char *str);

int		bi_unset(char **cmd_group, char ***env);
#endif