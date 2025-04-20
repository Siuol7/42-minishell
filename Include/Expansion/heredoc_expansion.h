/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expansion.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 22:11:28 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/20 22:14:59 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_EXPANSION_H

# define HEREDOC_EXPANSION_H

#include "minishell.h"

typedef struct s_shell	t_shell;

char	*hd_expansion_gen(t_shell *mns, char **line);


#endif