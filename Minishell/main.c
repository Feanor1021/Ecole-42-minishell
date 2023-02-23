#include "minishell.h"

t_shell *g_shell;

static void init_g_shell(char **env)
{
    g_shell = ft_calloc(sizeof(t_shell), 1);
    g_shell->env = ft_copyarr_str(env);
}

static void miniloop(void)
{
    char *input;

    while (!g_shell->e_flag)
    {
        input = ft_getinput();
        // if (!input)
        //     break;
        // ft_execline(input);
        // free(input);
    }
}

int main(int argc, char **argv, char **env)
{
    int exitcode;

    (void)argv;
    (void)argc;
    (void)exitcode;
    init_g_shell(env);
    ft_connectsignals();
    if (argc == 1)
        miniloop();
    // exitcode = g_shell->return_code;
    // return(exitcode);
}