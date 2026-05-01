/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:32:05 by nhamad            #+#    #+#             */
/*   Updated: 2025/10/10 12:32:08 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *arr)
{
	int	i;

	i = 0;
	while (arr[i] != '\0')
	{
		if (arr[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*alloc_empty(void)
{
	char	*p;

	p = (char *)malloc(1);
	if (!p)
		return (NULL);
	p[0] = '\0';
	return (p);
}

static int	find_len(char const *s1, char const *set, int start)
{
	int	end;
	int	len;

	end = ft_strlen(s1);
	end--;
	while (end >= start && is_set(s1[end], set))
		end--;
	len = end - start + 1;
	return (len);
}

static char	*get_res(int len, char const *s1, int start)
{
	int		i;
	char	*res;

	res = malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s1[start + i];
		i++;
	}
	res[len] = '\0';
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		len;
	char	*res;

	if (!s1)
		return (NULL);
	if (!set || s1[0] == '\0')
		return (ft_strdup((char *)s1));
	end = ft_strlen(s1);
	if (end == 0)
		return (alloc_empty());
	end--;
	start = 0;
	while (s1[start] != '\0' && is_set(s1[start], set))
		start++;
	while (end >= start && is_set(s1[end], set))
		end--;
	if (start > end)
		return (alloc_empty());
	len = find_len(s1, set, start);
	res = get_res(len, s1, start);
	return (res);
}
