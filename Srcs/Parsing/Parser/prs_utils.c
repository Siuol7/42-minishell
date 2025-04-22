/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:42:09 by tripham           #+#    #+#             */
/*   Updated: 2025/04/22 22:16:20 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prs_rd_ambi(t_shell *mns, t_cmd *gr, t_token *lst, int *k)
{
	gr->final[*k].val = ft_strdup(lst->val);
	if (!gr->final[*k].val)
		ft_bad_alloc(mns);
	gr->final[*k].type = lst->type;
	(*k)++;
}

static void	check_new(char *new, t_shell *mns)
{
	if (!new)
	{
		printf("bash: systax error: unexpected end of file\n");
		shell_clean(mns);
		exit(2);
	}
}

int	prs_extra_cmd(t_shell *mns)
{
	char	*new;
	char	*temp;

	while (1)
	{
		new = readline("> ");
		check_new(new, mns);
		if (new[0])
			break ;
		if (new[0] == '|')
		{
			mns->shell_err = -3;
			return (-1);
		}
	}
	temp = new;
	new = ft_strjoin(" ", new);
	if (!new)
		ft_bad_alloc(mns);
	free(temp);
	if (!ft_append(&mns->full_cmd_line, &new))
		ft_bad_alloc(mns);
	return (1);
}
