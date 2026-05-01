/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:08:59 by dshirais          #+#    #+#             */
/*   Updated: 2026/05/01 16:17:00 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_nred	*rd_handler(t_nred *node, t_token **current)
{
	t_nred	*new;

	while ((*current) && (*current)->type != WORD && (*current)->type != PIPE)
	{
		new = (t_nred *)ft_calloc(1, sizeof(t_nred));
		if (!new)
			return (NULL);
		which_red(new, *current);
		move_to_next_token(current);
		if (word_fill(new, current))
			return (NULL);
		node = red_add_back(node, new);
		move_to_next_token(current);
	}
	return (node);
}

int	word_fill(t_nred *node, t_token **current)
{
	if (node->type == ND_HEREDOC)
	{
		node->delimiter = red_list_gen(node->delimiter, current);
		if (!node->delimiter)
			return (1);
	}
	else
	{
		node->filename = red_list_gen(node->filename, current);
		if (!node->filename)
			return (1);
	}
	return (0);
}

t_narg	*red_list_gen(t_narg *node, t_token **current)
{
	t_token	*tmp;

	tmp = *current;
	if (!tmp)
		return (error_in_redirect(0, NULL), NULL);
	if (tmp->type != WORD)
		return (error_in_redirect(1, tmp->value), NULL);
	node = make_arg_list(&node, *current);
	if (!node)
		return (NULL);
	while ((*current)->next && (*current)->next->type == WORD
		&& (*current)->next->flag_cat)
	{
		move_to_next_token(current);
		node = make_arg_list(&node, *current);
		if (!node)
			return (NULL);
	}
	return (node);
}

t_nred	*red_add_back(t_nred *head, t_nred *new)
{
	t_nred	*tmp;

	tmp = head;
	new->next = NULL;
	if (!tmp)
		return (new);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (head);
}
