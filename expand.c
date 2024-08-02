#include "minishell.h"

int can_expand(char *input)
{
    int d_quote;
    int s_quote_index;
    int d_quote_index;
    int i = 0;

    d_quote = -1;
    while (input[i])
    {
        if (input[i] == '"')
        {
            d_quote = -d_quote;
            d_quote_index = i;
        }
        else if (input[i] == '\'')
            s_quote_index = i;
        if (input[i] == '$' && d_quote_index < s_quote_index && d_quote > 0)
            return (1);
        i++;
    }
    return (0);
}

char *variable_name(char *input)
{
    int len = 0;
    int start = 0;

    if (input[start] == '$') 
        start++;
    while (input[start + len] && (isalnum(input[start + len]) || input[start + len] == '_')) 
        len++;
    char *var_name = malloc(len + 1);
    if (var_name) {
        strncpy(var_name, input + start, len);
        var_name[len] = '\0';
    }
    return var_name;
}

char *get_value(char **env_vars)
{
    
}






