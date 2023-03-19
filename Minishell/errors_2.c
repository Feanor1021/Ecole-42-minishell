#include "minishell.h"

void put_error_ln(char *msg, char *data)
{
    ft_putstr_fd("bash: ", 2);
    if (data)
    {
        ft_putstr_fd(data, 2);
        ft_putstr_fd(": ", 2);
    }
    ft_putendl_fd(msg, 2);
}
