/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 14:53:54 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/03 16:22:54 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node	*new_node(t_ntype kind, t_node *lhs, t_node *rhs)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	node->type = kind;
	node->lhs = lhs;
	node->rhs = rhs;
	return (node);
}

t_node	*new_node_word(char *val)
{
	t_node	*node;

	node = calloc(1, sizeof(t_node));
	node->type = ND_WORD;
	node->val = val;
	return (node);
}

t_node	*new_node_redirect(char *val)
{
	t_node	*node;

	node = calloc(1, sizeof(t_node));
	node->type = ND_IO_RED;
	node->val = val;
	return (node);
}

bool	pipe_check(t_token *current)
{
	if (current->type != PIPE)
		return (false);
	current = current->next;
	return (true);
}

bool	command_check(t_token *current)
{
	if (!current->next)
		return (false);
	current = current->next;
	return (true);
}
