#include "minishell.h"

char **ft_copyarr_str(char **arr)
{
    char **ret;
    int i;

    ret = ft_calloc(sizeof(char *), ft_arrlen((void **)arr) + 1);
    i = 0;
    while (arr && *arr)
        ret[i++] = ft_strdup(*arr++);
    return (ret);
}

int ft_arrlen(void **arr)
{
    int len;

    len = 0;
    while (arr && arr[len])
        len++;
    return (len);
}

int ft_isdelimitter(char chr)
{
    return (ft_isspace(chr) ||
            chr == '<' ||
            chr == '>' ||
            chr == '|');
}

int ft_isquote(char chr)
{
    return (chr == '"' || chr == '\'');
}
