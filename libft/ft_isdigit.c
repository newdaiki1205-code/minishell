/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:00:50 by dshirais          #+#    #+#             */
/*   Updated: 2025/10/09 19:57:15 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int d)
{
	if (d >= '0' && d <= '9')
		return (2048);
	return (0);
}
// #include <stdio.h>
// #include <ctype.h>
// #include "libft.h"

// int main(void)
// {
// 	printf("ft_isdigit('0') = %d | isdigit('0') = %d\n", ft_isdigit('0'),
//		isdigit('0'));
// 	printf("ft_isdigit('9') = %d | isdigit('9') = %d\n", ft_isdigit('9'),
//		isdigit('9'));
// 	printf("ft_isdigit('a') = %d | isdigit('a') = %d\n", ft_isdigit('a'),
//		isdigit('a'));
// 	return (0);
// }