/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:30:31 by nhamad            #+#    #+#             */
/*   Updated: 2025/10/10 12:30:34 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	size_t	dlen;
	size_t	slen;
	size_t	space;

	dlen = 0;
	slen = ft_strlen(src);
	if (size != '\0')
	{
		while (dlen < size && dst[dlen] != '\0')
			dlen++;
	}
	if (dlen == size)
		return (size + slen);
	if (size > dlen + 1)
	{
		space = size - dlen - 1;
		i = -1;
		while ((size_t)++i < space && src[i] != '\0')
			dst[dlen + i] = src[i];
		dst[dlen + i] = '\0';
	}
	return (dlen + slen);
}
