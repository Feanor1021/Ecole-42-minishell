#include "minishell.h"

int ft_runcommand(t_command *cmd)
{
    pid_t pid;

    ft_pars_quote(cmd);
}

void run_commands(t_command **cmds)
{
    int i;
    pid_t last_command;

    ft_connectpipes();
    i = 0;
    while (cmds[i] && !g_shell->e_flag)
        last_command = ft_runcommand(cmds[i++]);
    ft_closepipes();
}