/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_not_closed_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 16:12:00 by dshirais          #+#    #+#             */
/*   Updated: 2026/05/01 17:28:47 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

int	is_valid_name(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	if (!ft_isalpha(str[i]) && !is_underscores(str[i]))
		return (0);
	i++;
	while (str[i] && name_check(str[i]))
		i++;
	return (i);
}

int	is_underscores(char c)
{
	if (c == '_')
		return (1);
	return (0);
}

int	name_check(char c)
{
	if (ft_isalnum(c) || is_underscores(c))
		return (1);
	return (0);
}

char	*mod_str(char *src, char *enkey)
{
	char	*new;
	size_t	size;
	size_t	i;
	size_t	j;
	size_t	key_size;

	size = ft_strlen(src) - (ft_strlen(enkey) + 1);
	new = (char *)ft_calloc(size + 1, sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	key_size = ft_strlen(enkey);
	while (i < size)
	{
		if (src[j] == '$')
		{
			j = j + key_size + 1;
			break ;
		}
		else
			new[i++] = src[j++];
	}
	ft_memcpy(&new[i], &src[j], size - i);
	return (new);
}
