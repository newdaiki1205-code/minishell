/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:06:48 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/26 16:31:37 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

t_token	*lexer(char *input)
{
	t_split	*input_tab;
	t_token	*tokens;

	input_tab = input_split(input);
	free(input);
	if (!input_tab)
		return (NULL);
	tokens = toknizer(input_tab);
	if (!tokens)
		return (NULL);
	return (tokens);
}
