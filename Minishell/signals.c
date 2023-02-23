#include "minishell.h"

void ft_signalhandler(int sig)
{
    (void)sig;
    if (g_shell->i_flag)
    {
        printf("\n");
        g_shell->i_flag = 0;
        return;
    }
    g_shell->return_code = 1;
    printf("\n");
    rl_on_new_line();
    rl_replace_line("", 0);
    rl_redisplay();
}

void ft_connectsignals()
{
    signal(SIGINT, ft_signalhandler);
    signal(SIGQUIT, SIG_IGN);
}