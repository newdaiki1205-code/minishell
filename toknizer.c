/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toknizer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 20:36:08 by dshirais          #+#    #+#             */
/*   Updated: 2026/03/30 20:37:58 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

t_token	*toknizer(t_token *head, char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
	{
		head = make_new_token(head, splited[i]);
		i++;
	}
	return (head);
}
