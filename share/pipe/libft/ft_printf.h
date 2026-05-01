/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:06:38 by nhamad            #+#    #+#             */
/*   Updated: 2025/11/06 12:06:43 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
size_t	handle_char(va_list args);
size_t	handle_str(va_list args);
size_t	handle_nbr(va_list args);
size_t	handle_pct(void);
size_t	handle_hex(va_list args, char c);
size_t	handle_ptr(va_list args);
size_t	handle_unbr(va_list args);
size_t	print_hex(unsigned int n, const char *base);

#endif
