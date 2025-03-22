/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_implement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:35:45 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/18 20:31:08 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	shell_implement(char **env)
{
	t_shell	*minishell;

	minishell = malloc(sizeof(t_shell));
	if (!minishell)
		return (1);
	shell_init(minishell, env);
	shell_input(minishell);
	shell_clean(minishell);
	return (0);
}
