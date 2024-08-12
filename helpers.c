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

int ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

void check_token_dollar(t_token **token)
{
    int i = 0;
    while(token[i]->content)
    {
        if (ft_strchr(token[i]->content, '$'))
            token[i]->need_expand = 1;
        else 
            token[i]->need_expand = 0;
        i++;
    }
}