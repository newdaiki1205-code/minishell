/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:02:02 by dshirais          #+#    #+#             */
/*   Updated: 2026/03/30 18:09:27 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"



size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
        i = 0;
        while (token && token[i])
	    {      
		    free(token[i]);
		    i++;
	    }
        free(input);
    }
    return 0;
}