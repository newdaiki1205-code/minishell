/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:58:26 by dshirais          #+#    #+#             */
/*   Updated: 2025/10/09 19:32:51 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
// #include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
//     t_list *a = ft_lstnew("1");
//     t_list *b = ft_lstnew("2");
//     t_list *c = ft_lstnew("3");
//     a->next = b;
//     b->next = c;
//     printf("ft_lstsize: %d\n", ft_lstsize(a));
//     free(c);
//     free(b);
//     free(a);
//     return 0;
// }