/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:06:39 by tripham           #+#    #+#             */
/*   Updated: 2025/03/18 19:07:39 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
void	redirect_fd(int from_fd, int to_fd)
{
	if (dup2(from_fd, to_fd) == -1)
	{
		perror("dup2 failed");
		close(from_fd);
		exit(EXIT_FAILURE);
	}
	close(from_fd);
}