/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_functions.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 04:02:14 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/09 11:08:06 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_FUNCTIONS_H

# define BUILTIN_FUNCTIONS_H

# include "minishell.h"

int		bi_cd(t_shell *mns, t_cmd *cmd);
int		bi_echo(t_shell *mns, t_cmd *cmd);
void	bi_env(t_shell *mns, t_token token);
void	bi_exit(t_shell *mns, t_token token);
void	bi_export(t_shell *mns, t_token token);
void	bi_pwd(t_shell *mns, t_cmd *cmd);
void	bi_unset(t_shell *mns, t_token token);

//EXPORT
void	ep_standalone(t_shell *mns);
int		ep_validation(char *str);

//ENV
void	env_standalone(t_shell *mns);
void	env_append(t_shell *mns, char *str)
char	*resolve_logic_pwd(const char *old, const char *target);

#endif