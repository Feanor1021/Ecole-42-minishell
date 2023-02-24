#include "minishell.h"

void *error_occured(t_command **commands, t_token *token)
{
    ft_free_arr_command(commands);
    if (token)
        ft_syntaxerror(token);
    return NULL;
}