#include "minishell.h"

static t_token *ft_get2chartoken(int *i, enum e_tokentype type, char chr)
{
    char schr[3];

    (*i) += 2;
    schr[0] = chr;
    schr[1] = chr;
    schr[2] = '\0';
    return (ft_createtoken(ft_strdup(schr), type));
}

static t_token *ft_get1chartoken(int *i, enum e_tokentype type, char chr)
{
    char schr[2];

    (*i)++;
    schr[0] = chr;
    schr[1] = '\0';
    return (ft_createtoken(ft_strdup(schr), type));
}

t_token *onechartoken(char *str, int *i)
{
    if (str[*i] == '>' && str[*i + 1] == '>')
        return (ft_get2chartoken(i, RED_APPEND, '>'));
    else if (str[*i] == '<' && str[*i + 1] == '<')
        return (ft_get2chartoken(i, HEREDOC, '<'));
    else if (str[*i] == '|')
        return (ft_get1chartoken(i, PIPE, '|'));
    else if (str[*i] == '>')
        return (ft_get1chartoken(i, RED_CREATE, '>'));
    else if (str[*i] == '<')
        return (ft_get1chartoken(i, RED_INPUT, '<'));
    else
        return NULL;
}

t_token *ft_createtoken(char *data, enum e_tokentype type)
{
    t_token *token;

    token = ft_calloc(sizeof(t_token), 1);
    if (!token)
        return NULL;
    token->data = data;
    token->type = type;
    return (token);
}