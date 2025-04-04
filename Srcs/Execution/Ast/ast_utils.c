/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:56:17 by tripham           #+#    #+#             */
/*   Updated: 2025/04/04 16:34:20 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ast_clean_all(t_ast *ast)
{
	if (!ast)
		return ;
	free(ast->left);
	free(ast->right);
	free(ast);
}
