#include "minishell.h"

static void heredoc_sighandler(int sig)
{
    (void)sig;
    exit(1);
}

static void heredoc_read(char *finish, int fd)
{
    char *line;

    while (1)
    {
        line = readline("> ");
        if (ft_strcmp(line, finish) == 0 || !line)
        {
            free(line);
            break;
        }
        write(fd, line, ft_strlen(line));
        write(fd, "\n", 1);
        free(line);
    }
}

static int take_heredoc(t_command *cmd, char *finish)
{
    int retcode;
    int p[2];
    pid_t pid;

    pipe(p);
    pid = fork();
    if (pid == 0)
    {
        signal(SIGINT, heredoc_sighandler);
        close(p[0]);
        heredoc_read(finish, p[1]);
        close(p[1]);
        exit(0);
    }
    close(p[1]);
    waitpid(pid, &retcode, 0);
    if ((((retcode)&0xff00) >> 8) != 0)
    {
        close(p[0]);
        return (0);
    }
    if (cmd->in != 0)
        close(cmd->in);
    cmd->in = p[0];
    return 1;
}

static int ft_heredoc(t_command *cmd)
{
    int i;

    i = 0;
    if (cmd->heredocsteps && cmd->heredocsteps[i] && !take_heredoc(cmd, cmd->heredocsteps[i++]))
        return (0);
    else
        return 1;
}

// while (cmd->heredocsteps && cmd->heredocsteps[i])
// {
//     if (!take_heredoc(cmd, cmd->heredocsteps[i++]))
//         return 0;
// }
// return 1;

int get_heredoc(t_pipeline *pipes)
{
    int i;

    i = 0;
    if (pipes)
    {
        while (pipes->commands[i])
        {
            if (!ft_heredoc(pipes->commands[i]))
                return 0;
            ft_free_arr_str(pipes->commands[i]->heredocsteps);
            pipes->commands[i]->heredocsteps = NULL;
            i++;
        }
    }
    return 1;
}