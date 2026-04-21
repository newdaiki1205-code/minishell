/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:10:18 by dshirais          #+#    #+#             */
/*   Updated: 2025/10/09 19:07:47 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ps;

	ps = (unsigned char *)s;
	while (n--)
	{
		if (*ps == (unsigned char)c)
			return ((void *)ps);
		ps++;
	}
	return (NULL);
}
// #include <stdio.h>
// #include <string.h>
// #include "libft.h"

// int main(void)
// {
// 	const char s[] = "abcdef";
// 	void *p1 = ft_memchr(s, 'd', 6);
// 	void *p2 = memchr(s, 'd', 6);
// 	printf("ft_memchr: %s | memchr: %s\n", (char*)p1, (char*)p2);

// 	p1 = ft_memchr(s, 'x', 6);
// 	p2 = memchr(s, 'x', 6);
// 	printf("ft_memchr (not found): %p | memchr: %p\n", p1, p2);
// 	return 0;
// }