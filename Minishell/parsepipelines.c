#include "minishell.h"

t_pipeline *ft_parsepipelines(t_token **tokens, int start, int end)
{
    t_pipeline *pipes;

    if ((char)tokens[0]->data[0] == '|')
    {
        ft_syntaxerror(*tokens);
        return (NULL);
    }
    pipes = ft_calloc(sizeof(t_pipeline), 1);
    if (!pipes)
        return NULL;
    pipes->commands = ft_parsecommands(tokens, start, end);
    if (!pipes->commands)
    {
        ft_free_arr_command(pipes->commands);
        free(pipes);
        return (NULL);
    }
    if (!pipes)
        return error_pipeline(pipes, NULL);
    return pipes;
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

// static t_pipeline *parsepipeline(t_token **tokens, int start, int end)
// {
//     t_pipeline *ret;

//     if ((char)tokens[0]->data[0] == '|')
//     {
//         ft_syntaxerror(*tokens);
//         return (NULL);
//     }
//     ret = ft_calloc(sizeof(t_pipeline), 1);
//     ret->commands = ft_parsecommands(tokens, start, end);
//     if (!ret->commands)
//     {
//         ft_free_arr_command(ret->commands);
//         free(ret);
//         return (NULL);
//     }
//     return ret;
// }
