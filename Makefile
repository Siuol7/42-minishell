# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/08 11:57:46 by caonguye          #+#    #+#              #
#    Updated: 2025/03/16 03:09:00 by caonguye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= minishell
CC		:= gcc
FLAG	:= -Wall -Werror -Wextra -g -O3
LFLAG	:=	-lreadline


# Additional libft paths
LIBFT_DIR		:= ./library/libft
LIBFT			:= $(LIBFT_DIR)/libft.a
FT_PRINTF_DIR	:= ./library/ft_printf_fd
PRINTF			:= $(FT_PRINTF_DIR)/libftprintf.a

HEADER			:= ./include/main

INCLUDE			:= -I $(LIBFT_DIR) -I $(FT_PRINTF_DIR) -I $(HEADER)

#MAIN
MAIN_SRC		:=	./srcs/main

MAIN_C			:=	main.c					\
					shell_implement.c		\
					shell_init.c			\
					bad_allocation.c		\
					shell_clean.c

# PARSING
PARSING_SRC		:=	./srcs/parsing

LEXER_DIR		:=	$(PARSING_SRC)/Lexer

LEXER_C			:=	shell_input.c		\
					shell_token_gen.c	\
					ft_token_split.c	\
					split_utils.c		\
					cmd_group_utils.c	\
					classify_utils.c

SRCS			:= 	$(addprefix ${MAIN_SRC}/,		${MAIN_C})				\
					$(addprefix ${LEXER_DIR}/, 		${LEXER_C})

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