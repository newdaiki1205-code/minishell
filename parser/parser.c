/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 20:48:36 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/09 16:24:30 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node	*parser(t_token **tokens)
{
	t_node *ret;
	t_token *head = *tokens;

	ret = pipe_sequence(tokens);
	if (!ret)
		return (NULL);
	free_tokens(head);
	debug_parser(ret);
	return (ret);
}
