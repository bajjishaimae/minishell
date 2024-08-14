/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deep_tokenize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:21:42 by cbajji            #+#    #+#             */
/*   Updated: 2024/08/14 22:58:52 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int contains_only_symbol(char *str)
{
    return (!strcmp(str, ">") || !strcmp(str, "<") || !strcmp(str, "<<") || !strcmp(str, ">>") || !strcmp(str, "|"));
}

int contains_symbol(char *str)
{
    return (ft_strchr(str, '>') || ft_strchr(str, '<') || ft_strchr(str, '|'));
}

void add_node(t_node **list, char *content)
{
    t_node *new_node = ft_lstnew(content);
    if (!new_node)
        return; 
    ft_lstadd_back(list, new_node);
}

void divide_and_add(t_node **list, char *content)
{
    int i = 0;
    int start = 0;
    char *token;

    while (content[i])
    {
        if (content[i] == '<' || content[i] == '>' || content[i] == '|')
        {
            if (i > start)
            {
                int len = i - start;
                token = malloc(sizeof(char) * (len + 1));
                if (!token) return; 
                strncpy(token, content + start, len);
                token[len] = '\0';
                add_node(list, token);
                free(token);
            }

            if (content[i + 1] == content[i])
            {
                token = malloc(sizeof(char) * 3);
                if (!token) return; 
                token[0] = content[i];
                token[1] = content[i];
                token[2] = '\0';
                add_node(list, token);
                free(token);
                i += 2;
            }
            else 
            {
                token = malloc(sizeof(char) * 2);
                if (!token) return; 
                token[0] = content[i];
                token[1] = '\0';
                add_node(list, token);
                free(token);
                i++;
            }

            start = i;
        }
        else
        {
            i++;
        }
    }

    if (i > start)
    {
        int len = i - start;
        token = malloc(sizeof(char) * (len + 1));
        if (!token) return; 
        strncpy(token, content + start, len);
        token[len] = '\0';
        add_node(list, token);
        free(token);
    }
}

t_node *search_token(t_token **tokens)
{
    int i = 0;
    t_node *list = NULL;
    while (tokens[i])
    {
        if (!contains_only_symbol(tokens[i]->content) && contains_symbol(tokens[i]->content))
        {
            divide_and_add(&list, tokens[i]->content);
        }
        else
        {
            add_node(&list, tokens[i]->content);
        }
        i++;
    }
    return list;
}

