#include "minishell.h"

int check_unclosed_quotes(char *input)
{
    int double_quotes;
    int single_quotes;
    int i;

    i = 0;
    double_quotes = 0;
    single_quotes = 0;
    while (input[i])
    {
        if (input[i] == '"')
            double_quotes++;
        if (input[i] == '\'')
            single_quotes++;
        i++;
    }
    if (double_quotes % 2 != 0 || single_quotes % 2 != 0)
    {
        printf("unclosed quotes\n");
        return (1);
    }
    return (0);
}

int check_prohibited_char(char *input)
{
    int i;

    i = 0;
    while (input[i])
    {
        if (input[i] == '\\' || input[i] == ';' || input[i] == '(' || input[i] == ')')
        {
            printf("prohibited character\n");
            return (1);
        }
        i++;
    }
    return (0);
}

int validate_redirection_syntax(char *input)
{
    int i;
    int inside_q;
    int q_type;

    q_type = 0;
    inside_q = 0;
    i = 0;
    while (input[i])
    {
        if (input[i] == '"' || input[i] == '\'')
        {
            if (inside_q && input[i] == q_type)
                inside_q = 0;
            else if (!inside_q)
            {
                inside_q = 1;
                q_type = input[i];
            }
        }
        else if (!inside_q && is_redirection_op(input[i]))
        {
            i++;
            while (input[i] == ' ')
                i++;
            if (input[i] == '\0' || (is_redirection_op(input[i]) && input[i - 1] == ' '))
            {
                printf("Syntax error: Invalid redirection\n");
                return 0;
            }
            while (input[i] && input[i] == ' ' && !is_redirection_op(input[i]))
                i++;
            continue;
        }
        i++;
    }
    if (is_redirection_op(input[0]) || is_redirection_op(input[i - 1]) || more_than_op(input))
    {
        printf("Redirection error\n");
        return 0;
    }
    return 1;
}
