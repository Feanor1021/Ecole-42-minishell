#include "minishell.h"

void ft_close_pipes()
{
    int i;

    i = 0;
    while (i < g_shell->pipe_count)
        close(g_shell->opened_pipes[i++]);
    free(g_shell->opened_pipes);
    g_shell->pipe_count = 0;
    g_shell->opened_pipes = NULL;
}

static void connect_pipe(t_command **cmds, int i, int *p)
{
    if (cmds[i - 1] && i - 1 >= 0)
    {
        ft_add_arr_int(&(g_shell->opened_pipes), g_shell->pipe_count++, p[0]);
        cmds[i]->in = p[0];
        pipe(p);
        cmds[i]->out = p[1];
        ft_add_arr_int(&(g_shell->opened_pipes), g_shell->pipe_count++, p[1]);
    }
    else if (i == 0 && cmds[i + 1])
    {
        pipe(p);
        ft_add_arr_int(&(g_shell->opened_pipes), g_shell->pipe_count++, p[1]);
        cmds[i]->out = p[1];
    }
    else if (!cmds[i + 1])
    {
        cmds[i]->in = p[0];
        ft_add_arr_int(&(g_shell->opened_pipes), g_shell->pipe_count++, p[0]);
    }
}

void ft_connect_pipes(t_command **cmd)
{
    int p[2];
    int i;
    int len;

    i = -1;
    len = ft_arrlen((void **)cmd);
    if (len == 1)
        return;
    while (++i < len)
        connect_pipe(cmd, i, p);
}