#include "minishell.h"

void *error_command_arr(t_command **commands, t_token *token)
{
    ft_free_arr_command(commands);
    if (token)
        ft_syntaxerror(token);
    return NULL;
}

void *error_command(t_command *cmd)
{
    ft_free_command(cmd);
    return NULL;
}

void *error_pipeline(t_pipeline *pipes, t_token *token)
{
    ft_free_pipeline(pipes);
    if (token)
        ft_syntaxerror(token);
    return NULL;
}