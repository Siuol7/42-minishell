/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:35:45 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/11 12:23:17 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	shell_implement(char **env)
{
	t_shell	*minishell;

	minishell = malloc(sizeof(t_shell));
	if (!minishell)
		return (0);
	shell_init(minishell, env);
	shell_input(minishell);
	shell_clean(minishell);
	return (1);
}
