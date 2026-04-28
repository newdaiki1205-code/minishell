/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:02:29 by dshirais          #+#    #+#             */
/*   Updated: 2025/10/09 19:56:27 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newnode;
	t_list	*newlist;
	t_list	*return_lst;

	newlist = ft_lstnew(f(lst->content));
	if (!newlist)
		return (NULL);
	lst = lst->next;
	return_lst = newlist;
	while (lst)
	{
		newnode = ft_lstnew(f(lst->content));
		if (!newnode)
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		newlist->next = newnode;
		lst = lst->next;
		newlist = newlist->next;
	}
	return (return_lst);
}

// #include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// void *dup_content(void *content)
// {
//     return ft_strdup((char *)content);
// }

// void del(void *content)
// {
//     free(content);
// }

// int main(void)
// {
//     t_list *a = ft_lstnew(ft_strdup("one"));
//     t_list *b = ft_lstnew(ft_strdup("two"));
//     t_list *c = ft_lstnew(ft_strdup("three"));
//     a->next = b;
//     b->next = c;

//     t_list *new = ft_lstmap(a, dup_content, del);

//     t_list *tmp = new;
//     while (tmp)
//     {
//         printf("%s\n", (char *)tmp->content);
//         tmp = tmp->next;
//     }

//     ft_lstclear(&a, del);
//     ft_lstclear(&new, del);
//     return 0;
// }
