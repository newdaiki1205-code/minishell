/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:18:25 by dshirais          #+#    #+#             */
/*   Updated: 2025/10/09 19:27:12 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	newnode->next = NULL;
	return (newnode);
}
// #include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
//     t_list *node = ft_lstnew("");
//     printf("ft_lstnew content: %s\n", (char *)node->content);
//     free(node);
//     return 0;
// }