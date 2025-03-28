/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:27:56 by tripham           #+#    #+#             */
/*   Updated: 2025/03/28 04:52:47 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static int	init_child(int *pipe_fd, pid_t *pid)
// {
// 	*pid = fork();
// 	if (*pid == -1)
// 	{
// 		perror("minishell: fork failed");
// 		close(pipe_fd[0]);
// 		close(pipe_fd[1]);
// 		exit(EXIT_FAILURE);
// 	}
// 	return (EXIT_SUCCESS);
// }

// static void	exec_child(t_shell *mns, t_ast *ast, int *pipe_fd, int left)
// {
// 	handle_signals_default();
// 	if (left)
// 	{
// 		close(pipe_fd[0]);
// 		redirect_fd(pipe_fd[1], STDOUT_FILENO);
// 		exec_ast(mns, ast->left);
// 	}
// 	else
// 	{
// 		close(pipe_fd[1]);
// 		redirect_fd(pipe_fd[0], STDIN_FILENO);
// 		exec_ast(mns, ast->right);
// 	}
// 	free_all(&ast, &mns);
// 	exit(mns->exitcode);
// }

// static void	exec_pipe(t_shell *mns, t_ast *ast)
// {
// 	int		pipe_fd[2];
// 	pid_t	pid[2];

// 	if (pipe(pipe_fd) == -1)
// 	{
// 		perror("minishell: pipe failed");
// 		exit(EXIT_FAILURE);
// 	}
// 	if (init_child(pipe_fd, &pid[0]) == EXIT_FAILURE)
// 		return ;
// 	if (pid[0] == 0)
// 		exec_child(mns, ast, pipe_fd, 1);
// 	if (init_child(pipe_fd, &pid[1]) == EXIT_FAILURE)
// 		return ;
// 	if (pid[1] == 0)
// 		exec_child(mns, ast, pipe_fd, 0);
// 	close(pipe_fd[0]);
// 	close(pipe_fd[1]);
// 	wait_update(mns, pid[1]);
// }

// static void exec_left_child(t_shell *mns, t_ast *ast, int *pipe_fd) 
// {
// 	handle_signals_default();
// 	(void) ast;
//     char *command_path;

//     close(pipe_fd[0]);
//     redirect_fd(pipe_fd[1], STDOUT_FILENO);
//     command_path = found_command_path(mns, mns->cmd[0].cmd_gr[0]);
//     if (!command_path) {
//         free_all(&ast, &mns);
//         exit(127);
//     }
//     execve(command_path, mns->cmd[0].cmd_gr, mns->env);
//     perror("execve left failed");
//     exit(127);
// }

// static void exec_right_child(t_shell *mns, t_ast *ast, int *pipe_fd) 
// {
// 	handle_signals_default();
// 	(void) ast;
//     char *command_path;

//     close(pipe_fd[1]);
//     redirect_fd(pipe_fd[0], STDIN_FILENO);
//     command_path = found_command_path(mns, mns->cmd[1].cmd_gr[0]);
//     if (!command_path) {
//         free_all(&ast, &mns);
//         exit(127);
//     }
//     execve(command_path, mns->cmd[1].cmd_gr, mns->env);
//     perror("execve right failed");
//     exit(127);
// }

// static void exec_pipe(t_shell *mns, t_ast *ast) 
// {
// 	int pipe_fd[2];
//     pid_t pid[2];

//     if (pipe(pipe_fd) == -1) {
//         perror("minishell: pipe failed");
//         exit(EXIT_FAILURE);
//     }
//     pid[0] = fork();
//     if (pid[0] == -1) {
//         perror("minishell: fork failed");
//         exit(EXIT_FAILURE);
//     }
//     if (pid[0] == 0)
//         exec_left_child(mns, ast, pipe_fd);

//     pid[1] = fork();
//     if (pid[1] == -1) {
//         perror("minishell: fork failed");
//         exit(EXIT_FAILURE);
//     }
//     if (pid[1] == 0)
//         exec_right_child(mns, ast, pipe_fd);

//     close(pipe_fd[0]);
//     close(pipe_fd[1]);
//     wait_update(mns, pid[0]);
//     wait_update(mns, pid[1]);
// }


// void	exec_ast(t_shell *mns, t_ast *ast)
// {
//     if (ast->token.type == OP_PIPE)
//         exec_pipe(mns, ast);
//     else if (ast->left)
//         exec_ast(mns, ast->left);
//     else if (ast->right)
//         exec_ast(mns, ast->right);
//     else if (ast->token.type == CMD)
//         exec_cmd(mns, ast->token);
//     // while (wait(NULL) > 0)
//     //     ;
// }


/* Hàm xử lý tiến trình con bên trái của pipe */
static void exec_left_child(t_shell *mns, t_ast *ast, int *pipe_fd) {
	handle_signals_default();
	(void) ast;  // Đánh dấu ast là không dùng đến

    char *command_path;

    /* Trong tiến trình con, không cần xử lý free hay restore tài nguyên dùng chung */
    close(pipe_fd[0]);                     /* Đóng đầu đọc của pipe */
    redirect_fd(pipe_fd[1], STDOUT_FILENO);  /* Chuyển STDOUT sang pipe_fd[1] */

    /* Sử dụng t_cmd đã được tạo ra từ parsing cho lệnh bên trái */
    command_path = found_command_path(mns, mns->cmd[0].cmd_gr[0]);
    if (!command_path) {
        exit(127);
    }
    execve(command_path, mns->cmd[0].cmd_gr, mns->env);
    perror("execve left failed");
    exit(127);
}

