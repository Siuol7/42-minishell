# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/08 11:57:46 by caonguye          #+#    #+#              #
#    Updated: 2025/03/09 05:01:27 by caonguye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= minishell
CC		:= gcc
FLAG	:= -Wall -Werror -Wextra -g -O3

# Additional libft paths
LIBFT_DIR		:= ./library/libft
LIBFT			:= $(LIBFT_DIR)/libft.a

INCLUDE			:= -I $(LIBFT_DIR) ./include/

# PARSING
PARSING_SRC		:=	./srcs/parsing

LEXER_DIR		:=	$(PARSING_SRC)/Lexer

LEXER_C			:=	ft_split_token.c		\
					shell_token_gen.c

SRCS			:= 	main.c										\
					parsing/implement.c							\
					$(addprefix ${PARSING_SRC}/, ${LEXER_C})

OBJS           :=	${SRCS:.c=.o}

all:    ${LIBFT} ${NAME}

%.o:	%.c
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
		@${CC} ${FLAG} -o $@ -c $< ${INCLUDE}

${NAME}	:	${OBJS} ${LIBFT}
		@${CC} ${OBJS} ${LIBFT} -o ${NAME}

${LIBFT}	:
		@$(MAKE) -s -C ${LIBFT_DIR}

clean    :
		@rm -f ${OBJS}
		@$(MAKE) -s -C ${LIBFT_DIR} clean

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

re    : fclean all

.PHONY: all clean fclean re