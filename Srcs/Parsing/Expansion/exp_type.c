/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 07:58:40 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/22 01:40:05 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exp_rd_check(t_shell *mns, t_token *t, char *key, char open)
{
	if (t->type == RD_HEREDOC)
		return (1);
	else if ((open == 'e' || open == '\"')
		&& SIGN_ERR < t->type && t->type < RD_AMBI && t->type != RD_HEREDOC
		&& (!get_env_val(mns, key) || ft_strlen(get_env_val(mns, key)) == 0))
	{
		t->type = RD_AMBI;
		return (1);
	}
	return (0);
}

static void	exp_unstring(t_shell *mns, char **key)
{
	char	*str;

	str = ft_strdup(*key);
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
