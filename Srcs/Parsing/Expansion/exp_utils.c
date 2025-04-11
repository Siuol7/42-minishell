/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:31:36 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/11 19:44:53 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exp_validation(char *str, )

int	exp_check_open(char c, char *open)
{
	if (c == '\'' || c == '\"')
	{
		if (*open == c)
			*open = '';
		else if (*open == '')
			*open = c;
	}
}
