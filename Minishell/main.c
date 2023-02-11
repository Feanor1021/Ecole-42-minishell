#include "Minishell.h"

int main(int argc, char **argv)
{
    int fd = open("my.txt", O_CREAT | O_WRONLY | O_TRUNC, 0664);
    if (fd < 0)
    {
        perror("open");
        exit(1);
    }
    dup2(fd, 1);
    printf("seasdqwe burdayim");
}