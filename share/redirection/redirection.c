/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 18:00:37 by dshirais          #+#    #+#             */
/*   Updated: 2026/05/01 16:58:09 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirection.h"

int	redirection(t_node *tree, t_env *env, int exit_status)
{
	if (tree->lhs)
	{
		if (redirection(tree->lhs, env, exit_status))
			return (1);
	}
	if (tree->type == ND_COMMAND && tree->red)
	{
		tree->red = traverse_red(tree->red, env, exit_status);
		if (!tree->red)
			return (1);
	}
	if (tree->rhs)
	{
		if (redirection(tree->rhs, env, exit_status))
			return (1);
	}
	return (0);
}

t_nred	*traverse_red(t_nred *red, t_env *env, int exit_status)
{
	t_nred	*tmp;

	tmp = red;
	while (tmp)
	{
		if (tmp->filename && ft_strchr(tmp->filename->val, '$'))
		{
			tmp->filename = traverse_args(tmp->filename, env, exit_status);
			if (!tmp->filename)
				return (NULL);
		}
		else if (tmp->delimiter)
		{
			tmp = here_doc_handler(tmp, env, exit_status);
			if (!tmp)
				return (NULL);
		}
		tmp = tmp->next;
	}
	if (red->type == ND_HEREDOC)
		red = finalize_here_doc(red);
	if (!red)
		return (NULL);
	return (red);
}

t_nred	*here_doc_handler(t_nred *node, t_env *env, int exit_status)
{
	t_nred	*tmp;
	int		q_flag;

	tmp = node;
	q_flag = 0;
	tmp->delimiter = quote_remove_delimiter(tmp->delimiter, &q_flag);
	if (!tmp->delimiter)
		return (NULL);
	tmp->infile_head = make_here_doc(tmp, tmp->delimiter->val);
	if (!tmp->infile_head && !tmp->here_doc_flag)
		return (NULL);
	if (!q_flag)
		tmp->infile_head = traverse_heredoc(tmp->infile_head, env, exit_status);
	if (!tmp->infile_head && !tmp->here_doc_flag)
		return (NULL);
	return (node);
}
