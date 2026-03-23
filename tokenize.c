/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:02:02 by dshirais          #+#    #+#             */
/*   Updated: 2026/03/23 16:57:39 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

// t_token *make_newtoken()
// {
//     t_token *new;

//     new = (t_token*)malloc(sizeof(t_token));
//     if(!new)
//         return NULL;
//     return new;
// }

// void add_token_back(t_token *head, t_token *new, char *input)
// {
//     t_token *tmp;
    
//     if(!head)
//     {
//         head = new;
//         new->next = NULL;
//     }
//     else
//     {
//         tmp = tmp->next;
//         while(tmp->next)
//             tmp = tmp->next;
//         tmp->next = new;
//         new->next = NULL;
//     }
//     set_info(new, input);
    
// }

// t_token *tokenizing(t_token *head, char **input)
// {
//     t_token *tmp;
//     int i = 1;
    
//     while(!input[i])
//     {
//         tmp = make_newtoken();
//         if(!tmp)
//             return NULL;
//         add_token_back(head, tmp, input[i]);
//         i++;
//     }
// }

// char *input_org(char **input)
// {
//     char *line;
//     int size;

    

    
// }

int main(void)
{
    // t_token *head;
    
    // head = NULL;
    // tokenizing(head, av);

    char *input;
    char **token;
    int i;

    while(1)
    {
        input = readline("minishell$ ");
        if (!input)
            break;
        if(ft_strlen(input) > 0)
            add_history(input);
        token = ft_split(input);
        i = 0;
        while(token[i])
        {
            printf("%s\n", token[i]);
            i++;
        }
        free(input);
    }
    return 0;
}