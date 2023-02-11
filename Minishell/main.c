#include "Minishell.h"

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        fprintf(stderr, "usage: lsgrep arg1 arg2\n");
        exit(1);
    }
    int tempin = dup(0);
    int tempout = dup(1);

    int fdpipe[2];
    pipe(fdpipe);

    dup2(fdpipe[1], 1);
    close(fdpipe[1]);

    int ret = fork();

    if (ret == 0)
    {
        close(fdpipe[0]);
        char *args[3];
        args[0] = "ls";
        args[1] = "-la";
        args[2] = NULL;
        execvp(args[0], args);
        perror("execvp");
        _exit(1);
    }

    dup2(fdpipe[0], 0);
    close(fdpipe[0]);

    int fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);

    if (fd < 0)
    {
        perror("open");
        exit(1);
    }
    dup2(fd, 1);
    close(fd);

    ret = fork();
    if (ret == 0)
    {
        char *args[3];
        args[0] = "grep";
        args[1] = argv[1];
        args[2] = NULL;
        execvp(args[0], args);
        perror("execvp");
        _exit(1);
    }
    dup2(0, tempin);
    dup2(1, tempout);
    waitpid(-1, NULL, 0);
}