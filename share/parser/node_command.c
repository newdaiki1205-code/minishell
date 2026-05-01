/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 20:45:37 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/28 17:55:38 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node	*new_node_command(t_token **current)
{
	t_node	*node;

	if (!is_valid_start(current))
		return (NULL);
	node = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!node)
		return (NULL);
	node->type = ND_COMMAND;
	while (!command_check(current))
	{
		if ((*current)->type != WORD)
		{
			node->red = rd_handler(node->red, current);
			if (!node->red)
				return (free_parser_error(node), NULL);
		}
		if (command_check(current))
			break ;
		node->args = make_arg_list(&node->args, *current);
		if (!node->args)
			return (free_parser_error(node), NULL);
		*current = (*current)->next;
	}
	return (node);
}

bool	is_valid_start(t_token **current)
{
	if (!*current)
	{
		printf("minishell: syntax error near unexpected token 'newline'\n");
		return (false);
	}
	if (command_check(current))
	{
		printf("minishell: syntax error near unexpected token '%s'\n",
			(*current)->value);
		return (false);
	}
	return (true);
}
