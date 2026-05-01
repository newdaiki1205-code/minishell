/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 20:47:39 by dshirais          #+#    #+#             */
/*   Updated: 2026/05/01 16:18:02 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_narg	*make_arg_list(t_narg **args, t_token *current)
{
	t_narg	*new;

	new = (t_narg *)malloc(sizeof(t_narg));
	if (!new)
		return (NULL);
	new->val = ft_strdup(current->value);
	if (!new->val)
		return (NULL);
	quotation_handler(new, current);
	new->flag_cat = 0;
	if (current->flag_cat)
		new->flag_cat = 1;
	arg_add_back(args, new);
	return (*args);
}

void	quotation_handler(t_narg *new, t_token *current)
{
	if (current->quote == SINGLE)
		new->q_state = ND_SINGLE;
	else if (current->quote == DOUBLE)
		new->q_state = ND_DOUBLE;
	else
		new->q_state = ND_DEF;
}

void	arg_add_back(t_narg **head, t_narg *new)
{
	t_narg	*tmp;

	if (!*head)
	{
		*head = new;
		new->next = NULL;
	}
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->next = NULL;
	}
}
