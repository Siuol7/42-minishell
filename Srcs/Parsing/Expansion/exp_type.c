/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 07:58:40 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/21 04:18:03 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exp_rd_check(t_shell *mns, t_token *t, char *key, char open)
{
	if ((open == 'e' || open == '\"')
		&& SIGN_ERR < t->type && t->type < RD_AMBI
		&& !get_env_val(mns, key))
		return (1);
	return (0);
}

static void	exp_unstring(t_shell *mns, char **key)
{
	char	*str;

	str = lx_qmarks_eli(mns, *key, 0, 0);
	if (!str)
	{
		free(*key);
		ft_bad_alloc(mns);
	}
	if (str && ft_strlen(str) > 0)
	{
		if (!ft_append(&mns->post_expansion, &str))
		{
			free(*key);
			ft_bad_alloc(mns);
		}
	}
	free(*key);
}

void	exp_type(t_shell *mns, char **key, char open, t_token *t)
{
	if (ft_is_dquote(key[0][0]))
		exp_unstring(mns, key);
	else
		exp_expand(mns, key, open, t);
}
