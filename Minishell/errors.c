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

void put_errno(void)
{
    char *msg;

    msg = strerror(errno);
    ft_putstr_fd(msg, 2);
}

void put_errno_msg(char *msg)
{
    ft_putstr_fd("bash: ", 2);
    ft_putstr_fd(msg, 2);
    ft_putstr_fd(": ", 2);
    put_errno();
    ft_putendl_fd("", 2);
}
