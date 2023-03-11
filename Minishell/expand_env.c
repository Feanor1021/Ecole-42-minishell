#include "minishell.h"

static int env_len(char *s)
{
    int i;

    i = 0;
    while (is_env(s[i]) && s[i])
        i++;
    return i;
}

static char *ft_take_env(char *token)
{
    if (token[0] == '$' && token[1] && token[1] == '?')
        return (ft_strdup("$?"));
    else if (token[0] == '$' && token[1] && !is_alpha_underscore(token[1]))
        return (ft_substr(token, 0, 2));
    else if (token[0] == '$' && token[1] && is_env(token[1]))
        return (ft_substr(token, 0, (env_len(token + 1) + 1)));
    return 0;
}

char *change_env_with_value(char *token)
{
    char *env;
    char *env_value;

    env = ft_take_env(token);
    if (!env)
        return token;
    if (ft_strnstr(env, "$?", ft_strlen(env)) && ft_strlen(env) == 2)
    {
        env_value = ft_itoa(g_shell->return_code);
        replace_with(&token, env, env_value);
        free(env_value);
    }
    else
    {
        env_value = get_env(env + 1);
        replace_with(&token, env, env_value);
    }
    free(env);
    return (token);
}