/* Hàm xử lý tiến trình con bên phải của pipe */
static void exec_right_child(t_shell *mns, t_ast *ast, int *pipe_fd) {
	handle_signals_default();
	(void) ast;  // Đánh dấu ast là không dùng đến

    char *command_path;

    close(pipe_fd[1]);                     /* Đóng đầu ghi của pipe */
    redirect_fd(pipe_fd[0], STDIN_FILENO);   /* Chuyển STDIN từ pipe_fd[0] */

    /* Sử dụng t_cmd cho lệnh bên phải */
    command_path = found_command_path(mns, mns->cmd[1].cmd_gr[0]);
    if (!command_path) {
        exit(127);
    }
    execve(command_path, mns->cmd[1].cmd_gr, mns->env);
    perror("execve right failed");
    exit(127);
}

/* Hàm exec_pipe sử dụng t_cmd để thực thi pipeline */
static void exec_pipe(t_shell *mns, t_ast *ast) {
	handle_signals_default();
    int pipe_fd[2];
    pid_t pid[2];

    if (pipe(pipe_fd) == -1) {
        perror("minishell: pipe failed");
        exit(EXIT_FAILURE);
    }
    /* Fork tiến trình con cho nhánh trái */
    pid[0] = fork();
    if (pid[0] == -1) {
        perror("minishell: fork failed");
        exit(EXIT_FAILURE);
    }
    if (pid[0] == 0)
        exec_left_child(mns, ast, pipe_fd);

    /* Fork tiến trình con cho nhánh phải */
    pid[1] = fork();
    if (pid[1] == -1) {
        perror("minishell: fork failed");
        exit(EXIT_FAILURE);
    }
    if (pid[1] == 0)
        exec_right_child(mns, ast, pipe_fd);

    /* Trong tiến trình cha: đóng pipe và chờ các tiến trình con kết thúc */
    close(pipe_fd[0]);
    close(pipe_fd[1]);
    wait_update(mns, pid[0]);
    wait_update(mns, pid[1]);
}

/* Hàm exec_ast đã được cập nhật */
void exec_ast(t_shell *mns, t_ast *ast) {
    if (!ast)
        return;

    if (ast->token.type == OP_PIPE)
        exec_pipe(mns, ast);
    else if (ast->left || ast->right) {
        if (ast->left)
            exec_ast(mns, ast->left);
        if (ast->right)
            exec_ast(mns, ast->right);
    } else if (ast->token.type == CMD) {
        exec_cmd(mns, ast->token);
    }
    /* Không dùng vòng lặp while(wait(NULL)>0) ở đây để không can thiệp redirection của shell bên ngoài */
}
