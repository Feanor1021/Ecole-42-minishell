#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "42-Libft/libft.h"
#include <sys/wait.h>

#define STREAM_IN 1
#define STREAM_OUT 2

#define BT_ECHO "echo"
#define BT_CD "cd"
#define BT_PWD "pwd"
#define BT_EXIT "exit"
#define BT_EXPORT "export"
#define BT_UNSET "unset"
#define BT_ENV "env"

enum e_tokentype
{
    WORD,
    PIPE,
    RED_APPEND,
    RED_CREATE,
    RED_INPUT,
    HEREDOC,
};

typedef struct s_shell
{
    int return_code;
    int e_flag;
    int i_flag;
    int pipe_count;
    int *opened_pipes;
    char **env;
} t_shell;

typedef struct s_stream
{
    char *path;
    int type;
    int appendmode;
} t_stream;

struct s_pipeline;

typedef struct s_command
{
    char *command;
    char **heredocsteps;
    char **arguments;
    t_stream **redirections;
    int out;
    int in;
} t_command;

typedef struct s_pipeline
{
    t_command **commands;
} t_pipeline;

typedef struct s_token
{
    char *data;
    enum e_tokentype type;
} t_token;

extern t_shell *g_shell;

// minishell_utils
int ft_arrlen(void **arr);
char **ft_copyarr_str(char **arr);
int ft_isdelimitter(char chr);
int ft_isquote(char chr);

// add_array
void ft_add_arr(void ***arr, void *new);
void ft_add_arr_token(t_token ***arr, t_token *new);
void ft_add_arr_command(t_command ***arr, t_command *new);
void ft_add_arr_str(char ***arr, char *new);
void ft_add_arr_stream(t_stream ***arr, t_stream *new);
void ft_add_arr_pipeline(t_pipeline ***arr, t_pipeline *new);
void ft_add_arr_int(int **arr, int len, int new);

// signals
void ft_connectsignals();
void ft_signalhandler(int sig);
void ft_clearsignals(void);

// getting input and prompt
char *ft_getinput(void);
char *ft_create_prompt(void);
void ft_execline(char *input);

// get tokens
t_token **ft_gettokens(char *str);
t_token *ft_createtoken(char *data, enum e_tokentype type);
t_token *onechartoken(char *str, int *i);

// execline
void ft_execline(char *input);

// parsepipelines
t_pipeline *ft_parsepipelines(t_token **tokens, int start, int end);

// parse commands
t_command **ft_parsecommands(t_token **tokens, int start, int end);
int parsetoken(t_token **tokens, int *start, int end, t_command *cmd);

// parse commands utils
int ft_parsewordtoken(t_command *cmd, t_token **tokens, int i);
int ft_parse_heredoc(t_command *cmd, t_token **tokens, int *i);
int ft_parse_input(t_command *cmd, t_token **tokens, int *i);
int ft_parse_output(t_command *cmd, t_token **tokens, int *i);

// syntax error
void ft_syntaxerror(t_token *token);

// frees
void ft_free_arr(void **arr, void (*f)(void *));
void ft_free_arr_str(char **arr);
void ft_free_command(t_command *cmd);
void ft_free_arr_command(t_command **commands);
void ft_free_stream(t_stream *stream);
void ft_free_arr_pipeline(t_pipeline **pipes);
void ft_free_pipeline(t_pipeline *pipe);

// errors
void *error_command_arr(t_command **commands, t_token *token);
void *error_command(t_command *cmd);
void *error_pipeline(t_pipeline *pipes, t_token *token);

// heredoc
int get_heredoc(t_pipeline *pipes);

// run_pipelines
void ft_runpipelines(t_pipeline *pipes);

// run commands
void run_commands(t_command **cmds);
int ft_runcommand(t_command *cmd);

// parse quote
void ft_pars_quote(t_command *cmd);
char *ft_pars_quote_first(char *token);

// parse quote_utils.c
void dbquote_len(char *token, int *end);
void singlequote_len(char *token, int *end);
void append_str(char **str, char *append);
void get_len_of_word(char *s, int *end);

// connection of pipes
void ft_connect_pipes(t_command **cmd);
void ft_close_pipes();

// expand_env.c
char *change_env_with_value(char *s);

// expand_env_utils.c
void replace_with(char **str, char *a, char *b);
char *get_env(char *arr);
int get_env_index(char *name);

// is_functions.c
int is_alpha_underscore(char c);
int is_env(char c);
int is_built_in(char *command);
int is_numeric(char *str);

// clear_null_arguments.c
void clean_null_arguments(t_command *cmd);

// build_in.c
int init_built_in(t_command *cmd);

// built_in_functions.c
int ft_env(t_command *cmd);
int ft_pwd(t_command *cmd);
int ft_exit(t_command *cmd);
int ft_echo(t_command *cmd);

#endif