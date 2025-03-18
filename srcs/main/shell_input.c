/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:58:30 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/18 11:51:13 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_input(t_shell	*mns)
{
	while (1)
	{
		mns->full_cmd_line = readline("minishell$ ");
		if (!ft_strcmp(mns->full_cmd_line, "exit"))
			return ;
		shell_token_gen(mns, mns->full_cmd_line);
		printf("Total : %d\n", mns->token_cnt);
		for (int i = 0; i < mns->token_cnt; i++)
			printf("Token %d : %s size %ld\n", i, mns->list[i].val, ft_strlen(mns->list[i].val));
		free(mns->full_cmd_line);
		ft_free_2d((void **)mns->splitted_cmd);
		free(mns->list);
	}
}
