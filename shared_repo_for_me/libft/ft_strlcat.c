/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:54:32 by dshirais          #+#    #+#             */
/*   Updated: 2025/10/09 19:58:51 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <bsd/string.h>

static char	*catchar(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (size != 0 && i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	catchar(&dst[dst_len], src, size - dst_len);
	return (dst_len + src_len);
}
// #include <stdio.h>
// #include <string.h>
// #include "libft.h"

// int main(void)
// {
// 	char dst1[20] = "Hello";
// 	char dst2[20] = "Hello";
// 	char *src = " World";

// 	size_t r1 = ft_strlcat(dst1, src, sizeof(dst1));
// 	size_t r2 = strlcat(dst2, src, sizeof(dst2));

// 	printf("ft_strlcat ret=%zu (%s) | strlcat ret=%zu (%s)\n", r1, dst1, r2,
//		dst2);
// 	return (0);
// }