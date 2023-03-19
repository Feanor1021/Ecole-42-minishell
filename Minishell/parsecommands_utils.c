#include "minishell.h"

// int ft_parsewordtoken(t_command *cmd, t_token **tokens, int i)
// {
//     if (!cmd->command)
//         cmd->command = ft_strdup(tokens[i]->data);
//     ft_add_arr_str(&(cmd->arguments), ft_strdup(tokens[i]->data));
//     return (1);
// }

int ft_parsewordtoken(t_command *cmd, t_token **tokens, int i)
{
    if (!cmd->command)
        cmd->command = ft_strdup(tokens[i]->data);
    ft_add_arr_str(&(cmd->arguments), ft_strdup(tokens[i]->data));
    return 1;
}

int ft_parse_heredoc(t_command *cmd, t_token **tokens, int *i)
{
    (*i)++;
    if (tokens[*i] && tokens[*i]->type == WORD)
    {
        ft_add_arr_str(&(cmd->heredocsteps), ft_strdup(tokens[*i]->data));
        return (1);
    }
    ft_syntaxerror(tokens[*i]);
    return (0);
}

int ft_parse_input(t_command *cmd, t_token **tokens, int *i)
{
    t_stream *stream;

    stream = ft_calloc(sizeof(t_stream), 1);
    (*i)++;
    if (tokens[*i] && tokens[*i]->type == WORD)
    {
        stream->type = STREAM_IN;
        stream->path = ft_strdup(tokens[*i]->data);
        ft_add_arr_stream(&(cmd->redirections), stream);
        return (1);
    }
    ft_syntaxerror(tokens[*i]);
    ft_free_stream(stream);
    return 0;
}

int ft_parse_output(t_command *cmd, t_token **tokens, int *i)
{
    t_stream *stream;

    stream = ft_calloc(sizeof(t_stream), 1);
    if (tokens[*i]->type == RED_APPEND)
        stream->appendmode = 1;
    (*i)++;
    if (tokens[*i] && tokens[*i]->type == WORD)
    {
        stream->type = STREAM_OUT;
        stream->path = ft_strdup(tokens[*i]->data);
        ft_add_arr_stream(&(cmd->redirections), stream);
        return 1;
    }
    ft_syntaxerror(tokens[*i]);
    ft_free_stream(stream);
    return 0;
}