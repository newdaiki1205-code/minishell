/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_val_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 22:26:39 by dshirais          #+#    #+#             */
/*   Updated: 2026/05/01 22:34:54 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

size_t	dol_finder(char *val)
{
	size_t	before_dol;

	before_dol = 0;
	if (ft_strchr(val, '$'))
		before_dol = ft_strchr(val, '$') - val;
	return (before_dol);
}

void	num_init(t_expand *info, char *val)
{
	info->ex_len = 0;
	info->pos = dol_finder(val);
}

size_t	how_many_copy(t_expand *info, t_nquote q_state, char *new)
{
	size_t	i;

	i = 0;
	if (q_state != ND_DEF && ft_strlen(new) == 2)
		info->copy_len = 2;
	else if (*new)
	{
		if (!ft_strcmp(new, "$") || (!is_valid_name(new)))
		{
			info->copy_len = 1;
			return (info->copy_len);
		}
		while (new[i] && new[i] != '$')
			i++;
		info->copy_len = i;
	}
	else
		info->copy_len = 0;
	return (info->copy_len);
}

char	*ft_strnjoin(char *s1, char *s2, size_t size)
{
	size_t	sum;
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	sum = ft_strlen(s1) + size;
	str = (char *)malloc(sizeof(char) * (sum + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (j < size)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
