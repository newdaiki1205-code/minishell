/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:08:09 by dshirais          #+#    #+#             */
/*   Updated: 2025/10/09 19:36:49 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
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
//     t_list *node = ft_lstnew("DeleteMe");
//     ft_lstdelone(node, del);
//     return 0;
// }