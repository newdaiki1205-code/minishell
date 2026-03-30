/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:23:14 by dshirais          #+#    #+#             */
/*   Updated: 2025/10/09 19:58:39 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <bsd/string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
// #include <stdio.h>
// #include <string.h>
// #include "libft.h"

// int main(void)
// {
// 	char src[] = "Hello";
// 	char dst1[10];
// 	char dst2[10];

// 	size_t r1 = ft_strlcpy(dst1, src, sizeof(dst1));
// 	size_t r2 = strlcpy(dst2, src, sizeof(dst2));

// 	printf("ft_strlcpy ret=%zu (%s) | strlcpy ret=%zu (%s)\n", r1, dst1, r2,
//		dst2);
// 	return (0);
// }