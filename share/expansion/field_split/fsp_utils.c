/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fsp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 16:38:46 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/26 21:32:25 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

char	*trim_str(char *str, char *ifs)
{
	char	*new;
	int		size;
	int		head;
	int		tail;

	head = 0;
	tail = ft_strlen(str) - 1;
	while (str[head] && ft_strchr(ifs, str[head]))
		head++;
	while (tail >= 0 && ft_strchr(ifs, str[tail]))
		tail--;
	size = (tail + 1) - head;
	new = ft_strndup(&str[head], size);
	if (!new)
		return (NULL);
	return (new);
}

int	ifs_count(char *str, char *ifs)
{
	int	i;
	int	re;

	i = 0;
	re = 0;
	while (str[i++])
	{
		if (ft_strchr(ifs, str[i]))
		{
			re++;
			while (str[i] && ft_strchr(ifs, str[i]))
				i++;
		}
	}
	return (re);
}

char	*unit_gen(char *str, char *ifs)
{
	int		size;
	int		i;
	char	*new;

	size = 0;
	i = 0;
	while (str[size] && !ft_strchr(ifs, str[size]))
		size++;
	new = (char *)malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	while (i < size)
	{
		new[i] = *str;
		str++;
		i++;
	}
	new[size] = '\0';
	return (new);
}

char	**make_ifs_tab(int size, char *str, char *ifs)
{
	char	**new;
	int		i;
	int		j;

	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size)
	{
		while (str[j] && ft_strchr(ifs, str[j]))
			j++;
		new[i] = unit_gen(&str[j], ifs);
		if (!new[i])
			return (free_string(new, i), NULL);
		while (str[j] && !ft_strchr(ifs, str[j]))
			j++;
		i++;
	}
	new[i] = NULL;
	return (new);
}

char	**ifs_split(char *src, char *ifs)
{
	char	**new;
	int		size;
	char	*str;

	if (!src)
		return (NULL);
	str = trim_str(src, ifs);
	if (!str)
		return (NULL);
	size = ifs_count(str, ifs);
	new = make_ifs_tab(size, str, ifs);
	if (!new)
		return (NULL);
	free(str);
	return (new);
}
