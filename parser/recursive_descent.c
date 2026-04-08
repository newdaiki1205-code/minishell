/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive-descent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 13:36:23 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/03 15:09:42 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node	*pipe_sequence(t_token **current)
{
	t_node	*node;

	node = command(current);
	if(!node)
		return NULL;
	while (1)
	{
		if (pipe_check(current))
		{
			node = new_node(ND_PIPE, node, command(current));
			if(!node->rhs)
				return NULL;
		}
		else
			return (node);
	}
}


t_node	*command(t_token **current)
{
	t_node	*node;

	node = new_node_command(current);
	if(!node)
		return NULL;
	return node;
}

// t_node	*command(t_token *current)
// {
// 	t_node	*node;

// 	node = element(current);
// 	while (1)
// 	{
// 		if (command_check(current)) // return if pipe  & token->next != NULL
// 			node = new_node(ND_COMMAND, node, element(current)); //problem: current is moved by command_check
// 		else
// 			return (node);
// 	}
// }

// t_node	*element(t_token *current)
// {
// 	t_node *node;

// 	if (current->type != WORD)
// 		node = new_node_redirect(current);
// 	else
// 		node = new_node_word(current);
// 	current = current->next;
// 	return (node);
// }