/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bad_allocation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:30:41 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/30 23:51:51 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_not_support(t_shell *mns, char *str)
{
	printf("bash: Not supporting %s", str);
	shell_clean(mns);
	exit(EXIT_SUCCESS);
}

void	ft_bad_alloc(t_shell *mns)
{
	shell_clean(mns);
	exit(EXIT_FAILURE);
}
