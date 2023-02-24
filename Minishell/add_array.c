#include "minishell.h"

void ft_add_arr(void ***arr, void *new)
{
    void **ret;
    int i;
    int k;

    ret = ft_calloc(sizeof(void *), ft_arrlen((void **)*arr) + 2);
    i = 0;
    k = 0;
    while (*arr && (*arr)[k])
        ret[i++] = (*arr)[k++];
    ret[i] = new;
    free(*arr);
    (*arr) = ret;
}

void ft_add_arr_token(t_token ***arr, t_token *new)
{
    ft_add_arr((void ***)arr, (void *)new);
}

void ft_add_arr_str(char ***arr, char *new)
{
    ft_add_arr((void ***)arr, (void *)new);
}

void ft_add_arr_command(t_command ***arr, t_command *new)
{
    ft_add_arr((void ***)arr, (void *)new);
}