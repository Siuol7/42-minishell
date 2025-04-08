/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:58:30 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/08 23:52:57 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	shell_input_operate(t_shell *mns)
{
	prs_extra_check(mns);
	add_history(mns->full_cmd_line);
	shell_token_gen(mns, mns->full_cmd_line);
	if (mns->shell_err == -2)
		printf("bash: Not supporting '||' type\n");
	else if (prs_cmd_check(mns))
	{
		heredoc_expand_all(mns);
		mns->ast = ast_init(mns->cmd_group, mns->group_cnt, 0);
		exec_ast(mns->ast, mns);
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