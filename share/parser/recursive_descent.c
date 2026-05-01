/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_descent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 13:36:23 by dshirais          #+#    #+#             */
/*   Updated: 2026/05/01 16:17:41 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node	*pipe_sequence(t_token **current)
{
	t_node	*node;

	node = command(current);
	if (!node)
		return (NULL);
	while (1)
	{
		if (pipe_check(current))
		{
			node = new_node_pipe(ND_PIPE, node, command(current));
			if (!node || !node->rhs)
				return (free_parser_error(node), NULL);
		}
		else
			return (node);
	}
}

t_node	*command(t_token **current)
{
	t_node	*node;

	node = new_node_command(current);
	if (!node)
		return (NULL);
	return (node);
}
