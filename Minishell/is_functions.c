#include "minishell.h"

int is_alpha_underscore(char c)
{
    if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    return (0);
}

int is_env(char c)
{
    if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        return (1);
    return (0);
}
