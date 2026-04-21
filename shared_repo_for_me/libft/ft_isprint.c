/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:53:57 by dshirais          #+#    #+#             */
/*   Updated: 2025/10/09 19:58:11 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (16384);
	return (0);
}
// #include <stdio.h>
// #include <ctype.h>
// #include "libft.h"

// int main(void)
// {
// 	printf("ft_isprint('A') = %d | isprint('A') = %d\n", ft_isprint('A'),
//		isprint('A'));
// 	printf("ft_isprint(31) = %d | isprint(31) = %d\n", ft_isprint(31),
//		isprint(31));
// 	printf("ft_isprint(127) = %d | isprint(127) = %d\n", ft_isprint(127),
//		isprint(127));
// 	return (0);
// }