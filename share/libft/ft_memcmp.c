/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:18:59 by dshirais          #+#    #+#             */
/*   Updated: 2025/10/09 19:08:33 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	while (n--)
	{
		if (*ps1 != *ps2)
			return ((int)(*ps1 - *ps2));
		ps1++;
		ps2++;
	}
	return (0);
}
// #include <stdio.h>
// #include <string.h>
// #include "libft.h"

// int main(void)
// {
// 	char s1[] = "abc";
// 	char s2[] = "abd";
// 	printf("ft_memcmp('abc','abd',3) = %d | memcmp = %d\n",
// 		ft_memcmp(s1, s2, 3), memcmp(s1, s2, 3));

// 	printf("ft_memcmp('abc','abc',3) = %d | memcmp = %d\n",
// 		ft_memcmp(s1, s1, 3), memcmp(s1, s1, 3));
// 	return 0;
// }