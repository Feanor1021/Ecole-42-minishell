#include "minishell.h"

static int run_built_in(t_command *cmd)
{
    if (ft_strcmp(BT_ENV, cmd->command) == 0)
        return (ft_env(cmd));
    // else if (ft_strcmp(BT_CD, cmd->command) == 0)
    //     return (ft_cd(cmd));
    else if (ft_strcmp(BT_EXIT, cmd->command) == 0)
        return (ft_exit(cmd));
    // else if (ft_strcmp(BT_EXPORT, cmd->command) == 0)
    //     return (ft_export(cmd));
    // else if (ft_strcmp(BT_UNSET, cmd->command) == 0)
    //     return (ft_unset(cmd));
    else if (ft_strcmp(BT_ECHO, cmd->command) == 0)
        return (ft_echo(cmd));
    else if (ft_strcmp(BT_PWD, cmd->command) == 0)
        return (ft_pwd(cmd));
    return (127);
}

int init_built_in(t_command *cmd)
{
    pid_t pid;

    g_shell->return_code = run_built_in(cmd);
    return (-1);
}
