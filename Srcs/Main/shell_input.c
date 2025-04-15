/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:58:30 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/15 22:55:49 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	execute_part(t_shell *mns)
{
	heredoc_expand_all(mns);
	if (mns->ast)
	{
		ast_clean_all(mns->ast);
		mns->ast = NULL;
	}
	mns->ast = ast_init(mns->cmd_group, mns->group_cnt, 0);
	exec_ast(mns->ast, mns);
}

static void	shell_input_operate(t_shell *mns)
{
	prs_extra_check(mns);
	add_history(mns->full_cmd_line);
	if (mns->shell_err == -3)
	{
		printf("minishell: syntax error near unexpected token `|'\n");
		mns->exitcode = 2;
		return ;
	}
	shell_token_gen(mns, mns->full_cmd_line, -1);
	if (mns->shell_err == -2)
	{
		printf("bash: Not supporting '||' type\n");
		update_status(mns, 2);
	}
	else if (mns->shell_err == -3)
		return ;
	else if (prs_cmd_check(mns))
		execute_part(mns);
}

void	shell_input(t_shell	*mns)
{
	while (1)
	{
		signals_initialize();
		mns->full_cmd_line = readline("minishell$ ");
		if (!mns->full_cmd_line)
		{
			printf("exit\n");
			env_shlvl_down(mns);
			shell_clean(mns);
			exit (0);
		}
		if (mns->full_cmd_line[0])
		{
			shell_input_operate(mns);
			mns->shell_err = 0;
		}
		shell_pre_input(mns);
	}
}
