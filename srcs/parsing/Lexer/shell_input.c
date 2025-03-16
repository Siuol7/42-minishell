/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:58:30 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/16 04:41:04 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_input(t_shell	*mns)
{
	while (1)
	{
		mns->full_cmd_line = readline("minishell$ ");
		shell_token_gen(mns, mns->full_cmd_line);
		printf("Token len: %d\n", mns->token_cnt);
		for (int i = 0; i < mns->token_cnt; i++)
			printf("Token %d : %s\n", i, mns->list[i].val);
		for (int j = 0; j < mns->cmd_cnt; j++)
		{
			printf("Cmd %d, %s\n", j, mns->cmd[j].cmd);
			for (int k = 0; k < mns->cmd[j].size; k++)
				printf("Cmd group %d : %s ", j, mns->cmd[j].cmd_gr[k]);
		}
		free(mns->full_cmd_line);
		ft_free_2d((void **)mns->splitted_cmd);
		free(mns->list);
	}
}
