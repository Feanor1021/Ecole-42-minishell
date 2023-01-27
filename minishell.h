/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:39:59 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/12 23:26:27 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define FT_DEFINES_H
# define DEP_AND 1
# define DEP_OR 2
# define STREAM_IN 1
# define STREAM_OUT 2

# define BT_ECHO "echo"
# define BT_CD "cd"
# define BT_PWD "pwd"
# define BT_EXIT "exit"
# define BT_EXPORT "export"
# define BT_UNSET "unset"

# define BT_ENV "env"

typedef struct s_wildcard
{
	int		len;
	char	***tmp;
	char	**tmp2;
}				t_wildcard;


enum e_tokentype {
	WORD,
	PIPE,
	RED_APPEND,
	RED_CREATE,
	AND,
	OR,
	RED_INPUT,
	HEREDOC,
	LPAR,
	RPAR
};

enum e_starmods {
	LEFT_STAR,
	RIGHT_STAR,
	DB_STARS
};

typedef struct s_token {
	char				*data;
	enum e_tokentype	type;
}	t_token;

typedef struct s_stream {
	char	*path;
	int		type;
	int		appendmode;
}	t_stream;

struct				s_pipeline;

typedef struct s_command {
	char				*command;
	char				**heredocsteps;
	char				**arguments;
	t_stream			**redirections;
	int					out;
	int					in;
	struct s_pipeline	**subshells;
}	t_command;

typedef struct s_pipeline {
	t_command	**commands;
	int			dependon;
}	t_pipeline;

typedef struct s_mini {
	int		return_code;
	int		exitflag;
	int		intflag;
	int		pipecount;
	int		issubshell;
	int		*openedpipes;
	char	**env;
}					t_mini;

extern t_mini		*g_mini;

char		**ft_copyarr_str(char	**arr);
void		ft_freearr_str(char **arr);
void		ft_freearr(void **arr, void (*f)(void *));
char		*ft_create_prompt(void);
char		*ft_getinput(void);
void		ft_execline(char *input);
t_token		**ft_gettokens(char *str);
t_pipeline	**ft_parsepipelines(t_token **tokens, int start, int end);
t_token		*ft_getnexttoken(char *str);
t_token		*ft_getonechartoken(enum e_tokentype type, int *i, char chr);
t_token		*ft_gettwochartoken(char *str, int *i, enum e_tokentype type, \
																char chr);
int			ft_isdelimitter(char chr);
t_token		*ft_getwordtoken(char *str, int *i);
int			ft_isquote(char chr);
void		ft_addarr(void ***arr, void *new);
int			ft_arrlen(void **arr);
t_token		*ft_createtoken(char *data, enum e_tokentype type);
int			ft_isspace(char chr);
void		ft_syntaxerror(t_token *token);
void		ft_freearr_pipeline(t_pipeline **pipes);
void		ft_freepipeline(t_pipeline *p);
int			ft_islogic(t_token *tok);
int			ft_skipbrackets(t_token **tokens, int start, int end);
void		ft_freearr_command(t_command **cmd);
void		ft_freecommand(t_command *command);
void		ft_addarr_pipeline(t_pipeline ***arr, t_pipeline *new);
void		ft_addarr_command(t_command ***arr, t_command *new);
t_command	**ft_parsecommands(t_token **tokens, int start, int end);
void		ft_freestream(t_stream *stream);
t_command	*ft_parsecommand(t_token **tokens, int start, int end);
int			ft_parsesubshell(t_command *cmd, t_token **tokens, \
						int *start, int end);
int			ft_parsewordtoken(t_command *cmd, t_token **tokens, int i);
void		ft_addarr_str(char ***arr, char *new);
int			ft_parseheredoc(t_command *cmd, t_token **tokens, int *i);
int			ft_heredoc(t_command *cmd);
int			ft_parseredoutput(t_command *cmd, t_token **tokens, int *i);
int			ft_parseredinput(t_command *cmd, t_token **tokens, int *i);
void		ft_addarr_stream(t_stream ***arr, t_stream *new);
void		ft_runpipelines(t_pipeline **pipes);
void		ft_connectpipes(t_command **cmds);
void		ft_addarr_int(int **arr, int len, int new);
int			ft_runcommand(t_command *cmd);
void		ft_closepipes(void);
int			ft_initsubshell(t_command *cmd);
void		ft_clearsignals(void);
int			ft_open_reds(t_command *cmd);
void		ft_puterrno_msg(char *msg);
void		ft_connectio(t_command *cmd);
void		ft_puterrno(void);
int			ft_strcmp(char *str1, char *str2);
int			ft_isbuiltin(char *command);
int			ft_runbuiltin(t_command *cmd);
int			ft_initbuiltin(t_command *cmd);
int			ft_cd(t_command *cmd);
char		*ft_get_value(char *s);
int			ft_strlenchr(char *s, char c);
int			ft_getenvindex(char *name);
void		ft_setenv(char *name, char *value);
int			ft_exit(t_command *cmd);
int			ft_isnumeric(char *str);
int			ft_export(t_command *cmd);
void		ft_onlyexport(t_command *command);
char		*ft_get_key(char *s);
char		*ft_get_value(char *s);
void		ft_strappend(char **str, char *appendstr);
int			ft_env_check(char *s);
int			ft_isalpha_underscore(char c);
int			ft_is_env(char c);
int			ft_unset(t_command *command);
void		ft_delenv(char *name);
int			ft_env(t_command *command);
void		ft_freearr_token(t_token **tokens);
void		ft_freetoken(t_token *token);
int			ft_echo(t_command *command);
int			ft_pwd(t_command *cmd);
int			ft_initredirects(t_command *cmd);
void		ft_pars_quote(t_command *cmd);
void		ft_get_end_numbers_dbquotes(char *s, int *end);
char		*change_env_with_value(char *s);
void		ft_replace(char **str, char *a, char *b);
void		ft_get_end_numbers_quote(char *s, int *end);
void		ft_get_len_of_word(char *s, int *end);
char		*ft_getenv(char *name);
void		ft_clean_array(t_command *cmd);
char		*ft_findinpath(char *file);
int			ft_ispath(char *file);
int			ft_filexists(char *path);
int			ft_isfile(char *path);
int			ft_initprocess(t_command *cmd, char *cmdpath);
void		ft_puterrln(char *msg, char *data);
void		ft_connectsignals(void);
void		ft_signalhandler(int sig);
void		ft_addarr_token(t_token ***arr, t_token *new);

//wilcard
int			ft_parse_wildcard(t_command *command, int index, int t_index);
int			ft_check_star(t_command *command);
int			ft_acheck(t_command *command);
int			ft_first_star(t_command *command);
int			ft_star_state(char *str);
char		*ft_only_word(char *str);
int			ft_total_words(char *str, int index, int count);
char		*ft_strstr_last(char *haystack, char *needle);
void		ft_db_stars_secondpart(t_command *command, int i, int j, char *fs);
void		ft_left_star_secondpart(t_command *cmd, int i, int j, char *fs);
char		*ft_revstrstr(char *haystack, char *needle);
int			ft_opendir(t_command *cmd);
void		ft_arrfix(t_command *cmd);

#endif