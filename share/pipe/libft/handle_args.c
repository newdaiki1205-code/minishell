/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:07:02 by nhamad            #+#    #+#             */
/*   Updated: 2025/11/06 12:07:05 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	handle_char(va_list args)
{
	char	c;

	c = va_arg(args, int);
	return (ft_putchar_fd(c, 1));
}

size_t	handle_str(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		return (ft_putstr_fd("(null)", 1));
	return (ft_putstr_fd(str, 1));
}

size_t	handle_nbr(va_list args)
{
	long	nbr;

	nbr = va_arg(args, int);
	return (ft_putnbr_fd(nbr, 1));
}

size_t	handle_pct(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}

size_t	handle_unbr(va_list args)
{
	unsigned long	nb;
	size_t			count;

	count = 0;
	nb = (unsigned long)va_arg(args, unsigned int);
	count += ft_putnbr_fd(nb, 1);
	return (count);
}
