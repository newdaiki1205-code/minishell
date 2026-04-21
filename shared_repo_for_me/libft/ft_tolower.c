/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:38:18 by dshirais          #+#    #+#             */
/*   Updated: 2025/10/13 14:57:05 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
// #include <stdio.h>
// #include <ctype.h>
// #include "libft.h"

// int main(void)
// {
// 	printf("ft_tolower('A') = %d | tolower('A') = %d\n", ft_tolower(-1),
// 		tolower(-1));
// 	printf("ft_tolower('z') = %d | tolower('z') = %d\n", ft_tolower('z'),
// 		tolower('z'));
// 	return (0);
// }