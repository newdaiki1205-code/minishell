/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:21:16 by dshirais          #+#    #+#             */
/*   Updated: 2025/10/09 19:34:18 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = ft_lstlast(*lst);
	if (!last)
		*lst = new;
	else
		last->next = new;
	new->next = NULL;
}
// #include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
//     t_list *a = ft_lstnew("Hello");
//     t_list *b = ft_lstnew("World");
//     ft_lstadd_back(&a, b);
//     printf("Last node: %s\n", (char *)ft_lstlast(a)->content);
//     free(b);
//     free(a);
//     return 0;
// }