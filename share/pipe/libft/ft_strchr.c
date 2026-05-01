/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:29:39 by nhamad            #+#    #+#             */
/*   Updated: 2025/10/10 12:29:41 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	ctmp;

	ctmp = c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ctmp)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == ctmp)
		return ((char *)&s[i]);
	return (NULL);
}
