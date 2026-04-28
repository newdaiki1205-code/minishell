/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:46:29 by dshirais          #+#    #+#             */
/*   Updated: 2025/10/09 19:02:30 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*cs;

	cs = (char *)s;
	while (*cs)
	{
		if (*cs == (char)c)
			return (cs);
		cs++;
	}
	if (c == '\0')
		return (cs);
	return (NULL);
}
// #include <stdio.h>
// #include <string.h>
// #include "libft.h"

// int main(void)
// {
// 	const char *s = "Hello world";
// 	char *p1 = ft_strchr(s, '\0');
// 	char *p2 = strchr(s, '\0');
// 	printf("ft_strchr: %s | strchr: %s\n", p1, p2);

// 	p1 = ft_strchr(s, 'x');
// 	p2 = strchr(s, 'x');
// 	printf("ft_strchr (not found): %p | strchr: %p\n", (void*)p1, (void*)p2);
// 	return 0;
// }