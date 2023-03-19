#include "minishell.h"

static int run_built_in(t_command *cmd)
{
    if (ft_strcmp(BT_ENV, cmd->command) == 0)
        return (ft_env(cmd));
    else if (ft_strcmp(BT_CD, cmd->command) == 0)
        return (ft_cd(cmd));
    else if (ft_strcmp(BT_EXIT, cmd->command) == 0)
        return (ft_exit(cmd));
    else if (ft_strcmp(BT_EXPORT, cmd->command) == 0)
        return (ft_export(cmd));
    else if (ft_strcmp(BT_UNSET, cmd->command) == 0)
        return (ft_unset(cmd));
    else if (ft_strcmp(BT_ECHO, cmd->command) == 0)
        return (ft_echo(cmd));
    else if (ft_strcmp(BT_PWD, cmd->command) == 0)
        return (ft_pwd(cmd));
    return (127);
}

int init_built_in(t_command *cmd)
{
    pid_t pid;

    if (cmd->in != 0 || cmd->out != 1)
    {
        pid = fork();
        if (pid == 0)
        {
            g_shell->e_flag = 1;
            if (!open_redirs(cmd))
                exit(-1);
            g_shell->return_code = run_built_in(cmd);
            ft_close_pipes();
            exit(-1);
        }
        return (pid);
    }
    if (!open_redirs(cmd))
        return -1;
    g_shell->return_code = run_built_in(cmd);
    return (-1);
}
