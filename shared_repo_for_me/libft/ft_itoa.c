/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:48:34 by dshirais          #+#    #+#             */
/*   Updated: 2025/10/09 19:21:36 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_size(int n)
{
	int	i;

	i = 0;
	if (n < 10 && n >= 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*makestr(char *str, int n, int size)
{
	int	num;

	num = n / 10;
	if (num > 0)
		str = makestr(str, num, size - 1);
	str[size - 1] = n % 10 + '0';
	return (str);
}

static char	*makestr_minus(char *str, int n, int size)
{
	int	num;

	str[0] = '-';
	n = -n;
	num = n / 10;
	if (num > 0)
		str = makestr(str, num, size - 1);
	str[size - 1] = n % 10 + '0';
	return (str);
}

static char	*int_min(char *str)
{
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*str;

	if (n == -2147483648)
	{
		str = (char *)malloc(sizeof(char) * 12);
		if (!str)
			return (NULL);
		str = int_min(str);
		return (str);
	}
	size = count_size(n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	if (n < 0)
		str = makestr_minus(str, n, size);
	else
		str = makestr(str, n, size);
	str[size] = '\0';
	return (str);
}
// #include <stdio.h>
// #include "libft.h"

// int main(void)
// {
// 	int nums[] = {0, 42, -42, 2147483647, -2147483648};
// 	for (int i = 0; i < 5; i++)
// 	{
// 		char *s = ft_itoa(nums[i]);
// 		printf("ft_itoa(%d) = \"%s\"\n", nums[i], s);
// 		free(s);
// 	}
// 	return 0;
// }