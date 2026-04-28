/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 20:11:45 by dshirais          #+#    #+#             */
/*   Updated: 2025/10/09 19:03:25 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*cs;
	int		i;

	cs = (char *)s;
	i = 0;
	while (cs[i])
		i++;
	if (c == '\0')
		return (&cs[i]);
	i--;
	while (i >= 0)
	{
		if (cs[i] == (char)c)
			return (&cs[i]);
		i--;
	}
	return (NULL);
}
// #include <stdio.h>
// #include <string.h>
// #include "libft.h"

// int main(void)
// {
// 	const char *s = "banana";
// 	char *p1 = ft_strrchr(s, 'a');
// 	char *p2 = strrchr(s, 'a');
// 	printf("ft_strrchr: %s | strrchr: %s\n", p1, p2);

// 	p1 = ft_strrchr(s, 'z');
// 	p2 = strrchr(s, 'z');
// 	printf("ft_strrchr (not found): %p | strrchr: %p\n", (void*)p1, (void*)p2);
// 	return 0;
// }