/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:17:28 by dshirais          #+#    #+#             */
/*   Updated: 2025/10/13 13:56:42 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*pdest;
	unsigned char	*psrc;

	if (!dest && !src)
		return (NULL);
	pdest = (unsigned char *)dest;
	psrc = (unsigned char *)src;
	if (dest < src)
	{
		while (n--)
			*pdest++ = *psrc++;
	}
	else
	{
		pdest += n - 1;
		psrc += n - 1;
		while (n--)
			*pdest-- = *psrc--;
	}
	return (dest);
}
// #include <stdio.h>
// #include <string.h>
// #include "libft.h"

// int main(void)
// {
// 	char buf1[20] = "123456789";
// 	char buf2[20] = "123456789";

// 	ft_memmove(NULL, NULL, 5);
// 	memmove(NULL, NULL, 5);

// 	printf("ft_memmove vs memmove: %d\n", memcmp(buf1, buf2, 10));
// 	return 0;
// }