#include "minishell.h"

void ft_runpipelines(t_pipeline *pipes)
{
    g_shell->i_flag = 1;
    if (!get_heredoc(pipes))
        return;
    if (pipes)
        run_commands(pipes->commands);
    g_shell->i_flag = 0;
}