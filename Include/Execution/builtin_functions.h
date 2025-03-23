/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_functions.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 04:02:14 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/23 04:14:32 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_FUNCTIONS_H

# define BUILTIN_FUNCTIONS_H

# include "minishell.h"

void	bi_cd(t_shell *mns, t_token token);
void	bi_echo(t_shell *mns, t_token token);
void	bi_env(t_shell *mns, t_token token);
void	bi_exit(t_shell *mns, t_token token);
void	bi_export(t_shell *mns, t_token token);
void	bi_pwd(t_shell *mns, t_token token);
void	bi_unset(t_shell *mns, t_token token);

void	ep_standalone(t_shell *mns);
void	env_standalone(t_shell *mns);

#endif