/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:53:42 by dshirais          #+#    #+#             */
/*   Updated: 2025/10/09 19:11:56 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	size_t	i;
	char	*str;

	size = ft_strlen(s);
	i = 0;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (i < size)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include "libft.h"

// int main(void)
// {
// 	char *s1 = "libft test";
// 	char *d1 = ft_strdup(s1);
// 	char *d2 = strdup(s1);
// 	printf("ft_strdup: %s | strdup: %s\n", d1, d2);
// 	free(d1);
// 	free(d2);
// 	return 0;
// }