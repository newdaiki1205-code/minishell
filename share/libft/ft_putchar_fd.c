/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:57:13 by dshirais          #+#    #+#             */
/*   Updated: 2025/10/13 14:52:33 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
//#include <stdio.h>
// int	main(void)
// {
// 	int fd;
// 	char c = 'a';

// 	fd = open("test.txt", O_RDWR | O_TRUNC | O_CREAT, 0700);
// 	if (fd == -1)
// 		return (1);
// 	printf("fd = %d\n", fd);
// 	ft_putchar_fd(c, fd);
// 	close(fd);
// 	ft_putchar_fd('\0', 1);
// 	return (0);
// }