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

	node = (t_node *)ft_calloc(1, sizeof(t_node));
	node->type = kind;
	node->lhs = lhs;
	node->rhs = rhs;
	return (node);
}

bool	command_check(t_token **current)
{
	if(!current || !*current)
		return true;
	if((*current)->type != PIPE)
		return false;
	return true;
}

bool	pipe_check(t_token **current)
{
	if(!current || !*current)
		return false;
	if((*current)->type != PIPE)
		return false;
	*current = (*current)->next;
	return true;
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
	if((*current)->type != WORD)
		return printf("syntax error near unexpected token '%s'\n", (*current)->value), 1;
	node->filename = ft_strdup((*current)->value); //current->type != word return -1
	if(!node->filename)
		return 1;
	*current = (*current)->next;
	return 0;
}

t_node *new_node_command(t_token **current)
{
	t_node *node;

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

t_nword *make_arg_list(t_nword **args, t_token *current)
{
	t_nword *new;
	t_nword *tmp;

	new = (t_nword*)ft_calloc(1, sizeof(t_nword));
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

void quotation_handler(t_nword *new, t_token *current)
{
	if(current->quote == SINGLE)
		new->q_state = ND_SINGLE;
	else if(current->quote == DOUBLE)
		new->q_state = ND_DOUBLE;
	else
		new->q_state = ND_DEF;
}

// t_node	*new_node_word(t_token *current)
// {
// 	t_node	*node;

// 	node = calloc(1, sizeof(t_node));
// 	node->type = ND_WORD;
// 	node->head = make_wordlist(current, &node->head);
// 	return (node);
// }

// t_nword *make_wordlist(t_token *current, t_nword **head)
// {
// 	t_nword *new;
// 	t_nword *tmp;

// 	new = calloc(1, (sizeof(t_nword)));
// 	if(!new)
// 		return NULL;
// 	new->val = current->value;
// 	new->q_state = current->quote;
// 	if(!*head)
// 	{
// 		*head = new;
// 		new->next = NULL;
// 	}
// 	else
// 	{
// 		tmp = *head;
// 		while (tmp->next)
// 			tmp = tmp->next;
// 		tmp->next = new;
// 		new->next = NULL;
// 	}
// 	return head;
// }

// t_node	*new_node_redirect(char *val)
// {
// 	t_node	*node;

// 	node = calloc(1, sizeof(t_node));
// 	node->type = ND_IO_RED;
// 	node->val = val;
// 	return (node);
// }

// bool	command_check(t_token *current)
// {
// 	if (!current || current->type == PIPE)
// 		return (false);
// 	//current = current->next;
// 	return (true);
// }
