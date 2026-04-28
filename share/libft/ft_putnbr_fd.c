/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 14:04:09 by dshirais          #+#    #+#             */
/*   Updated: 2025/10/09 13:01:19 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	res;
	int		num;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	num = n / 10;
	if (num > 0)
		ft_putnbr_fd(num, fd);
	res = n % 10 + '0';
	write(fd, &res, 1);
}

// int	main(void)
// {
// 	int fd;
// 	int n = -2147483648;

// 	fd = open("number.txt", O_RDWR | O_CREAT, 0700);
// 	if (fd == -1)
// 		return (1);
// 	ft_putnbr_fd(n, fd);
// 	close(fd);
// 	ft_putnbr_fd(NULL, 1);
// 	return (0);
// }