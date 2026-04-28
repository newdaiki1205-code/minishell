/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:41:48 by dshirais          #+#    #+#             */
/*   Updated: 2025/10/16 14:57:47 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	len;
	size_t	i;

	if (!s || !f)
		return (ft_strdup(""));
	len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[len] = '\0';
	return (str);
}
// #include <stdio.h>
// #include "libft.h"

// static char plus_one(unsigned int i, char c)
// {
// 	(void)i;
// 	return c + 1;
// }

// int main(void)
// {
// 	char *s = NULL;
// 	char *res = ft_strmapi(s, plus_one);
// 	printf("ft_strmapi(\"%s\") = \"%s\"\n", s, res);
// 	free(res);
// 	return 0;
// }