/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalize_argument.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 18:11:23 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/26 20:05:32 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

void	arg_concat(t_narg *head)
{
	t_narg	*current;
	t_narg	*next;
	char	*new;

	current = head;
	while (current && current->next)
	{
		next = current->next;
		if (current->next && next->flag_cat)
		{
			new = ft_strjoin(current->val, next->val);
			free(current->val);
			current->val = new;
			restructure_list(current, next);
		}
		next = current->next;
		if (current->next && !next->flag_cat)
			current = current->next;
	}
}

void	restructure_list(t_narg *current, t_narg *next)
{
	t_narg	*tmp;

	tmp = next->next;
	free(next->val);
	free(next);
	current->next = tmp;
}
