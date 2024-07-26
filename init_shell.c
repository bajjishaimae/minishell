#include "minishell.h"

char **copy_env(char **env)
{
    int size;
    char **to_copy;
    int i;

    i = 0;
    size = 0;
    while (env[size])
        size++;
    to_copy = malloc (sizeof(char *) * size + 1);
    if (!to_copy)
    {
        exit(1);
    }
    
    while (env[i])
    {
        to_copy[i] = strdup(env[i]);
        i++;
    }
    to_copy[i] = NULL;
    return (to_copy);
}

void display_prompt(t_list shell)
{
    char *input;
    int i = 0;
    while(1)
    {
        input = readline("minishell$  ");
        if (!input)
            exit(1);
        add_history(input);
        check_unclosed_quotes(input);
        shell.tokens = into_tokens(input);
        while(shell.tokens[i])
        {
            printf("%s\n", shell.tokens[i]);
            i++;
        }
        i = 0;
    }
}