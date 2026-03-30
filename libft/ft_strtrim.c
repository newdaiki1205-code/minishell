/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:09:57 by dshirais          #+#    #+#             */
/*   Updated: 2025/10/13 14:29:30 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	strlen;

	if (!s1 || !set)
		return (ft_strdup(""));
	len = ft_strlen(s1);
	i = 0;
	while (s1[i] && isset(s1[i], set))
		i++;
	while (len > i && s1[len - 1] && isset(s1[len - 1], set))
		len--;
	strlen = len - i;
	str = (char *)malloc(sizeof(char) * (strlen + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1 + i, strlen);
	str[strlen] = '\0';
	return ((char *)str);
}
// #include <stdio.h>
// #include "libft.h"

// int main(void)
// {
// 	char *s1 = "";
// 	char *set = "";
// 	char *trimmed = ft_strtrim(s1, set);
// 	printf("ft_strtrim(\"%s\", \"%s\") = \"%s\"\n", s1, set, trimmed);
// 	free(trimmed);
// 	return (0);
// }