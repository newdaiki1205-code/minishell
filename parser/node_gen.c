/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_gen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:16:14 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/13 20:14:36 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node	*new_node_pipe(t_ntype kind, t_node *lhs, t_node *rhs)
{
	t_node	*node;

	node = (t_node *)ft_calloc(1, sizeof(t_node));
	node->type = kind;
	node->lhs = lhs;
	node->rhs = rhs;
	return (node);
}

t_node *new_node_command(t_token **current)
{
	t_node *node; //if its NULL, readline -> toknize -> node?

	if(!*current)
		return printf("minishell: syntax error near unexpected token 'newline'\n"), NULL;
	if(command_check(current))
		return printf("minishell: syntax error near unexpected token '%s'\n", (*current)->value), NULL;
	node = (t_node*)ft_calloc(1, sizeof(t_node));
	if(!node)
		return NULL;
	node->type = ND_COMMAND;
	while(!command_check(current))
	{
		if((*current)->type != WORD && rd_handler(&node->red, current))
			return NULL;
		if(command_check(current))
			break;
		node->args = make_arg_list(&node->args, *current);
		*current = (*current)->next;
	}
	return node;
}

t_narg *make_arg_list(t_narg **args, t_token *current)
{
	t_narg *new;
	t_narg *tmp;

	new = (t_narg*)ft_calloc(1, sizeof(t_narg));
	if(!new)
		return NULL;
	new->val = ft_strdup(current->value);
	quotation_handler(new, current);
	if(!*args)
	{
		*args = new;
		new->next = NULL;
	}
	else
	{
		tmp = *args;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->next = NULL;
	}
	return *args;
}

int rd_handler(t_nred *node, t_token **current)
{	
	
	if((*current)->type == I_RED)
		node->type = ND_INPUT;
	else if((*current)->type == O_RED)
		node->type = ND_OUTPUT;
	else if ((*current)->type == APPEND)
		node->type = ND_APPEND;
	else 
		node->type = ND_HEREDOC;
	*current = (*current)->next;
	if(!*current)
		return printf("minihsell: syntax error near unexpected token `newline'\n"), 1;
	if((*current)->type != WORD)
		return printf("minishell: syntax error near unexpected token '%s'\n", (*current)->value), 1;
	node->filename = ft_strdup((*current)->value); //current->type != word return -1
	if(!node->filename)
		return 1;
	*current = (*current)->next;
	return 0;
}


void quotation_handler(t_narg *new, t_token *current)
{
	if(current->quote == SINGLE)
		new->q_state = ND_SINGLE;
	else if(current->quote == DOUBLE)
		new->q_state = ND_DOUBLE;
	else
		new->q_state = ND_DEF;
}

