/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 13:22:34 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/26 20:27:41 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

int	expansion(t_node *tree, t_env *env, int exit_status)
{
	if (tree->lhs)
	{
		if (expansion(tree->lhs, env, exit_status))
			return (1);
	}
	if (tree->type == ND_COMMAND && tree->args)
	{
		tree->args = traverse_args(tree->args, env, exit_status);
		if (!tree->args)
			return (1);
	}
	if (tree->rhs)
	{
		if (expansion(tree->rhs, env, exit_status))
			return (1);
	}
	return (0);
}

t_narg	*traverse_args(t_narg *args, t_env *env, int exit_status)
{
	t_narg	*tmp;

	tmp = args;
	while (tmp)
	{
		if ((tmp->q_state == ND_DEF || tmp->q_state == ND_DOUBLE)
			&& ft_strchr(tmp->val, '$'))
		{
			tmp->val = expand_val(tmp, env, exit_status);
			if (!tmp->val)
				return (NULL);
			if (tmp->q_state == ND_DEF)
				tmp = field_splitiing(tmp, env);
			if (!tmp)
				return (NULL);
		}
		if (tmp->q_state != ND_DEF)
			tmp->val = quote_remove(tmp);
		if (!tmp->val)
			return (NULL);
		tmp = tmp->next;
	}
	tmp = args;
	arg_concat(tmp);
	return (args);
}
