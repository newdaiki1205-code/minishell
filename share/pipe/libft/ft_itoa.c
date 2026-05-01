/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:43:12 by nhamad            #+#    #+#             */
/*   Updated: 2025/10/21 14:43:16 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digits(unsigned long n)
{
	long	tmp;
	int		digits;

	tmp = n;
	digits = 0;
	if (n == 0)
		return (1);
	while (tmp > 0)
	{
		digits++;
		tmp /= 10;
	}
	return (digits);
}

static void	write_abs_into(char *s, unsigned long nb, int end_index)
{
	if (nb == 0)
	{
		s[end_index] = '0';
		return ;
	}
	while (nb)
	{
		s[end_index--] = (char)('0' + (nb % 10));
		nb /= 10;
	}
}

char	*ft_itoa(int n)
{
	long	tmp;
	int		neg;
	int		digits;
	int		total;
	char	*res;

	tmp = (long)n;
	neg = (tmp < 0);
	if (neg)
		tmp *= -1;
	digits = get_digits(tmp);
	total = digits + neg + 1;
	res = (char *)malloc((size_t)total);
	if (!res)
		return (NULL);
	res[total - 1] = '\0';
	write_abs_into(res, tmp, total - 2);
	if (neg)
		res[0] = '-';
	return (res);
}
