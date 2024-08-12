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
    int i = 0;

    while (input[i] && input[i] != '$')
        i++;
    start = i + 1;
    while (input[i] && input[i] != ' ')
        i++;
    len = i - start;
    char *var_name = malloc(sizeof(char) * (len + 1));
    if (var_name) {
        strncpy(var_name, input + start, len);
        var_name[len] = '\0';
    }
    return var_name;
}

char *get_value(char **env_vars, int len, char *name)
{
    int i = 0;
    int j = 0;
    char *value;
    while (env_vars[i])
    {
        if (strncmp(name, env_vars[i], len) == 0)
        {
            len++;
            break;
        }
        i++;
    }
    j = len;
    while (env_vars[i][j])
        j++;
    value = malloc(sizeof(char) * (j - len + 1));
    j = 0;
    while(env_vars[i][len])
    {
        value[j] = env_vars[i][len];
        j++;
        len++;
    }
    value[j] = '\0';
    return (value);

}

void replace_it(char *input, char *value)
{
    int i = 0;
    while (input[i])
    {
        if (input[i] == '$')
        {

        }

    }
}

void expand(char *input, t_list shell)
{
    if (can_expand(input))
}

int main()
{
    char **env;
    env = malloc (sizeof(char *) * 3);
    int i = 0;
    
    env[0] = strdup("USER=bajjishaima");
    env[1] = strdup("HOME=/home/bajjishaima");
    env[2] = strdup("NAME=DESKTOP-ATD8A5U");


   printf("%s\n", get_value(env, 4, "USER"));
}

