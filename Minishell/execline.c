#include "minishell.h"

void ft_execline(char *input)
{
    t_token **tokens;

    tokens = ft_gettokens(input);
    if (tokens)
    {
        int i = 0;

        while (tokens[i])
        {
            printf("%s %d\n", tokens[i]->data, tokens[i]->type);
            i++;
        }
    }
}