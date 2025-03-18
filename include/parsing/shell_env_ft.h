/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_env_ft.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 01:22:16 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/19 01:23:52 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_ENV_FT_H

# define SHELL_ENV_FT_H

//STRUCT FORWARD DECLARATION
typedef struct	s_shell	t_shell;

char	**env_dup(char **env);

#endif