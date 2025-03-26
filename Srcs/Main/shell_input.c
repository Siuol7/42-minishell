/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:58:30 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/26 02:14:39 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_input(t_shell	*mns)
{
	while (1)
	{
		mns->full_cmd_line = readline("minishell$ ");
		if (!mns->full_cmd_line)
		{
			printf("exit");
			shell_clean(mns);
		}
		add_history(mns->full_cmd_line);
		shell_token_gen(mns, mns->full_cmd_line);
		shell_cmd_recheck(mns);
		mns->ast = ast_root_init(mns->list, mns->token_cnt);
		if (!mns->ast)
			shell_clean(mns);
		//exec_ast(mns, mns->ast);
		shell_pre_input(mns);
	}
}
