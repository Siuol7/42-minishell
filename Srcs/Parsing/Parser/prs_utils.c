/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:42:09 by tripham           #+#    #+#             */
/*   Updated: 2025/04/15 22:50:11 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
