# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 16:22:44 by fyardimc          #+#    #+#              #
#    Updated: 2023/03/29 16:22:46 by fyardimc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_END		=	\e[0m
_BOLD		=	\e[1m
_UNDER		=	\e[4m
_REV		=	\e[7m
_GREY		=	\e[30m
_RED		=	\e[31m
_GREEN		=	\e[32m
_YELLOW		=	\e[33m
_BLUE		=	\e[34m
_PURPLE		=	\e[35m
_CYAN		=	\e[36m
_WHITE		=	\e[37m
_IGREY		=	\e[40m
_IRED		=	\e[41m
_IGREEN		=	\e[42m
_IYELLOW	=	\e[43m
_IBLUE		=	\e[44m
_IPURPLE	=	\e[45m
_ICYAN		=	\e[46m
_IWHITE		=	\e[47m

NAME = minishell

SRC := $(shell find src -name '*.c')

CC = gcc

DIR_OBJS = $(SRC:%.c=./obj/%.o)

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

LREADLINE = -L${HOME}/readline/8.2.1/lib -lreadline

INCLUDE = -I${HOME}/readline/8.2.1/include/

.PHONY : all clean fclean re bonus

all : $(NAME)

$(NAME) : $(DIR_OBJS)
	@make -C libft
	@printf "\033[K\r$(_GREEN) All files compiled into 'DIR_OBJS'. $(_END)✅\n"
	@$(CC) $(CFLAG)  $(DIR_OBJS) $(LREADLINE) -o $(NAME) $(LIBFT) -I ./include/minishell.h -g
	@printf "\033[K\r$(_GREEN) Executable '$(NAME)' created. $(_END)✅\n"

./obj/%.o : %.c
	@mkdir -p $(shell dirname $@)
	@printf "\033[K\r $(_YELLOW)Compiling $< $(_END)⌛ "
	@$(CC) $(CFLAG) $(INCLUDE) -I ./include -c $< -o $@

clean :
	@make clean -C libft
	@printf "\033[K\r$(_RED) '"$(DIR_OBJS)"' has been deleted. $(_END)🗑️\n"
	@rm -rf  obj *.o

fclean :
	@make fclean -C libft
	@rm -rf  obj *.o $(NAME)
	@printf "\033[K\r$(_RED) '"$(NAME)"' has been deleted. $(_END)🗑️\n"


re : fclean $(NAME)
