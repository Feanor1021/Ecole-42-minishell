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

SRC = 	ft_closepipes.c         ft_export.c             ft_get_key.c            ft_initredirects.c      ft_onlyexport.c         ft_puterrno.c           ft_strlenchr.c	\
		ft_connectio.c          ft_extendarr.c          ft_get_value.c          ft_initsubshell.c       ft_open_reds.c          ft_puterrno_msg.c       ft_syntaxerror.c	\
		ft_addarr.c             ft_connectpipes.c       ft_filexists.c          ft_getenv.c             ft_insertarr.c          ft_parse_quote.c        ft_pwd.c	\
		ft_addarr_command.c     ft_connectsignals.c     ft_findinpath.c         ft_getenvindex.c        ft_is_env.c             ft_parse_quote_utils.c  ft_readfile.c	\
		ft_addarr_int.c         ft_copyarr_str.c        ft_freearr.c            ft_getinput.c           ft_isalpha_underscore.c ft_parsecommand.c       ft_replace.c	\
		ft_addarr_pipeline.c    ft_create_prompt.c      ft_freearr_command.c    ft_getnexttoken.c       ft_isbuiltin.c          ft_parsecommands.c      ft_runbuiltin.c	\
		ft_addarr_str.c         ft_createtoken.c        ft_freearr_pipeline.c   ft_getonechartoken.c    ft_isdelimitter.c       ft_parseheredoc.c       ft_runcommand.c	\
		ft_addarr_stream.c      ft_delenv.c             ft_freearr_str.c        ft_gettokens.c          ft_isfile.c             ft_parsepipelines.c     ft_runcommands.c \
		ft_addarr_token.c       ft_echo.c               ft_freearr_token.c      ft_gettwochartoken.c    ft_islogic.c            ft_parseredinput.c      ft_runpipelines.c \
		ft_arrlen.c             ft_env.c                ft_freecommand.c        ft_getwordtoken.c       ft_isnumeric.c          ft_parseredoutput.c     ft_setenv.c	\
		ft_cd.c                 ft_env_check.c          ft_freepipeline.c       ft_heredoc.c            ft_ispath.c             ft_parsesubshell.c      ft_signalhandler.c \
		ft_clean_array.c        ft_execline.c           ft_freestream.c         ft_initbuiltin.c        ft_isquote.c            ft_parsewordtoken.c     ft_skipbrackets.c \
		ft_clearsignals.c       ft_exit.c               ft_freetoken.c          ft_initprocess.c        ft_isspace.c            ft_puterrln.c           ft_strappend.c \
		ft_take_env.c			ft_unset.c				minishell.c				ft_wilcard_parse.c		ft_wilcard_parse_utils.c ft_wilcard_parse_utils2.c \
		ft_wilcard_parse_utils3.c ft_opendir.c          ft_first_star.c         ft_arrfix.c

CC = gcc

DIR_OBJS = $(SRC:%.c=./obj/%.o)

CFLAG = -Wall -Wextra -Werror

LIBFT = 42-Libft/libft.a

LREADLINE = -L${HOME}/readline/lib -lreadline

INCLUDE = -I${HOME}/readline/include/

MAKE = make

MKDIR = mkdir

all : $(NAME)

$(NAME) : $(DIR_OBJS)
	@$(MAKE) -C 42-Libft
	@printf "make 42-Libft"
	@printf "\033[K\r$(_GREEN) All files compiled into 'DIR_OBJS'. $(_END)✅\n"
	@$(CC) $(CFLAG)  $(DIR_OBJS) $(LREADLINE) -o $(NAME) $(LIBFT)
	@printf "\033[K\r$(_GREEN) Executable '$(NAME)' created. $(_END)✅\n"

obj/%.o : ./%.c
	@$(MKDIR) -p $(shell dirname $@)
	@printf "\033[K\r $(_YELLOW)Compiling $< $(_END)⌛ "
	@$(CC) $(CFLAG)  $(INCLUDE) -c $< -o $@

re : fclean all

clean :
	@make clean -C 42-Libft
	@printf "\033[K\r$(_RED) '"$(DIR_OBJS)"' has been deleted. $(_END)🗑️\n"
	@rm -rf  obj *.o

fclean :
	@make fclean -C 42-Libft
	@rm -rf  obj *.o $(NAME)
	@printf "\033[K\r$(_RED) '"$(NAME)"' has been deleted. $(_END)🗑️\n"

norm :
	norminette

.PHONY: all re clean fclean