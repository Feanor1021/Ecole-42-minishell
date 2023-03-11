#include "minishell.h"

static void ft_check_double_quotes(char *token, char **all_tokens)
{
    int end;
    char *token_temp;

    if (token[1] && token[1] == '"')
        return;
    else
    {
        dbquote_len(token + 1, &end);
        token_temp = ft_substr(token, 1, end);
        token_temp = change_env_with_value(token_temp);
        append_str(all_tokens, token_temp);
        free(token_temp);
    }
}

static void ft_check_single_quotes(char *token, char **all_tokens)
{
    int end;
    char *token_temp;

    if (token[1] && token[1] == '\'')
        return;
    else
    {
        singlequote_len(token + 1, &end);
        token_temp = ft_substr(token, 1, end);
        append_str(all_tokens, token_temp);
        free(token_temp);
    }
}

static void ft_check_without_quotes(char *tokens, char **all_tokens)
{
    char *token_temp;

    token_temp = ft_strdup(tokens);
    token_temp = change_env_with_value(token_temp);
    append_str(all_tokens, token_temp);
    free(token_temp);
}

char *ft_pars_quote_first(char *token)
{
    char *all_tokens;

    all_tokens = ft_calloc(sizeof(char), 1);

    if (token[0] == '"')
        ft_check_double_quotes(token, &all_tokens);
    else if (token[0] == '\'')
        ft_check_single_quotes(token, &all_tokens);
    else
        ft_check_without_quotes(token, &all_tokens);
    free(token);
    return all_tokens;
}

void ft_pars_quote(t_command *cmd)
{
    int i;

    if (cmd->command)
        cmd->command = ft_pars_quote_first(cmd->command);
    i = 0;
    while (cmd->arguments && cmd->arguments[i])
    {
        cmd->arguments[i] = ft_pars_quote_first(cmd->arguments[i]);
        i++;
    }
    // clean_array(cmd);
}
