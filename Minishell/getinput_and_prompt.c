#include "minishell.h"

char *ft_create_prompt(void)
{
    char *prompt;
    char *cwd;
    int len;

    cwd = "minishell # ";
    len = ft_strlen(cwd);
    prompt = ft_calloc(sizeof(char), len + 1);
    ft_memmove(prompt, cwd, len);
    return (prompt);
}

char *ft_getinput(void)
{
    char *input;
    char *prompt;

    prompt = ft_create_prompt();
    input = readline(prompt);
    if (input && *input)
        add_history(input);
    free(prompt);
    return (input);
}