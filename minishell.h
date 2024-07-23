#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>


typedef struct s_list
{
    char **env_var;
} t_list;

void display_prompt(t_list shell);
char **copy_env(char **env);
void check_unclosed_quotes(char *input);