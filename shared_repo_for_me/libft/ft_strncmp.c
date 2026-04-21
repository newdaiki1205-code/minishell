/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:20:18 by dshirais          #+#    #+#             */
/*   Updated: 2025/10/09 19:04:24 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
// #include <stdio.h>
// #include <string.h>
// #include "libft.h"

// int main(void)
// {
// 	printf("ft_strncmp('abc','abc',3) = %d | strncmp = %d\n",
// 		ft_strncmp("abc", "abc", 3), strncmp("abc", "abc", 3));
// 	printf("ft_strncmp('abc','abd',3) = %d | strncmp = %d\n",
// 		ft_strncmp("abc", "abd", 3), strncmp("abc", "abd", 3));
// 	printf("ft_strncmp('abc','abcd',3) = %d | strncmp = %d\n",
// 		ft_strncmp("abc", "abcd", 3), strncmp("abc", "abcd", 3));
// 	return 0;
// }