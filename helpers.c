#include "minishell.h"

int is_redirection_op(char c)
{
    if (c == '<' || c == '>')
        return (1);
    return(0);
}

int more_than_op(char *input)
{
    int i;
    int count;

    count = 1;
    i = 0;
    while (input[i])
    {
        if (input[i] == '<' || input[i] == '>')
        {
            i++;
            while(input[i] == '<' || input[i] == '>')
            {
                count++;
                i++;
                if(count > 2)
                    return (1);
            }
        }
        i++;
    }
    return (0);
}