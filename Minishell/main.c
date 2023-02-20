#include "minishell.h"

t_shell *g_shell;

static void init_g_shell(char **env)
{
    g_shell = ft_calloc(sizeof(t_shell), 1);
    g_shell->env = ft_copyarr_str(env);

    int i = 0;
    while(g_shell->env[i])
        printf("%s\n", g_shell->env[i++]);
    exit(0);
}

void ft_signalhandler()
{
    printf("içeri");
    exit(1);
}

void ft_connectsignals()
{
    signal(SIGINT, ft_signalhandler);
    signal(SIGQUIT, SIG_IGN);
}

int main(int argc, char **argv, char **env)
{
    int exitcode;

    (void)argv;
    (void)argc;
    (void)exitcode;
    init_g_shell(env);
    // ft_connectsignals();
    // if(argc == 1)
    //     miniloop();
    // exitcode = g_shell->return_code; 
    // return(exitcode);
}