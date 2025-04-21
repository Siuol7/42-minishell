/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 14:45:27 by tripham           #+#    #+#             */
/*   Updated: 2025/04/21 21:21:11 by tripham          ###   ########.fr       */
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
	if (c == '\'' || c == '\"')
	{
		temp = lx_qmarks_eli(mns, *limiter, 0, 0);
		free(*limiter);
		*limiter = temp;
		return (1);
	}
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

void clean_heredoc_files(t_shell *mns, t_cmd *cmd)
{
	int		i;
	int		heredoc_id;
	char	*file_name;
	int		group_index;

	group_index = get_cmd_group_index(mns, cmd);
	if (group_index == -1)
		return ;

	i = 0;
	heredoc_id = 0;
	while (i < cmd->in_cnt)
	{
		if (cmd->in[i].type == RD_HEREDOC)
		{
			file_name = heredoc_filename(group_index * 100 + heredoc_id);
			if (file_name)
			{
				unlink(file_name);
				free(file_name);
			}
			heredoc_id++;
		}
		i++;
	}
}
