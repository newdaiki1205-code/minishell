/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:34:12 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/26 18:01:12 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

t_narg	*expand_list(t_narg *src, char **tab, int size)
{
	t_narg	*current;
	int		flag;

	current = src;
	if (size == 1)
		flag = copy_the_first(tab[0], current);
	else
		flag = make_expanded_list(size, tab, current);
	if (flag)
		return (NULL);
	return (src);
}

int	make_expanded_list(int size, char **tab, t_narg *current)
{
	t_narg	*new;
	t_narg	*tmp;
	int		i;
	int		j;

	if (copy_the_first(tab[0], current))
		return (1);
	i = 1;
	j = 1;
	while (i < size)
	{
		new = gen_expanded_arg(tab[j]);
		if (!new)
			return (1);
		tmp = current->next;
		current->next = new;
		new->next = tmp;
		current = current->next;
		i++;
		j++;
	}
	return (0);
}

int	copy_the_first(char *src, t_narg *current)
{
	char	*trimed;

	trimed = ft_strdup(src);
	if (!trimed)
		return (1);
	free(current->val);
	current->val = trimed;
	return (0);
}

t_narg	*gen_expanded_arg(char *str)
{
	t_narg	*new;

	new = (t_narg *)malloc(sizeof(t_narg));
	if (!new)
		return (NULL);
	new->val = ft_strdup(str);
	new->flag_cat = 0;
	new->q_state = ND_DEF;
	return (new);
}
