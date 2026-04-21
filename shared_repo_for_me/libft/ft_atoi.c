/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:55:31 by dshirais          #+#    #+#             */
/*   Updated: 2025/10/09 18:27:42 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	return (res * sign);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	char	*str;
// 	int		std_res;
// 	int		ft_res;

// 	str = "-2147483648";
// 	std_res = atoi(str);
// 	ft_res = ft_atoi(str);
// 	printf("%d\n", std_res);
// 	printf("%d\n", ft_res);
// 	return (0);
// }

// int i = 0;
// while (nptr[i])
// 	i++;
// if (i > 11)
// 	return (0);