/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parser_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:22:48 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/30 16:50:19 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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

void	free_redirection(t_nred *head)
{
	t_nred	*tmp;

	while (head)
	{
		tmp = head->next;
		if (head->filename)
			free_args(head->filename);
		if (head->delimiter)
			free_args(head->delimiter);
		if (head->infile_head)
			free_args(head->infile_head);
		if (head->here_doc)
			free_arg_table(head->here_doc);
		free(head);
		head = tmp;
	}
}

// void	free_infile(t_infile *head)
// {
// 	t_infile	*tmp;

// 	while (head)
// 	{
// 		tmp = head->next;
// 		if (head->str)
// 			free(head->next);
// 		free(head);
// 		head = tmp;
// 	}
// }
