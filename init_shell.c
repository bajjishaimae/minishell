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
    to_copy = malloc (sizeof(char *) * (size + 1));
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
    (void)shell;
    //i = 0;
    while(1)
    {
        input = readline("minishell$  ");
        if (!input)
            exit(1);
        add_history(input);
        if (check_unclosed_quotes(input) || check_prohibited_char(input) || !validate_redirection_syntax(input))
            continue;
        shell.tokens = into_tokens(input);
        check_token_dollar(shell.tokens);
        // while(shell.tokens[i])
        // {
        //     printf("%s\n", shell.tokens[i]->content);
        //     i++;
        // }
        // i = 0;
        
        // printf("%d\n", tokens_number(input));
    }
}