/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 00:21:45 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/10 01:39:01 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	main(int ac, char **av, char **env)
{
	(void)av;
	if (ac != 1)
		return (EXIT_FAILURE);
	return (shell_implement(env));
}
