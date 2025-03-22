/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 00:21:45 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/18 20:20:55 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void test_ast_input(t_shell *mns);

int	main(int ac, char **av, char **env)
{
	(void)av;
	if (ac != 1)
		return (EXIT_FAILURE);
	return (shell_implement(env));
}
