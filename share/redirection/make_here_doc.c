/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_here_doc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:57:24 by dshirais          #+#    #+#             */
/*   Updated: 2026/05/01 15:21:36 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirection.h"

t_narg	*make_here_doc(t_nred *node, char *delimiter)
{
	char	*input;

	while (1)
	{
		input = readline("> ");
		if (!input)
			return (NULL);
		if (!ft_strcmp(delimiter, input))
		{
			node->here_doc_flag = 1;
			free(input);
			break ;
		}
		node->infile_head = make_heredoc_list(node->infile_head, input);
		if (!node->infile_head)
			return (NULL);
		free(input);
	}
	return (node->infile_head);
}

t_narg	*make_heredoc_list(t_narg *args, char *input)
{
	t_narg	*new;

	new = (t_narg *)malloc(sizeof(t_narg));
	if (!new)
		return (NULL);
	new->val = ft_strdup(input);
	if (!new->val)
		return (NULL);
	new->q_state = ND_DOUBLE;
	new->flag_cat = 0;
	new->next = NULL;
	if (!args)
		return (new);
	heredoc_add_back(args, new);
	return (args);
}

void	heredoc_add_back(t_narg *head, t_narg *new)
{
	t_narg	*tmp;

	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
