/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:58:30 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/01 20:11:13 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_redirect_info(t_cmd *cmd)
{
	printf("Input      : %s (type %d)\n", cmd->in.val, cmd->in.type);

	for (int i = 0; i < cmd->out_cnt; i++)
		printf("Output %d   : %s (type %d)\n", i, cmd->out[i].val, cmd->out[i].type);

	for (int i = 0; i < cmd->heredoc_cnt; i++)
		printf("Heredoc %d  : %s\n", i, cmd->heredoc[i]);
}

static void	shell_debug_print(t_shell *mns)
{
	printf("\n===== SHELL DEBUG INFO =====\n");
	printf("Group count: %d\n", mns->group_cnt);
	printf("Exit code  : %d\n", mns->exitcode);
	printf("Shell level: %d\n", mns->shlvl);
	printf("Full input : %s\n", mns->full_cmd_line);
	printf("AST pointer: %p\n", (void *)mns->ast);
	printf("Error code : %d\n", mns->shell_err);
	printf("-----------------------------\n");

	for (int i = 0; i < mns->group_cnt; i++)
	{
		t_cmd *cmd = &mns->cmd_group[i];

		printf("Group %d\n", i);
		printf("Raw string : %s\n", mns->cmd_str[i]);
		printf("Command    : %s\n", cmd->cmd);

		for (int j = 0; j < cmd->arg_cnt; j++)
			printf("Arg %d      : %s\n", j, cmd->cmd_arg[j]);

		print_redirect_info(cmd);
		printf("-----------------------------\n");
	}

}

static void	shell_input_operate(t_shell *mns)
{
	prs_extra_check(mns);
	add_history(mns->full_cmd_line);
	shell_token_gen(mns, mns->full_cmd_line);

	if (prs_cmd_check(mns) && mns->shell_err != -2)
	{
		printf("OK to work\n");
		// mns->ast = build_ast(...);
		// exec_ast(mns, mns->ast);
	}
	else if (mns->shell_err == -2)
		printf("bash: Not supporting '||' type\n");

	shell_debug_print(mns);
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
