/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:20:30 by cbajji            #+#    #+#             */
/*   Updated: 2024/08/18 15:33:31 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
word 1
built 2
redir 3
heredoc 4
*/

void giving_type(t_node *token)
{
    t_node *current;
    current = token;
    while (current)
    {
        if (!strcmp(current->content, "<") || !strcmp(current->content, ">") || !strcmp(current->content, ">>"))
            current->type = 3;
        else if (!strcmp(current->content, "<<"))
            current->type = 4;
        else if (!strcmp(current->content, "echo") || !strcmp(current->content, "cd") || !strcmp(current->content, "pwd") || !strcmp(current->content, "export")
                || !strcmp(current->content, "unset") || !strcmp(current->content, "env") || !strcmp(current->content, "exit"))
            current->type = 2;
        else 
            current->type = 1;
        current = current->next;
    }
}

