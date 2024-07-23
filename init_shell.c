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
    to_copy[i] == NULL;
    return (to_copy);
}

char *take_prompt(t_list shell)
{
    
}
void display_prompt(t_list shell)
{
    char *prompt;
    char *input;

    prompt = take_prompt(shell);//implement this
    input = readline(prompt);
    if (!input)
    {
        return;
    }
    add_history(input);
    check_unclosed_quotes(input);

}