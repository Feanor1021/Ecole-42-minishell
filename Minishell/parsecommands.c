#include "minishell.h"

static t_command *createcommand(void)
{
    // default
    t_command *cmd;

    cmd = ft_calloc(sizeof(t_command), 1);
    cmd->in = 0;
    cmd->out = 1;
    return (cmd);
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
        // if(!cmd)
        //     return (error_occured(commands,  NULL));
        // ft_addarr_command(&commands, cmd);
    }
}