/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:28:14 by nhamad            #+#    #+#             */
/*   Updated: 2025/10/10 12:28:17 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*ps;
	unsigned char		*pd;
	size_t				i;

	if (dest == src || n == 0)
		return (dest);
	ps = (const unsigned char *)src;
	pd = (unsigned char *)dest;
	i = 0;
	if (pd < ps)
	{
		while (i < n)
		{
			pd[i] = ps[i];
			i++;
		}
	}
	else
	{
		while (n--)
			pd[n] = ps[n];
	}
	return (dest);
}
