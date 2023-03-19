#include "minishell.h"

void ft_free_command(t_command *cmd)
{
    if (cmd)
    {
        if (cmd->out != 1)
            close(cmd->out);
        if (cmd->in != 0)
            close(cmd->in);
        ft_free_arr_str(cmd->arguments);
        ft_free_arr_str(cmd->heredocsteps);
        ft_free_arr((void **)cmd->redirections, (void (*)(void *))ft_free_stream);
        free(cmd->command);
        free(cmd);
    }
}

void ft_free_pipeline(t_pipeline *pipe)
{
    if (pipe)
        ft_free_arr_command(pipe->commands);
    free(pipe);
}

void ft_freetoken(t_token *token)
{
    if (token)
    {
        free(token->data);
        free(token);
    }
}

void ft_free_arr_token(t_token **tokens)
{
    ft_free_arr((void **)tokens, (void (*)(void *))ft_freetoken);
}
