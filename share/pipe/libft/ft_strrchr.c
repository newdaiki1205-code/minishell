/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:31:49 by nhamad            #+#    #+#             */
/*   Updated: 2025/10/10 12:31:52 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				n;
	unsigned char	uc;

	uc = c;
	n = ft_strlen(s);
	if (s[n] == uc)
		return ((char *)&s[n]);
	while (n--)
	{
		if (s[n] == uc)
			return ((char *)&s[n]);
	}
	return (NULL);
}
