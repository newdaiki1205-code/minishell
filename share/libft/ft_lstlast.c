/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:07:24 by dshirais          #+#    #+#             */
/*   Updated: 2025/10/09 19:33:38 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	i;
	int	size;

	if (!lst)
		return (NULL);
	i = 0;
	size = ft_lstsize(lst);
	while (i < size - 1)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}
// #include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
//     t_list *a = ft_lstnew("first");
//     t_list *b = ft_lstnew("second");
//     a->next = b;
//     printf("ft_lstlast: %s\n", (char *)ft_lstlast(a)->content);
//     free(b);
//     free(a);
//     return 0;
// }