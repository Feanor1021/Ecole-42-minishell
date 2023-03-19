#include "minishell.h"

int is_alpha_underscore(char c)
{
    if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    return (0);
}

int is_env(char c)
{
    if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        return (1);
    return (0);
}

int is_built_in(char *command)
{
    if (ft_strcmp(BT_ECHO, command) == 0 ||
        ft_strcmp(BT_CD, command) == 0 ||
        ft_strcmp(BT_PWD, command) == 0 ||
        ft_strcmp(BT_EXIT, command) == 0 ||
        ft_strcmp(BT_EXPORT, command) == 0 ||
        ft_strcmp(BT_UNSET, command) == 0 ||
        ft_strcmp(BT_ENV, command) == 0)
        return (1);
    return (0);
}

int is_numeric(char *str)
{
    int i;

    i = 0;
    while (str && str[i])
        if (!ft_isdigit(str[i++]))
            return (0);
    return (1);
}

int is_path(char *file)
{
    if (ft_strncmp("./", file, 2) == 0 ||
        ft_strncmp("/", file, 1) == 0 ||
        ft_strncmp("../", file, 3) == 0)
        return (1);
    return (0);
}
