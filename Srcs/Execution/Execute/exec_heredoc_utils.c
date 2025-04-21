/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 14:45:27 by tripham           #+#    #+#             */
/*   Updated: 2025/04/22 01:00:54 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exp_check_quotes(t_shell *mns, char **limiter)
{
	char	c;
	char	*temp;

	if (!limiter || !*limiter)
		return (0);
	c = **limiter;
	temp = lx_qmarks_eli(mns, *limiter, 0, 0);
	free(*limiter);
	*limiter = temp;
	if (c == '\'' || c == '\"')
		return (1);
	return (0);
}

int	exp_hd_check_nl(char *limiter)
{
	int	i;

	i = 0;
	if (!limiter)
		return (0);
	while (limiter[i])
	{
		if (limiter[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	which_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			return ('\'');
		else if (str[i] == '\"')
			return ('\"');
		i++;
	}
	return (0);
}

char	*heredoc_filename(int index)
{
	char	*filename;
	char	*index_str;

	index_str = ft_itoa(index);
	if (index_str == NULL)
	{
		perror("heredoc_filename failed");
		return (NULL);
	}
	filename = ft_strjoin(".heredoc_tmp_", index_str);
	if (filename == NULL)
	{
		free(index_str);
		perror("heredoc_filename failed");
		return (NULL);
	}
	free(index_str);
	return (filename);
}

static int	get_cmd_group_index(t_shell *mns, t_cmd *cmd)
{
	int	i = 0;

	while (i < mns->group_cnt)
	{
		if (&mns->cmd_group[i] == cmd)
			return (i);
		i++;
	}
	return (-1);
}

void clean_heredoc_files(t_shell *mns, t_cmd *cmd)
{
	int		i;
	char	*file_name;
	int		group_index;

	group_index = get_cmd_group_index(mns, cmd);
	if (group_index == -1)
		return ;
	i = 0;
	while (i < cmd->heredoc_cnt)
	{
		file_name = heredoc_filename(group_index * 100 + i);
		unlink(file_name);
		free(file_name);
		free(cmd->heredoc[i]);
		cmd->heredoc[i] = NULL;
		i++;
	}
}
