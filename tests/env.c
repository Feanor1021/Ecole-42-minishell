#include <stdio.h>
#include <stdlib.h>

int main(int agc, char **argv, char **env)
{
    char *env_var = env[0];
    int i = 0, j;
    while (env[i])
    {
        if (env[i][0] == 'P' && env[i][1] == 'A')
            break;
        i++;
    }
    env_var = env[i];
    printf("%s\n\n", env_var);
    i = 0;
    char *arr = (char *)malloc(sizeof(char) * 7);
    while (env_var[i] != '=' && env_var[i])
    {
        arr[i] = env_var[i];
        i++;
    }
    arr[i] = '\0';
    printf("%s\n", arr);
    printf("%s", getenv(arr));
}