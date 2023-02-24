#include "minishell.h"

void ft_free_arr(void **arr, void (*f)(void *))
{
    int i;

    i = 0;
    while (arr && arr[i])
        f(arr[i++]);
    free(arr);
}

void ft_free_arr_command(t_command **commands)
{
    ft_free_arr((void **)commands, (void (*)(void *))ft_free_command);
}

void ft_free_arr_str(char **arr)
{
    ft_free_arr((void **)arr, free);
}

void ft_free_stream(t_stream *stream)
{
    if (stream)
    {
        free(stream->path);
        free(stream);
    }
}