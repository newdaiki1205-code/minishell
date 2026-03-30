/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 13:58:27 by dshirais          #+#    #+#             */
/*   Updated: 2025/10/13 14:19:18 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}

// int main()
// {
//     int fd;
//     char *s = "Hello, World!";

//     fd = open("newline.txt", O_RDWR | O_CREAT, 0700);
//     if(fd == -1)
//         return (1);
//     ft_putendl_fd(s, fd);
//     close(fd);
//     return (0);
// }