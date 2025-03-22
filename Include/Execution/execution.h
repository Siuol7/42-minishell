/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 23:13:23 by tripham           #+#    #+#             */
/*   Updated: 2025/03/23 01:35:19 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

typedef struct s_shell	t_shell;

void	redirect_fd(int from_fd, int to_fd);
void	exec_ast(t_shell *mns, t_ast *ast);

int		handle_signals_default(void);
void	handle_sigint(int signal_val);
void	handle_sigint_heredoc(int signal_val);

void	free_all(t_ast **ast, t_shell **mns);

void	signals_exit_configure(t_shell *mns);
int		signals_initialize(void);
int		signals_configure(int signal_val, void (*handler)(int));

int		update_status(t_shell *mns, int new_status);
void	wait_update(t_shell *mns, pid_t pid);

#endif