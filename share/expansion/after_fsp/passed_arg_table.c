/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   passed_arg_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 18:36:06 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/26 20:44:50 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

int	concat_args(t_node *tree)
{
	if (tree->lhs)
		concat_args(tree->lhs);
	if (tree->type == ND_COMMAND && tree->args)
	{
		tree = make_arg_tab(tree);
		if (!tree)
			return (1);
	}
	if (tree->rhs)
		concat_args(tree->rhs);
	return (0);
}

t_node	*make_arg_tab(t_node *node)
{
	t_narg	*current;
	int		size;
	int		i;

	current = node->args;
	size = args_count(current);
	node->argument = (char **)malloc(sizeof(char *) * (size + 1));
	if (!node->argument)
		return (NULL);
	i = 0;
	while (i < size)
	{
		node->argument[i] = ft_strdup(current->val);
		if (!node->argument[i])
			return (free_string(node->argument, i), NULL);
		current = current->next;
		i++;
	}
	node->argument[size] = NULL;
	current = node->args;
	while (current->next)
		restructure_list(current, current->next);
	free_args(current);
	return (node);
}

int	args_count(t_narg *head)
{
	int		i;
	t_narg	*current;

	i = 0;
	current = head;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}
