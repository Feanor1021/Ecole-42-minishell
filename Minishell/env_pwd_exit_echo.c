#include "minishell.h"

int ft_env(t_command *cmd)
{
    int i;

    i = -1;
    while (g_shell->env[++i])
        if (ft_strchr(g_shell->env[i], '='))
            ft_putendl_fd(g_shell->env[i], cmd->out);
    return (0);
}

int ft_pwd(t_command *cmd)
{
    char buffer[4096];

    getcwd(buffer, 4096);
    ft_putendl_fd(buffer, cmd->out);
    return (0);
}

int ft_exit(t_command *cmd)
{
    (void)cmd;
    g_shell->e_flag = 1;
    if (cmd->in == 0 && cmd->out == 1)
        ft_putendl_fd("exit", 2);
    if (cmd->arguments[1])
    {
        if (is_numeric(cmd->arguments[1]))
            return (ft_atoi(cmd->arguments[1]));
        else
        {
            ft_putstr_fd("bash: exit :", 2);
            ft_putstr_fd(cmd->arguments[1], 2);
            ft_putendl_fd(": numeric argument required", 2);
            return (255);
        }
    }
    return (0);
}

static int echo_n_check(t_command *cmd, int i)
{
    if (cmd->arguments[1][0] != '-')
        return 0;
    while (cmd->arguments[1][i] && cmd->arguments[1][i] == 'n')
        i++;
    if (!cmd->arguments[1][i])
        return 1;
    return 0;
}

int ft_echo(t_command *cmd)
{
    int i;
    int n_flag;

    if (!cmd->arguments[1])
    {
        ft_putstr_fd("\n", cmd->out);
        return (0);
    }
    n_flag = echo_n_check(cmd, 1);
    if (n_flag && !cmd->arguments[2])
        return (0);
    i = 1;
    if (!n_flag)
        i = 0;
    while (cmd->arguments[++i])
    {
        ft_putstr_fd(cmd->arguments[i], cmd->out);
        if (cmd->arguments[i + 1])
            ft_putstr_fd(" ", cmd->out);
    }
    if (cmd->arguments[1] && !n_flag)
        ft_putstr_fd("\n", cmd->out);
    return 0;
}