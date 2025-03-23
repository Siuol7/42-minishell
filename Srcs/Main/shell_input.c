/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:58:30 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/23 01:35:19 by caonguye         ###   ########.fr       */
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
		if (!ft_strcmp(mns->full_cmd_line, "exit"))
			return ;
		shell_token_gen(mns, mns->full_cmd_line);
		mns->ast = ast_root_init(mns->list, mns->token_cnt);
		if (mns->ast)
		{
			exec_ast(mns, mns->ast);
			print_ast(mns->ast, 0);
		}
		shell_pre_input(mns);
	}
}
