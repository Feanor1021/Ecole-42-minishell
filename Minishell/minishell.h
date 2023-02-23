#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "42-Libft/libft.h"

typedef struct s_shell
{
    int return_code;
    int e_flag;
    int i_flag;
    int p_count;
    int *openedpips;
    char **env;
} t_shell;

extern t_shell *g_shell;

extern int a;

int ft_arrlen(void **arr);
char **ft_copyarr_str(char **arr);

void ft_connectsignals();
void ft_signalhandler(int sig);

char *ft_getinput(void);
char *ft_create_prompt(void);

#endif