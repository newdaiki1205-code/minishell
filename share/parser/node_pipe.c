/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:16:14 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/26 20:01:05 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node	*new_node_pipe(t_ntype kind, t_node *lhs, t_node *rhs)
{
	t_node	*node;

	node = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!node)
		return (NULL);
	node->type = kind;
	node->lhs = lhs;
	node->rhs = rhs;
	return (node);
}
