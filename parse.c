/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:20:30 by cbajji            #+#    #+#             */
/*   Updated: 2024/08/18 21:51:57 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
word 1
built 2
heredoc 3
infile 4
outfile 5
*/

void	redirections_classifier(t_node **lst_token)
{
	t_node	*current;

	current = *lst_token;
	while (current)
	{
		if (current->type == 4 && !ft_strcmp(current->content, "<")
			&& current->next != NULL && ft_strcmp(current->next->content, ">"))
			current->next->type = 4;
		else if (current->type == 5 && (!ft_strcmp(current->content, ">")
				|| !ft_strcmp(current->content, ">>")) && current->next != NULL)
			current->next->type = 5;
		else if (current->type == 3 && (!ft_strcmp(current->content, "<<"))
			&& current->next != NULL)
			current->next->type = 3;
		current = current->next;
	}
}

void giving_type(t_node *token)
{
    t_node *current;
    current = token;
    while (current)
    {
        if (!strcmp(current->content, "<"))
            current->type = 4;
        else if (!strcmp(current->content, ">") || !strcmp(current->content, ">>"))
            current->type = 5;
        else if (!strcmp(current->content, "<<"))
            current->type = 3;
        else if (!strcmp(current->content, "echo") || !strcmp(current->content, "cd") || !strcmp(current->content, "pwd") || !strcmp(current->content, "export")
                || !strcmp(current->content, "unset") || !strcmp(current->content, "env") || !strcmp(current->content, "exit"))
            current->type = 2;
        else 
            current->type = 1;
        current = current->next;
    }
}

t_line *create_line(t_node *node)
{
   t_line *line;
   t_node *current;
   t_node *first = NULL;
   line = malloc (sizeof(t_line));
   current = node;
   while(current && strcmp(current->content, "|"))
   {
        if (!first)
            first = node;
        else
            current->next = node;
        current = node;
        node = node->next;
   }
   if (current)
        current->next = NULL;
    line = first;
    redirections_classifier(&line->tokens);
    return (line);
}


t_line *tokens_to_lines(t_node *tokens)
{
    t_line *first_line = NULL;
    int flag = 0;
    t_line *line = NULL;

    while (tokens)
    {
        if (flag == 0)
        {
            line = create_line(tokens);
            if (!first_line)
                first_line = line;
            ft_lstadd_back(&first_line, line);
            flag = 1;
        }
        else if (strcmp(tokens->content, "|") == 0)
        {
            flag = 0;
        }
        tokens = tokens->next;
    }

    return first_line;
}