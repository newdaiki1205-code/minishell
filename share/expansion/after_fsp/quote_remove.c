/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 18:08:17 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/26 18:08:46 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

char	*quote_remove(t_narg *node)
{
	char	*new;
	size_t	size;
	size_t	content;
	size_t	q_start;
	char	quot;

	size = ft_strlen(node->val) - 2;
	if (node->q_state == ND_DOUBLE)
		quot = 34;
	else
		quot = 39;
	q_start = 0;
	while (node->val[q_start] && node->val[q_start] != quot)
		q_start++;
	content = ft_strlen(node->val) - (q_start + 1) - 1;
	new = (char *)ft_calloc(size + 1, sizeof(char));
	if (!new)
		return (NULL);
	ft_memcpy(new, node->val, q_start);
	ft_memcpy(&new[q_start], &node->val[q_start + 1], content);
	free(node->val);
	return (new);
}
