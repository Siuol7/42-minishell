/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 20:56:48 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/13 21:00:58 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exp_expand_digit(t_shell *mns, char **key, char *exp_sign)
{
	char	*temp;

	temp = *key + 1;
	if (!ft_append(&mns->post_expansion, &temp))
	{
		free(*key);
		ft_bad_alloc(mns);
	}
	free(*key);
	free(exp_sign);
}

static void	exp_expand_string(t_shell *mns, char **key, char *exp_sign)
{
	char	*str;

	get_env_val(mns, *key);
	str = ft_strdup(get_env_val(mns, *key));
	if (!str)
		ft_bad_alloc(mns);
	if (str && ft_strlen(str) > 0)
	{
		if (!ft_append(&mns->post_expansion, &str))
		{
			free(*key);
			ft_bad_alloc(mns);
		}
	}
	free(exp_sign);
}

static void	exp_copy(t_shell *mns, char **key, char *exp_sign)
{
	if (!ft_append(&mns->post_expansion, &exp_sign))
	{
		free(*key);
		ft_bad_alloc(mns);
	}
	if (!ft_append(&mns->post_expansion, key))
		ft_bad_alloc(mns);
}

void	exp_expand(t_shell *mns, char **key, char open)
{
	int		type;
	char	*exp_sign;

	type = exp_validation(*key);
	exp_sign = ft_strdup("$");
	if (!exp_sign)
	{
		free(*key);
		ft_bad_alloc(mns);
	}
	if (open == '\'')
		exp_copy(mns, key, exp_sign);
	else
	{
		if (type == 0)
		{
			if (!ft_append(&mns->post_expansion, &exp_sign))
				ft_bad_alloc(mns);
		}
		else if (type == 1)
			exp_expand_digit(mns, key, exp_sign);
		else
			exp_expand_string(mns, key, exp_sign);
	}
}
