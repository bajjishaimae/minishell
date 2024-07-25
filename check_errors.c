#include "minishell.h"

void check_unclosed_quotes(char *input)
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
        printf("unclosed quotes\n");
}