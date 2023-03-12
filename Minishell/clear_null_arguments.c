#include "minishell.h"

static void remove_nulls(t_command *cmd, int total_zero)
{
    int i;
    int j;
    int len;
    char **temp;

    len = ft_arrlen((void **)cmd->arguments);
    temp = ft_calloc(sizeof(char *), len - total_zero + 1);
    j = 0;
    i = -1;
    while (cmd->arguments && cmd->arguments[++i])
    {
        if (ft_strlen(cmd->arguments[i]) == 0)
        {
            j++;
            free(cmd->arguments[i]);
        }
        else
            temp[i - j] = cmd->arguments[i];
    }
    free(cmd->arguments);
    cmd->arguments = temp;
}

void clean_null_arguments(t_command *cmd)
{
    int i;
    int total_zero;

    i = -1;
    total_zero = 0;
    while (cmd->arguments && cmd->arguments[++i])
        if (ft_strlen(cmd->arguments[i]) == 0)
            total_zero++;
    remove_nulls(cmd, total_zero);
}