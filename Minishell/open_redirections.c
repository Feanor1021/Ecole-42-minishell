#include "minishell.h"
#include <sys/wait.h>
static int get_flags(t_stream *stream)
{
    int flags;

    flags = O_CREAT | O_WRONLY;
    if (stream->appendmode)
        flags |= O_APPEND;
    else
        flags |= O_TRUNC;
    return (flags);
}

static int redirect_out(t_command *cmd, t_stream *stream)
{
    if (cmd->out != 1)
        close(cmd->out);
    cmd->out = open(stream->path, get_flags(stream), 0666);
    if (cmd->out == -1)
    {
        put_errno_msg(stream->path);
        return 0;
    }
    return 1;
}

static int redirect_in(t_command *cmd, t_stream *stream)
{
    if (cmd->in != 0)
        close(cmd->in);
    cmd->in = open(stream->path, O_RDONLY);
    if (cmd->in == -1)
    {
        put_errno_msg(stream->path);
        return 0;
    }
    return 1;
}

int open_redirs(t_command *cmd)
{
    int i;

    i = 0;
    while (cmd->redirections && cmd->redirections[i])
    {
        if (cmd->redirections[i]->type == STREAM_OUT)
        {
            if (!redirect_out(cmd, cmd->redirections[i]))
                return 0;
        }
        else if (cmd->redirections[i]->type == STREAM_IN)
            if (!redirect_in(cmd, cmd->redirections[i]))
                return 0;
        i++;
    }
    return 1;
}

int init_redirects(t_command *cmd)
{
    if (open_redirs(cmd))
    {
        g_shell->return_code = 0;
        return -1;
    }
    g_shell->return_code = 1;
    return 0;
}