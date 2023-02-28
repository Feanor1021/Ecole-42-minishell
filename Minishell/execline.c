#include "minishell.h"

void ft_execline(char *input)
{
    t_token **tokens;
    t_pipeline *pipelines;

    tokens = ft_gettokens(input);
    pipelines = NULL;
    if (tokens)
    {
        pipelines = ft_parsepipelines(tokens, 0, ft_arrlen((void **)tokens));
        if (pipelines)
        {
            ft_runpipelines(pipelines);
            //      ft_freearr_pipelines(pipelines);
        }
        // ft_freearr_token(tokens);
    }
}

// if (tokens)
// {
//     int i = 0;

//     while (tokens[i])
//     {
//         printf("%s %d\n", tokens[i]->data, tokens[i]->type);
//         i++;
//     }
// }