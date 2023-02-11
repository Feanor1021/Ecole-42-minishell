#include "Minishell.h"

int main(int argc, char **argv)
{
    int tempin = dup(0);
    int tempout = dup(1);

    int fdpipe[2];
    pipe(fdpipe);

    dup2(fdpipe[1], 1);
    dup2(fdpipe[0], 0);
    printf("seaqw\n");
    char a[15];
    fgets(a, 15, 0);
    dup2(1, tempout);
    write(1, a, 15);
}