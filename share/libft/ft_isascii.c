/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:13:22 by dshirais          #+#    #+#             */
/*   Updated: 2025/10/09 19:57:53 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
// #include <stdio.h>
// #include <ctype.h>
// #include "libft.h"

// int main(void)
// {
// 	printf("ft_isascii(65) = %d | isascii(65) = %d\n", ft_isascii(65),
//		isascii(65));
// 	printf("ft_isascii(128) = %d | isascii(128) = %d\n", ft_isascii(128),
//		isascii(128));
// 	return (0);
// }