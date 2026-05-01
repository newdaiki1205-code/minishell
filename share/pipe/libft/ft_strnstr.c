/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:31:30 by nhamad            #+#    #+#             */
/*   Updated: 2025/10/10 12:31:33 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int			i;
	int			j;
	const char	*ub;
	const char	*ul;

	i = 0;
	ub = (const char *)big;
	ul = (const char *)little;
	if (ul[0] == '\0')
		return ((char *)ub);
	while ((size_t)i < len && ub[i] != '\0')
	{
		j = 0;
		if (ub[i] == ul[j])
		{
			while (ub[i + j] == ul[j] && (size_t)(i + j) < len && ul[j] != '\0')
			{
				j++;
			}
			if (ul[j] == '\0')
				return ((char *)&ub[i]);
		}
		i++;
	}
	return (NULL);
}
