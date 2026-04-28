/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_spliting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 18:22:03 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/26 18:22:39 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

t_narg	*field_splitiing(t_narg *src, t_env *env)
{
	char	**tab;
	int		size;
	t_narg	*re;
	char	*ifs_val;

	ifs_val = search_env(env, "IFS");
	if (!ifs_val)
		return (NULL);
	if (*ifs_val)
		tab = ifs_split(src->val, ifs_val);
	else if (is_ifs(src->val))
		tab = ft_split(src->val);
	else
		return (free(ifs_val), src);
	if (!tab)
		return (free(ifs_val), NULL);
	free(ifs_val);
	size = 0;
	while (tab[size])
		size++;
	re = expand_list(src, tab, size);
	if (!re)
		return (free_tab(tab), NULL);
	free_tab(tab);
	return (re);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	is_ifs(char *str)
{
	if (ft_strchr(str, 9))
		return (1);
	if (ft_strchr(str, 10))
		return (1);
	if (ft_strchr(str, 32))
		return (1);
	return (0);
}
