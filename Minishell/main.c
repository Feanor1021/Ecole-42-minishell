#include "Minishell.h"

int main()
{
    int ret;

    ret = fork();
    if (ret == 0)
    {
        char const *argv[3];
        argv[0] = "ls";
        argv[1] = "-la";
        argv[2] = NULL;
        execvp(argv[0], argv);
        perror("execvp");
        _exit(1);
    }
    else if (ret < 0)
    {
        perror("fork");
        exit(2);
    }
    else
    {
        waitpid(ret, NULL, 0);
    }
}