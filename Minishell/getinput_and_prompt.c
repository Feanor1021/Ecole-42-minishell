#include "minishell.h"

char *ft_create_prompt(void)
{
    char *prompt;

    prompt = ft_strdup("minishell # ");
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