/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:58:30 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/23 01:03:58 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void print_ast(t_ast *root, int level)
{
    int i;

    if (!root)
        return;
    
    for (i = 0; i < level; i++)
        printf("  ");
    printf("[Type: %d, Value: %s]\n", root->token.type, 
           root->token.val ? root->token.val : "NULL");
    
    if (root->left)
    {
        for (i = 0; i < level; i++)
            printf("  ");
        printf("Left:\n");
        print_ast(root->left, level + 1);
    }
    
    if (root->right)
    {
        for (i = 0; i < level; i++)
            printf("  ");
        printf("Right:\n");
        print_ast(root->right, level + 1);
    }
}

void	shell_input(t_shell	*mns)
{
	while (1)
	{
		mns->full_cmd_line = readline("minishell$ ");
		if (!ft_strcmp(mns->full_cmd_line, "exit"))
			return ;
		shell_token_gen(mns, mns->full_cmd_line);
		mns->ast = ast_root_init(mns->list, mns->token_cnt);
		if (mns->ast)
		{
			execute_ast(mns, mns->ast);
			print_ast(mns->ast, 0);
		}
		shell_pre_input(mns);
	}
}
