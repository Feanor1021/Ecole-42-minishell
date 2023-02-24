#include "minishell.h"

static t_command *create_command(void)
{
    // default
    t_command *cmd;

    cmd = ft_calloc(sizeof(t_command), 1);
    cmd->in = 0;
    cmd->out = 1;
    return (cmd);
}

int parsetoken(t_token **tokens, int *start, int end, t_command *cmd)
{
    if (*start < end && tokens[*start]->type == WORD && !ft_parsewordtoken(cmd, tokens, *start))
        return 0;
}

static t_command *ft_parsecommand(t_token **tokens, int start, int end)
{
    t_command *cmd;

    cmd = create_command();
    while (tokens[start] && start < end)
    {
        if (!parsetoken(tokens, &start, end, cmd))
            return (0); // error gg
        start++;
    }
    return (cmd);
}

t_command **ft_parsecommands(t_token **tokens, int start, int end)
{
    t_command *cmd;
    t_command **commands;
    int i;

    commands = NULL;
    i = start;
    while (i < end)
    {
        while (i < end && tokens[i] && tokens[i]->type != PIPE)
            i++;
        cmd = ft_parsecommand(tokens, start, i);
        if (!cmd)
            return (error_occured(commands, NULL));
        ft_add_arr_command(&commands, cmd);
        if (tokens[i] && tokens[i]->type == PIPE && !tokens[++i])
        {
            return (error_occured(commands, tokens[i - 1]));
        }
        start = i;
    }
    return (commands);
}