/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:02:20 by dshirais          #+#    #+#             */
/*   Updated: 2025/10/09 18:53:59 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*pdest;
	unsigned char	*psrc;

	if (!dest && !src)
		return (NULL);
	pdest = (unsigned char *)dest;
	psrc = (unsigned char *)src;
	while (n--)
		*pdest++ = *psrc++;
	return (dest);
}
// #include <stdio.h>
// #include <string.h>
// #include "libft.h"

// int main(void)
// {
// 	char src[] = "Hello";
// 	char dst1[10];
// 	char dst2[10];

// 	ft_memcpy(dst1, src, 6);
// 	memcpy(dst2, src, 6);

// 	printf("ft_memcpy result: %s | memcpy result: %s\n", dst1, dst2);
// 	return 0;
// }