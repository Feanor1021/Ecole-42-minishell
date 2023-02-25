#include "minishell.h"

int ft_parsewordtoken(t_command *cmd, t_token **tokens, int i)
{
    if (!cmd->command)
        cmd->command = ft_strdup(tokens[i]->data);
    ft_add_arr_str(&(cmd->arguments), ft_strdup(tokens[i]->data));
    return (1);
}

// int ft_parsewordtoken(t_command *cmd, t_token **tokens, int i)
// {
//     if (!cmd->command)
//     {
//         cmd->command = ft_strdup(tokens[i]->data);
//         return 1;
//     }
//     ft_add_arr_str(&(cmd->arguments), ft_strdup(tokens[i]->data));
//     return 1;
// }