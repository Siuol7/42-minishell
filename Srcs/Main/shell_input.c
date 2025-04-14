/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:58:30 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/14 11:58:36 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	shell_input_operate(t_shell *mns)
{
	prs_extra_check(mns);
	add_history(mns->full_cmd_line);
	shell_token_gen(mns, mns->full_cmd_line, -1);
	if (mns->shell_err == -2)
	{
		printf("bash: Not supporting '||' type\n");
		update_status(mns, 2);
	}
	else if (mns->shell_err == -3)
		return ;
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
