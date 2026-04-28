/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:16:03 by dshirais          #+#    #+#             */
/*   Updated: 2025/10/09 19:38:25 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
// #include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>

// void print_content(void *content)
// {
//     printf("%s\n", (char *)content);
// }

// int main(void)
// {
//     t_list *a = ft_lstnew("one");
//     t_list *b = ft_lstnew("two");
//     t_list *c = ft_lstnew("three");
//     a->next = b;
//     b->next = c;
//     ft_lstiter(a, print_content);
//     free(c);
//     free(b);
//     free(a);
//     return 0;
// }