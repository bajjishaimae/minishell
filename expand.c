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

char *replace_value(char *token, char *value, char *name)
{
    int name_len = ft_strlen(name);
    int token_len = ft_strlen(token);
    int value_len = ft_strlen(value);
    int new_token_len = (token_len - name_len) + value_len;
    char *new_token = malloc (sizeof(char) * new_token_len);
    char *pos = strstr(token, name);

    strncpy(new_token, token, pos - token);
    strcpy(new_token + (pos - token), value);
    strcpy(new_token + (pos - token) + value_len ,pos + name_len);

    return (new_token);
}

void expand(t_token **tokens, char *input, t_list shell)
{
    int i = 0;
    char *name;
    int name_len;
    char *value;
    char *new_token;
    check_token_dollar(shell.tokens);

    while (tokens[i])
    {
        if(!tokens[i]->need_expand || !can_expand(tokens[i]->content))
        {
            i++;
            continue;
        }
        name = variable_name(tokens[i]->content);
        name_len = ft_strlen(name);
        value = get_value(shell.env_var, name_len, name);
        new_token = replace_value(tokens[i]->content, value, name);
        free(tokens[i]->content);
        tokens[i]->content = new_token;
        i++;
    }
}


