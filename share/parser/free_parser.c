/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 19:14:35 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/26 19:58:09 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	free_parser(t_node *tree)
{
	if (!tree)
		return ;
	if (tree->lhs)
		free_parser(tree->lhs);
	if (tree->type == ND_COMMAND)
	{
		free_arg_table(tree->argument);
		free(tree->red.filename);
	}
	if (tree->rhs)
		free_parser(tree->rhs);
	free(tree);
}

void	free_args(t_narg *args)
{
	t_narg	*tmp;

	if (!args || !(args->val))
		return ;
	while (args)
	{
		tmp = args->next;
		free(args->val);
		free(args);
		args = tmp;
	}
}

void	free_arg_table(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_parser_error(t_node *tree)
{
	if (!tree)
		return ;
	if (tree->lhs)
		free_parser_error(tree->lhs);
	if (tree->type == ND_COMMAND)
	{
		if (tree->args)
			free_args(tree->args);
		if (tree->red.filename)
			free(tree->red.filename);
	}
	if (tree->rhs)
		free_parser_error(tree->rhs);
	free(tree);
}
