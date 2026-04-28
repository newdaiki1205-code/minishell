/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:29:26 by dshirais          #+#    #+#             */
/*   Updated: 2025/10/09 19:09:55 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <bsd/string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *)big);
	if (ft_strlen(big) < len)
		len = ft_strlen(big);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (i + j < len && big[i + j] == little[j] && little[j])
		{
			if (!little[j + 1])
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
// #include <stdio.h>
// #include <string.h>
// #include "libft.h"

// int main(void)
// {
// 	const char *big = "Hello World!";
// 	const char *little = "World";

// 	char *p1 = ft_strnstr(big, little, 12);
// 	char *p2 = strnstr(big, little, 12);
// 	printf("ft_strnstr: %s | strnstr: %s\n", p1, p2);

// 	p1 = ft_strnstr(big, "test", 12);
// 	p2 = strnstr(big, "test", 12);
// 	printf("ft_strnstr (not found): %p | strnstr: %p\n", (void*)p1, (void*)p2);
// 	return 0;
// }