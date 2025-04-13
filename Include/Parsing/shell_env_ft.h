/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_env_ft.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 01:22:16 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/13 22:57:32 by caonguye         ###   ########.fr       */
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
	int	id;
	int	ls;
	int	rs;
}	t_sort;

typedef struct s_point
{
	int	start;
	int	end;
}	t_point;

char	**env_sorting(t_shell *mns);
int		merge_sort(char **env, int left, int right);

//EXPANSION
int		exp_validation(char *key);
void	exp_generate(t_shell *mns);
void	exp_check_open(char c, char *open);
char	*exp_getkey(t_shell *mns, char *str, int *i);
char	*exp_new_strdup(const char *s);
void	exp_expand(t_shell *mns, char **key, char open);
#endif