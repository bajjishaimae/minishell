#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <readline/readline.h>
#include <readline/history.h>


typedef struct s_token
{
    char *content;
    char *type;
    int need_expand;
} t_token;

typedef struct s_list
{
    char **env_var;
    t_token **tokens;
} t_list;

void display_prompt(t_list shell);
char **copy_env(char **env);
int check_unclosed_quotes(char *input);
t_token **into_tokens(char *input);
int check_prohibited_char(char *input);
int is_redirection_op(char c);
int skip_spaces(char *input, int i);
int validate_redirection_syntax(char *input);
int tokens_number(char *input);
int more_than_op(char *input);
void check_token_dollar(t_token **token);
int ft_strlen(char *str);
void expand(t_token **tokens, t_list shell);
#endif