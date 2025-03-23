/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_env_ft.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 01:22:16 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/23 23:19:30 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_ENV_FT_H

# define SHELL_ENV_FT_H

//STRUCT FORWARD DECLARATION
typedef struct s_shell	t_shell;

typedef struct s_sort
{
	int	i;
	int	j;
	int	k;
	int	ls;
	int	rs;
}	t_sort;

char	**env_sorting(t_shell *mns);
int		merge_sort(char **env, int left, int right);

#endif