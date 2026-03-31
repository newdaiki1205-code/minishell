/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 19:07:20 by dshirais          #+#    #+#             */
/*   Updated: 2026/03/31 15:00:07 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

void free_tokens(t_token *tokens)
{
	t_token *tmp;
	
	while(tokens)
	{
		tmp = tokens->next;
		free(tokens->value);
		free(tokens);
		tokens = tmp;
	}
}

void print_tokeninfo(t_token *tokens)
{
	while (tokens)
	{
        printf("Type: %d\n", tokens->type);
		printf("Quote: %d\n", tokens->quote);
		printf("Value: %s\n", tokens->value);
		printf("\n");
		tokens = tokens->next;
	}
}
