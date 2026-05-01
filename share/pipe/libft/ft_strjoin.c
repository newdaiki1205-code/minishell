/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:30:06 by nhamad            #+#    #+#             */
/*   Updated: 2025/10/10 12:30:08 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*alloc_empty(void)
{
	char	*p;

	p = (char *)malloc(1);
	if (!p)
		return (NULL);
	p[0] = '\0';
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*res;
	size_t	s1len;
	size_t	s2len;

	if (!s1 || !s2)
		return (alloc_empty());
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	len = s1len + s2len;
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	ft_memcpy(res, s1, s1len);
	ft_memcpy(res + s1len, s2, s2len);
	res[len] = '\0';
	return (res);
}
