#include "minishell.h"

void dbquote_len(char *token, int *end)
{
    int index;

    index = 0;
    *end = -1;
    while (1)
    {
        (*end)++;
        if (token[index] == '"' || !token[index])
            return;
        index++;
    }
}

void singlequote_len(char *token, int *end)
{
    int index;

    index = 0;
    *end = -1;
    while (1)
    {
        (*end)++;
        if (token[index] == '\'' || !token[index])
            return;
        index++;
    }
}