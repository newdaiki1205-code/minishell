/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:06:17 by nhamad            #+#    #+#             */
/*   Updated: 2025/11/06 12:06:20 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	handle_args(const char *s, va_list args)
{
	size_t	count;

	count = 0;
	if (s[0] == '%' && s[1] == '%')
		count += handle_pct();
	if (s[0] == '%' && s[1] == 'c')
		count += handle_char(args);
	if (s[0] == '%' && s[1] == 's')
		count += handle_str(args);
	if (s[0] == '%' && (s[1] == 'i' || s[1] == 'd'))
		count += handle_nbr(args);
	if ((s[0] == '%' && s[1] == 'X') || s[1] == 'x')
		count += handle_hex(args, s[1]);
	if (s[0] == '%' && s[1] == 'p')
		count += handle_ptr(args);
	if (s[0] == '%' && s[1] == 'u')
		count += handle_unbr(args);
	return (count);
}

static int	is_conv(const char s)
{
	char	*conv;
	int		i;

	i = 0;
	conv = "cspdiuxX%";
	while (conv[i] != '\0')
	{
		if (s == conv[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	size_t	count;

	va_start(args, format);
	i = 0;
	count = 0;
	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	while (format[i] != '\0')
	{
		if ((format[i] == '%' && is_conv(format[i + 1])))
		{
			count += handle_args(&format[i], args);
			i += 2;
		}
		else
		{
			count += ft_putchar_fd(format[i], 1);
			i++;
		}
	}
	va_end(args);
	return (count);
}
