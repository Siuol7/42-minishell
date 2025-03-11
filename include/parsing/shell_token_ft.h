/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_token_ft.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:55:24 by caonguye          #+#    #+#             */
/*   Updated: 2025/03/11 23:52:31 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_TOKEN_FT_H

# define SHELL_TOKEN_FT_H

int		ft_skip_space(char *input, int index);
int		ft_skip_dquote(char *input, int index);
int		ft_skip_word(char *input, int index);
int		ft_split_word(char *in, char **res, int *start, int *i);
int		ft_split_dquote(char *in, char **res, int *start, int *i);

#endif