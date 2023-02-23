#include "minishell.h"

static t_pipeline	*parsepipeline(t_token **tokens, int start, int end)
{
    t_pipeline *ret;

    if((char)tokens[0]->data[0] == '|')
    {
        ft_syntaxerror(*tokens);
        return (NULL);
    }
    ret = ft_calloc(sizeof(t_pipeline), 1);
    ret->commands = ft_parsecommands(tokens, start, end);
    // if(!ret->commands)
    // {
    //     ft_freearr_command(ret->commands);
    //     free(ret);
    //     return (NULL);
    // }
}


static int findend(t_token **tokens, int start, int end)
{
    while (start < end && tokens[start])
        start++;
    return (start);
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