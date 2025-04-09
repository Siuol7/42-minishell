/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:58:30 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/09 20:39:18 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	shell_input_operate(t_shell *mns)
{
	prs_extra_check(mns);
	add_history(mns->full_cmd_line);
	shell_token_gen(mns, mns->full_cmd_line, -1);
	if (mns->shell_err == -2)
		printf("bash: Not supporting '||' type\n");
	else if (mns->shell_err == -3)
		return ;
	// else if (prs_cmd_check(mns))
	// {
	// 	heredoc_expand_all(mns);
	// 	mns->ast = ast_init(mns->cmd_group, mns->group_cnt, 0);
	// 	exec_ast(mns->ast, mns);
	// }
	// printf("Group cnt %d\n", mns->group_cnt);
	// for (int i = 0; i < mns->group_cnt; i++)
	// {
	// 	printf("Group %d : %s\n", i, mns->cmd_str[i]);
	// 	printf("CMD %s\n", mns->cmd_group[i].cmd);
	// 	for (int j = 0; j < mns->cmd_group[i].arg_cnt; j++)
	// 		printf("CMD ARG %d : %s\n", j, mns->cmd_group[i].cmd_arg[j]);
	// 	printf("File in %s type %d\n", mns->cmd_group[i].in.val, mns->cmd_group[i].in.type);
	// 	for (int m = 0; m < mns->cmd_group[i].out_cnt; m++)
	// 		printf("File out %s type %d\n", mns->cmd_group[i].out[m].val, mns->cmd_group[i].out[m].type);
	// 	for (int n = 0; n < mns->cmd_group[i].heredoc_cnt; n++)
	// 		printf("HEREDOC %d is  %s\n", n, mns->cmd_group[i].heredoc[n]);
	// }
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
		{
			shell_input_operate(mns);
		}
		shell_pre_input(mns);
	}
}
// else if (prs_cmd_check(mns))
// 	{
// 		printf("OK to work\n");
// 		heredoc_expand_all(mns);
// 		mns->ast = ast_init(mns->cmd_group, mns->group_cnt, 0);
// 		exec_ast(mns->ast, mns);
// 		// chua free ast o day, nhung da free trong
//			shell_clean, double check coi co can thiet ko
// 	}