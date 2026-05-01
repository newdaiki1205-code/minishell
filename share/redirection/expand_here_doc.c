/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_here_doc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:59:20 by dshirais          #+#    #+#             */
/*   Updated: 2026/05/01 15:44:43 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirection.h"

t_narg	*quote_remove_delimiter(t_narg *del, int *flag)
{
	t_narg	*tmp;

	tmp = del;
	while (tmp)
	{
		if (tmp->q_state != ND_DEF)
		{
			tmp->val = quote_remove(tmp);
			if (!*flag)
				*flag = 1;
		}
		if (!tmp->val)
			return (NULL);
		tmp = tmp->next;
	}
	tmp = del;
	arg_concat(tmp);
	return (del);
}

t_narg	*traverse_heredoc(t_narg *args, t_env *env, int exit_status)
{
	t_narg	*tmp;

	tmp = args;
	while (tmp)
	{
		if (ft_strchr(tmp->val, '$'))
		{
			tmp->val = expand_val(tmp, env, exit_status);
			if (!tmp->val)
				return (NULL);
		}
		tmp = tmp->next;
	}
	return (args);
}

t_nred	*finalize_here_doc(t_nred *node)
{
	t_nred	*last;
	t_narg	*current;
	int		size;

	last = free_except_last(node);
	current = last->infile_head;
	size = args_count(current);
	last->here_doc = make_here_doc_tab(last->infile_head, size);
	if (!last->here_doc)
		return (NULL);
	free_args(last->infile_head);
	last->infile_head = NULL;
	return (last);
}

t_nred	*free_except_last(t_nred *node)
{
	t_nred	*last;
	t_nred	*tmp;

	last = node;
	while (last && last->next)
	{
		tmp = last;
		last = last->next;
		if (tmp->filename)
			free_args(tmp->filename);
		if (tmp->delimiter)
			free_args(tmp->delimiter);
		if (tmp->infile_head)
			free_args(tmp->infile_head);
		if (tmp->here_doc)
			free_arg_table(tmp->here_doc);
		free(tmp);
	}
	return (last);
}

char	**make_here_doc_tab(t_narg *list, int size)
{
	char	**new;
	int		i;

	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new[i] = ft_strdup(list->val);
		if (!new[i])
			return (free_string(new, i), NULL);
		list = list->next;
		i++;
	}
	new[size] = NULL;
	return (new);
}
