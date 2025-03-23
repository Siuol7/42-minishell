# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/08 11:57:46 by caonguye          #+#    #+#              #
#    Updated: 2025/03/23 02:49:32 by tripham          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= minishell
CC		:= gcc
FLAG	:= -Wall -Werror -Wextra -g -O3
LFLAG	:=	-lreadline


# Additional libft paths
LIBFT_DIR		:= ./Library/libft
LIBFT			:= $(LIBFT_DIR)/libft.a
FT_PRINTF_DIR	:= ./Library/ft_printf_fd
PRINTF			:= $(FT_PRINTF_DIR)/libftprintf.a

HEADER			:= ./Include/Main

INCLUDE			:= -I $(LIBFT_DIR) -I $(FT_PRINTF_DIR) -I $(HEADER)

#MAIN
MAIN_SRC		:=	./Srcs/Main

MAIN_C			:=	main.c					\
					shell_implement.c		\
					shell_input.c			\
					shell_init.c			\
					bad_allocation.c		\
					shell_clean.c

# PARSING
PARSING_SRC		:=	./Srcs/Parsing

# Lexer
LEXER_DIR		:=	$(PARSING_SRC)/Lexer

LEXER_C			:=	shell_token_gen.c	\
					lx_token_split.c	\
					lx_split_utils.c		\
					lx_cmd_group_utils.c	\
					lx_classify_utils.c

#	Env
ENV_DIR			:= $(PARSING_SRC)/Environment

ENV_C			:= env_gen.c

# Execution
EXECUTION_SRC	:=	./Srcs/Execution

# AST
AST_DIR			:=	$(EXECUTION_SRC)/Ast

# Signals
SIGNAL_DIR		:=	$(EXECUTION_SRC)/Signals

# Execute
EXECUTE_DIR		:=	$(EXECUTION_SRC)/Execute

AST_C			:=	ast_init.c			\
					ast_utils.c			\
					ast_root_init.c

SRCS			:= 	$(addprefix ${MAIN_SRC}/,		${MAIN_C})		\
					$(addprefix ${LEXER_DIR}/, 		${LEXER_C})		\
					$(addprefix ${ENV_DIR}/,		${ENV_C})

EXECUTE_C		:=	exec_ast.c		\
					exec_utils.c	\
					exec_cmd_check.c

SIGNAL_C		:=	handle_signals_default.c		\
					signals_initialize.c

SRCS			:= 	$(addprefix ${MAIN_SRC}/,		${MAIN_C})				\
					$(addprefix ${LEXER_DIR}/, 		${LEXER_C})				\
					$(addprefix ${AST_DIR}/,		${AST_C})				\
					$(addprefix ${EXECUTE_DIR}/,	${EXECUTE_C})			\
					$(addprefix ${SIGNAL_DIR}/,		${SIGNAL_C})

OBJS           :=	${SRCS:.c=.o}

all:    ${LIBFT} ${PRINTF} ${NAME}

%.o:%.c
		@${CC} ${FLAG} ${INCLUDE} -o $@ -c $<

${NAME}	:	${OBJS} ${LIBFT} ${PRINTF}
		@printf "\033[1;32m💻Launching"
		@for i in 1 2 3; do \
			printf "\033[0;32m."; sleep 0.3; \
		done; \
		for i in 1 2 3; do \
			printf "\b \b"; sleep 0.3; \
		done; \
		for i in 1 2 3; do \
			printf "\033[0;32m."; sleep 0.3; \
		done; \
		for i in 1 2 3; do \
			printf "\b \b"; sleep 0.3; \
		done; \
		printf "\033[0m\n"
		@${CC} ${OBJS} ${LIBFT} ${PRINTF} ${FLAG} ${LFLAG} -o ${NAME}

${LIBFT}	:
		@$(MAKE) -s -C ${LIBFT_DIR}

${PRINTF}	:
		@$(MAKE) -s -C ${FT_PRINTF_DIR}

clean    :
		@rm -f ${OBJS}
		@$(MAKE) -s -C ${LIBFT_DIR} clean
		@$(MAKE) -s -C ${FT_PRINTF_DIR} clean

fclean   : clean
		@printf "\033[1;32m🧹️Cleaning"
		@for i in 1 2 3; do \
			printf "\033[0;32m."; sleep 0.3; \
		done; \
		for i in 1 2 3; do \
			printf "\b \b"; sleep 0.3; \
		done; \
		for i in 1 2 3; do \
			printf "\033[0;32m."; sleep 0.3; \
		done; \
		for i in 1 2 3; do \
			printf "\b \b"; sleep 0.3; \
		done; \
		printf "\033[0m\n"
		@echo "\033[1;32mDone🎉"
		@rm -rf ${NAME}
		@$(MAKE) -s -C ${LIBFT_DIR} fclean
		@$(MAKE) -s -C ${FT_PRINTF_DIR} fclean

re    : fclean all

.PHONY: all clean fclean re