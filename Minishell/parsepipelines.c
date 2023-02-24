#include "minishell.h"

static int findend(t_token **tokens, int start, int end)
{
    while (start < end && tokens[start])
        start++;
    return (start);
}

static t_pipeline *parsepipeline(t_token **tokens, int start, int end)
{
    t_pipeline *ret;

    if ((char)tokens[0]->data[0] == '|')
    {
        ft_syntaxerror(*tokens);
        return (NULL);
    }
    ret = ft_calloc(sizeof(t_pipeline), 1);
    ret->commands = ft_parsecommands(tokens, start, end);
    if (!ret->commands)
    {
        ft_free_arr_command(ret->commands);
        free(ret);
        return (NULL);
    }
    return ret;
}

t_pipeline **ft_parsepipelines(t_token **tokens, int start, int end)
{
    t_pipeline **pipes;
    t_pipeline *pipeline;
    int i;

    pipes = NULL;
    i = start;
    while (i < end)
    {
        i = findend(tokens, i, end);
        pipeline = parsepipeline(tokens, start, i);
    }
}

// int j = 0, k = 0;
// while ((pipeline->commands)[k])
// {
//     j = 0;
//     printf("\n%s\n", (pipeline->commands)[k]->command);
//     while (((pipeline->commands)[k]->arguments)[j])
//     {
//         printf("%s ", ((pipeline->commands)[k]->arguments)[j]);
//         j++;
//     }
//     k++;
// }