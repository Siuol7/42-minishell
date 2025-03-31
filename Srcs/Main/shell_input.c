/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:58:30 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/31 15:31:36 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	shell_input_operate(t_shell *mns)
{
	//prs_extra_check(mns);
	add_history(mns->full_cmd_line);
	shell_token_gen(mns, mns->full_cmd_line);
	// if (prs_cmd_check(mns))
	// {
	// 	mns->ast = ast_root_init(mns->list, mns->token_cnt);
	// 	if (!mns->ast)
	// 		shell_clean(mns);
	// 	exec_ast(mns, mns->ast);
	// }
	printf("Group cnt %d\n", mns->group_cnt);
	for (int i = 0; i < mns->group_cnt; i++)
	{
		printf("Group %d : %s\n", i, mns->cmd_str[i]);
		for (int j = 0; j < mns->cmd_group[i].token_cnt; j++)
			printf("Token : %s\n", mns->cmd_group[i].token[j]);
	}
}

void	shell_input(t_shell	*mns)
{
	while (1)
	{
		mns->full_cmd_line = readline("minishell$ ");
		if (!mns->full_cmd_line)
		{
			printf("exit\n");
			shell_clean(mns);
		}
		if (mns->full_cmd_line[0])
			shell_input_operate(mns);
		shell_pre_input(mns);
	}
}
