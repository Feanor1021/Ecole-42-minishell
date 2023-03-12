#include "minishell.h"

int ft_runcommand(t_command *cmd)
{
    pid_t pid;

    ft_pars_quote(cmd);
    if (is_built_in(cmd->command))
        pid = init_built_in(cmd);

    return pid;
}

void run_commands(t_command **cmds)
{
    int i;
    pid_t last_command;

    ft_connect_pipes(cmds);
    i = 0;
    while (cmds[i] && !g_shell->e_flag)
        last_command = ft_runcommand(cmds[i++]);
    ft_close_pipes();
}