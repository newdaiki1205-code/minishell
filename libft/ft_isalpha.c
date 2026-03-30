/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:54:22 by dshirais          #+#    #+#             */
/*   Updated: 2025/10/09 19:56:59 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1024);
	return (0);
}
// #include <stdio.h>
// #include <ctype.h>
// #include "libft.h"

// int main(void)
// {
// 	printf("ft_isalpha('A') = %d | isalpha('A') = %d\n", ft_isalpha('A'),
//		isalpha('A'));
// 	printf("ft_isalpha('z') = %d | isalpha('z') = %d\n", ft_isalpha('z'),
//		isalpha('z'));
// 	printf("ft_isalpha('1') = %d | isalpha('1') = %d\n", ft_isalpha('1'),
//		isalpha('1'));
// 	return (0);
// }