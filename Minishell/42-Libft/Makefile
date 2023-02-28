NAME = libft.a

SRCS =	ft_atoi.c               ft_isascii.c            ft_lstadd_front.c       ft_lstmap.c             ft_memcpy.c             ft_putnbr_fd.c          ft_strdup.c             ft_strlen.c             ft_strtrim.c \
		ft_bzero.c              ft_isdigit.c            ft_lstclear.c           ft_lstnew.c             ft_memmove.c            ft_putstr_fd.c          ft_striteri.c           ft_strmapi.c            ft_substr.c \
		ft_calloc.c             ft_isprint.c            ft_lstdelone.c          ft_lstsize.c            ft_memset.c             ft_split.c              ft_strjoin.c            ft_strncmp.c            ft_tolower.c \
		ft_isalnum.c            ft_itoa.c               ft_lstiter.c            ft_memchr.c             ft_putchar_fd.c         ft_strchr.c             ft_strlcat.c            ft_strnstr.c            ft_toupper.c \
		ft_isalpha.c            ft_lstadd_back.c        ft_lstlast.c            ft_memcmp.c             ft_putendl_fd.c         ft_strcmp.c             ft_strlcpy.c            ft_strrchr.c			ft_strstr.c \
		ft_isspace.c ft_strcmp.c

OBJS = $(SRCS:%.c=./obj/%.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.PHONY : all clean fclean re bonus

all : $(NAME)

$(NAME) : $(OBJS)
	@ar rcs $(NAME) $(OBJS)

./obj/%.o : %.c
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CFLAGS) -c $^ -o $@

clean :
	@rm -rf $(OBJS) obj *.o

fclean : clean
	@rm -f $(NAME)

re : fclean $(NAME)
