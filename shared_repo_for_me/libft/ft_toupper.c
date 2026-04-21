/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:22:54 by dshirais          #+#    #+#             */
/*   Updated: 2025/10/13 14:58:33 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
// #include <stdio.h>
// #include <ctype.h>
// #include "libft.h"

// int main(void)
// {
// 	printf("ft_toupper('a') = %d | toupper('a') = %d\n", ft_toupper(-1),
// 		toupper(-1));
// 	printf("ft_toupper('Z') = %d | toupper('Z') = %d\n", ft_toupper('Z'),
// 		toupper('Z'));
// 	return (0);
// }