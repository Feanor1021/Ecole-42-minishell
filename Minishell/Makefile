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

SRC =	main.c minishell_utils1.c signals.c getinput_and_prompt.c gettokens.c gettokens_utils.c execline.c parsepipelines.c parsecommands.c syntax_errors.c \
		add_array.c parsecommands_utils.c free_functions.c free_functions_2.c errors.c run_pipelines.c heredoc.c run_commands.c pars_quote_utils.c pars_quote.c connection_of_pipes.c \

CC = gcc

DIR_OBJS = $(SRC:%.c=./obj/%.o)

CFLAGS = -Wall -Wextra -Werror

LIBFT = 42-Libft/libft.a

LREADLINE = -L${HOME}/readline/lib -lreadline

INCLUDE = -I${HOME}/readline/include/

.PHONY : all clean fclean re bonus

all : $(NAME)

$(NAME) : $(DIR_OBJS)
	@make -C 42-Libft
	@printf "\033[K\r$(_GREEN) All files compiled into 'DIR_OBJS'. $(_END)✅\n"
	@$(CC) $(CFLAG)  $(DIR_OBJS) $(LREADLINE) -o $(NAME) $(LIBFT) -I ./minishell.h -g
	@printf "\033[K\r$(_GREEN) Executable '$(NAME)' created. $(_END)✅\n"

./obj/%.o : %.c
	@mkdir -p $(shell dirname $@)
	@printf "\033[K\r $(_YELLOW)Compiling $< $(_END)⌛ "
	@$(CC) $(CFLAG) $(INCLUDE) -c $< -o $@

clean :
	@make clean -C 42-Libft
	@printf "\033[K\r$(_RED) '"$(DIR_OBJS)"' has been deleted. $(_END)🗑️\n"
	@rm -rf  obj *.o

fclean :
	@make fclean -C 42-Libft
	@rm -rf  obj *.o $(NAME)
	@printf "\033[K\r$(_RED) '"$(NAME)"' has been deleted. $(_END)🗑️\n"


re : fclean $(NAME)
