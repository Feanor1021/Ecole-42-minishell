#include "minishell.h"

static void del_env(char *del)
{
    int i;
    int j;
    int index_of_del;
    int tot_len_env;
    char **new_env;

    index_of_del = get_env_index(del);
    if (index_of_del == -1)
        return;
    tot_len_env = ft_arrlen((void **)g_shell->env);
    new_env = ft_calloc(sizeof(char *), tot_len_env);
    i = -1;
    j = 0;
    while (g_shell->env[++i])
    {
        if (index_of_del == i)
            j++;
        new_env[i] = g_shell->env[i];
    }
    free(g_shell->env[index_of_del]);
    free(g_shell->env);
    g_shell->env = new_env;
}

int ft_unset(t_command *cmd)
{
    int i;

    i = -1;
    while (cmd->arguments[++i])
    {
        if (env_check(cmd->arguments[i]))
            del_env(cmd->arguments[i]);
        else
        {
            ft_putstr_fd("bash: unset: '", 2);
            ft_putstr_fd(cmd->arguments[i], 2);
            ft_putendl_fd("':not a valid identifier", 2);
        }
    }
    return 0;
}