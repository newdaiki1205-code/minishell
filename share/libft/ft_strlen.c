/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:58:54 by dshirais          #+#    #+#             */
/*   Updated: 2025/10/09 19:29:32 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
// #include <stdio.h>
// #include <string.h>
// #include "libft.h"

// int main(void)
// {
// 	const char *s1 = "Hello world";
// 	const char *s2 = "";
// 	printf("ft_strlen('Hello world') = %zu | strlen('Hello world') = %zu\n",
// ft_strlen(s1), strlen(s1));
//no 	printf("ft_strlen('') = %zu | strlen('') = %zu\n", ft_strlen(s2),
//		strlen(s2));
// 	return (0);
// }