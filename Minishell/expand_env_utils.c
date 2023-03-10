#include "minishell.h"

void replace_with(char **str, char *a, char *b)
{
    char *temp;

    if(b)
    {
        temp = *str;
        *str = ft_strdup(b);
        free(temp);
    }
    else
    {
		ft_memmove(ft_strnstr(*str, a, ft_strlen(*str)),
				   ft_strnstr(*str, a, ft_strlen(*str)) + ft_strlen(a), ft_strlen(*str));
    }

}

int get_env_index(char *name)
{
    int i;
    int k;
    int index;
    char **env;

    if(name[0] == '$')
        name++;
    index = 0;
    env = g_shell->env;
    while(env[index])
    {
        i = 0;
        k = 0;
        while (env[index][i] && env[index][i] == name[k])
        {
            i++;
            k++;
        }
 		if ((!name[k] && env[index][i] == '=') || !env[index][i])
			return (index);
		index++;
	}
	return (-1);
}

char *get_env(char *arr)
{
    int i;
    int env_index;
    char *env;

    env_index = get_env_index(arr);
    if(env_index == -1)
        return NULL;
    env = g_shell->env[env_index];
    i = 0;
    while (env[i] && env[i] != '=')
        i++;
    if (env[i] == '=')
        i++;
    return (env+i);
}

