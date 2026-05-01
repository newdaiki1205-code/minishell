/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:44:40 by nhamad            #+#    #+#             */
/*   Updated: 2026/02/03 18:09:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnbr_fd(long n, int fd)
{
	long	ln;
	size_t	count;

	count = 0;
	ln = n;
	if (ln < 0)
	{
		ft_putchar_fd('-', fd);
		ln *= -1;
		count++;
	}
	if (ln >= 10)
		count += ft_putnbr_fd((ln / 10), fd);
	count++;
	ft_putchar_fd(ln % 10 + '0', fd);
	return (count);
}
