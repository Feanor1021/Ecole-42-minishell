#include "minishell.h"

static void ft_check_double_quotes(char *token, char **all_tokens, int *index)
{
    int end;
    char *token_temp;
    char *env_val_temp;

    if (token[*index + 1] && token[*index + 1] == '"')
        (*index) += 2;
    else
    {
        dbquote_len(token + ++(*index), &end);
        token_temp = ft_substr(token, *index, end);
        env_val_temp = change_env_with_value(token_temp);
        append_str(all_tokens, env_val_temp);
        free(env_val_temp);
        *index += end + 1;
    }
}

static void ft_check_single_quotes(char *token, char **all_tokens, int *index)
{
    int end;
    char *token_temp;

    if (token[*index + 1] && token[*index + 1] == '\'')
        (*index) += 2;
    else
    {
        singlequote_len(token + ++(*index), &end);
        token_temp = ft_substr(token, *index, end);
        append_str(all_tokens, token_temp);
        free(token_temp);
        *index += end + 1;
    }
}

static void ft_check_without_quotes(char *tokens, char **all_tokens, int *index)
{
    int end;
    char *token_temp;
    char *env_val_temp;

    get_len_of_word(tokens + (*index), &end);
    token_temp = ft_substr(tokens, *index, end);
    env_val_temp = change_env_with_value(token_temp);
    append_str(all_tokens, env_val_temp);
    free(env_val_temp);
    *index += end;
}

char *ft_pars_quote_first(char *token)
{
    int index;
    char *all_tokens;

    all_tokens = ft_calloc(sizeof(char), 1);
    index = 0;
    while (token[index])
    {
        if (token[index] == '"')
            ft_check_double_quotes(token, &all_tokens, &index);
        else if (token[index] == '\'')
            ft_check_single_quotes(token, &all_tokens, &index);
        else
            ft_check_without_quotes(token, &all_tokens, &index);
    }
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