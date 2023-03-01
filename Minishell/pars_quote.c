#include "minishell.h"

char *ft_pars_quote_first(char *token)
{
    int index;
    char *all_tokens;

    all_tokens = ft_calloc(sizeof(char), 1);
    index = 0;
    while (token[index])
    {
        
    }
}

void ft_pars_quote(t_command *cmd)
{
    int i;

    if (cmd->command)
        cmd->command = ft_pars_quote_first(cmd->command);
    i = 0;
    while (cmd->arguments && cmd->arguments[i])
    {
        cmd->arguments[i] = ft_pars_quote_first(cmd->arguments[i]);
        i++;
    }
    ft_clean_array(cmd);
}