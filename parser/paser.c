/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paser.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 20:48:36 by dshirais          #+#    #+#             */
/*   Updated: 2026/03/31 20:52:48 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node	*new_node(t_type kind, t_node *lhs, t_node *rhs)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	node->type = kind;
	node->lhs = lhs;
	node->rhs = rhs;
	return (node);
}

t_node	*new_node_word(int val)
{
	t_node	*node;

	node = calloc(1, sizeof(t_node));
	node->type = ND_WORD;
	node->val = val;
	return (node);
}
