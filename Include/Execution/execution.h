/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 23:13:23 by tripham           #+#    #+#             */
/*   Updated: 2025/03/27 20:12:44 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <sys/stat.h> 

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
char	*found_command_path(t_shell *mns, char *cmd);
//Builtin functions
int		exec_cmd_check(t_token token);
void	exec_builtin(t_shell *mns, t_token token);
void	exec_echo(t_shell *mns, t_token token);
void	exec_cd(t_shell *mns, t_token token);
void	exec_pwd(t_shell *mns, t_token token);
void	exec_export(t_shell *mns, t_token token);
void	exec_unset(t_shell *mns, t_token token);
void	exec_env(t_shell *mns, t_token token);
void	exec_exit(t_shell *mns, t_token token);

// Handle_Error
void	handle_execution_error(char *command_path, char **splitted_command);
void	handle_command_error(char **command, char *message);
void	handle_open_error(char *file_name, int which_pipe_end);
void	handle_fork_error(int *pipe);
int		check_error(char *command);
void	exec_error(t_shell *mns, char *cmd_path, char *ms1, char *ms2);



// Execution
void	exec_non_builtin(t_shell *mns, t_token token);
void	exec_cmd(t_shell *mns, t_token token);

// Redirect
int		exec_rd_process(t_ast *token);
int		exec_rd_io(t_shell *mns, t_ast *rd_ast);
#endif