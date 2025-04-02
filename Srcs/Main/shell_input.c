/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:58:30 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/03 02:19:54 by caonguye         ###   ########.fr       */
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
		printf("OK to work\n");
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
