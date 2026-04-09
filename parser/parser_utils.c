/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 14:53:54 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/09 16:17:37 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
	*current = (*current)->next; //if it is NULL? readline?
	return true;
}

void free_parser(t_node *tree)
{
    if(tree->lhs)
		free_parser(tree->lhs);
	if(tree->type == ND_COMMAND)
	{
		free_args(tree->args);
		free(tree->red.filename);
	}
	if(tree->rhs)
		free_parser(tree->rhs);
	free(tree);
}

void free_args(t_nword *args)
{
	t_nword *tmp;
	
	if(!args || !(args->val))
		return;
	while(args)
	{
		tmp = args->next;
		free(args->val);
		free(args);
		args = tmp;
	}
}

