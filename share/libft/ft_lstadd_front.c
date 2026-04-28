/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:40:27 by dshirais          #+#    #+#             */
/*   Updated: 2025/10/09 19:32:08 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = (*lst);
	(*lst) = new;
}
// #include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
//     t_list *a = ft_lstnew("World");
//     t_list *b = ft_lstnew("Hello");
//     ft_lstadd_front(&a, NULL);
//     printf("First node: %s\n", (char *)a->content);
//     printf("Next node: %s\n", (char *)a->next->content);
//     free(a->next);
//     free(a);
//     return 0;
// }