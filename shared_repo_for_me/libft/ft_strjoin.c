/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:59:50 by dshirais          #+#    #+#             */
/*   Updated: 2025/10/09 19:18:39 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	sum;
	char	*str;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	sum = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (sum + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}
// #include <stdio.h>
// #include "libft.h"

// int main(void)
// {
// 	char *s1 = "Hello";
// 	char *s2 = "World";
// 	char *joined = ft_strjoin(s1, s2);
// 	printf("ft_strjoin(\"%s\", \"%s\") = \"%s\"\n", s1, s2, joined);
// 	free(joined);
// 	return 0;
// }