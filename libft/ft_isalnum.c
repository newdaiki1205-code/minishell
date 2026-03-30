/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:03:46 by dshirais          #+#    #+#             */
/*   Updated: 2025/10/09 19:57:36 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (8);
	return (0);
}
// #include <stdio.h>
// #include <ctype.h>
// #include "libft.h"

// int main(void)
// {
// 	printf("ft_isalnum('A') = %d | isalnum('A') = %d\n", ft_isalnum('A'),
//		isalnum('A'));
// 	printf("ft_isalnum('8') = %d | isalnum('8') = %d\n", ft_isalnum('8'),
//		isalnum('8'));
// 	printf("ft_isalnum('*') = %d | isalnum('*') = %d\n", ft_isalnum('*'),
//		isalnum('*'));
// 	return (0);
// }