/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:04:59 by dshirais          #+#    #+#             */
/*   Updated: 2025/10/09 19:37:37 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	while (*lst)
	{
		temp = *lst;
		del((*lst)->content);
		*lst = (*lst)->next;
		free(temp);
	}
}
// #include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>

// void del(void *content)
// {
//     printf("Deleting: %s\n", (char *)content);
// }

// int main(void)
// {
//     t_list *a = ft_lstnew("A");
//     t_list *b = ft_lstnew("B");
//     t_list *c = ft_lstnew("C");
//     a->next = b;
//     b->next = c;
//     ft_lstclear(&a, del);
//     printf("After clear: %p\n", (void *)a);
//     return 0;
// }