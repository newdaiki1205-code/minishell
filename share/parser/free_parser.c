/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 19:14:35 by dshirais          #+#    #+#             */
/*   Updated: 2026/05/01 22:24:50 by dshirais         ###   ########.fr       */
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
		free_redirection(tree->red);
	}
	if (tree->rhs)
		free_parser(tree->rhs);
	free(tree);
}

void	free_parser_error(t_node *tree)
{
	printf("free_start\n");
	if (!tree)
		return ;
	if (tree->lhs)
		free_parser_error(tree->lhs);
	if (tree->type == ND_COMMAND)
	{
		if (tree->args)
			printf("free_arg\n"), free_args(tree->args);
		if (tree->red)
			printf("free\n"),free_redirection(tree->red);
	}
	if (tree->rhs)
		free_parser_error(tree->rhs);
	printf("free_tree\n"), free(tree);
}
