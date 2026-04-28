/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_val_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 22:26:39 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/26 18:30:09 by dshirais         ###   ########.fr       */
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

void	num_init(size_t *ex_len, size_t *pos, char *val)
{
	*ex_len = 0;
	*pos = dol_finder(val);
}

size_t	how_many_copy(t_nquote q_state, char *new)
{
	size_t	copy_len;
	size_t	i;

	i = 0;
	if (q_state != ND_DEF && ft_strlen(new) == 2)
		copy_len = 2;
	else if (*new)
	{
		i++;
		while (new[i] && new[i] != '$')
			i++;
		copy_len = i;
	}
	else
		return (0);
	return (copy_len);
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
