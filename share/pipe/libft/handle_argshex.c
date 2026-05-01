/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:07:18 by nhamad            #+#    #+#             */
/*   Updated: 2025/11/06 12:07:20 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	handle_hex(va_list args, char c)
{
	unsigned int	n;
	const char		*base;

	n = va_arg(args, unsigned int);
	base = "0123456789ABCDEF";
	if (c == 'x')
		base = "0123456789abcdef";
	if (n == 0)
		return (ft_putchar_fd('0', 1));
	return (print_hex(n, base));
}

size_t	print_hex(unsigned int n, const char *base)
{
	size_t	count;

	count = 0;
	if (n >= 16)
		count += print_hex(n / 16, base);
	count += ft_putchar_fd(base[n % 16], 1);
	return (count);
}

size_t	print_hex_ptr(unsigned long long n, const char *base)
{
	size_t	count;

	count = 0;
	if (n >= 16)
		count += print_hex_ptr(n / 16, base);
	count += ft_putchar_fd(base[n % 16], 1);
	return (count);
}

size_t	handle_ptr(va_list args)
{
	unsigned long long	addr;
	size_t				count;

	count = 0;
	addr = (unsigned long long)va_arg(args, void *);
	if (addr == 0)
	{
		count += ft_putstr_fd("(nil)", 1);
		return (count);
	}
	count += ft_putstr_fd("0x", 1);
	count += print_hex_ptr(addr, "0123456789abcdef");
	return (count);
}
