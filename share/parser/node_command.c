/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 20:45:37 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/26 19:57:59 by dshirais         ###   ########.fr       */
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
		if ((*current)->type != WORD && rd_handler(&node->red, current))
			return (free_parser_error(node), NULL);
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

int	rd_handler(t_nred *node, t_token **current)
{
	if ((*current)->type == I_RED)
		node->type = ND_INPUT;
	else if ((*current)->type == O_RED)
		node->type = ND_OUTPUT;
	else if ((*current)->type == APPEND)
		node->type = ND_APPEND;
	else
		node->type = ND_HEREDOC;
	node->filename = filename_handler(node, current);
	if (!node->filename)
		return (1);
	*current = (*current)->next;
	return (0);
}

char	*filename_handler(t_nred *node, t_token **current)
{
	t_token	*filename;

	*current = (*current)->next;
	filename = *current;
	if (!filename)
	{
		printf("minihsell: syntax error near unexpected token `newline'\n");
		return (NULL);
	}
	if (filename->type != WORD)
	{
		printf("minishell: syntax error near unexpected token '%s'\n",
			filename->value);
		return (NULL);
	}
	node->filename = ft_strdup((*current)->value);
	if (!node->filename)
		return (NULL);
	return (node->filename);
}
