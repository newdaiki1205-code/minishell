/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 14:53:54 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/26 19:18:09 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	command_check(t_token **current)
{
	if (!current || !*current)
		return (true);
	if ((*current)->type != PIPE)
		return (false);
	return (true);
}

bool	pipe_check(t_token **current)
{
	if (!current || !*current)
		return (false);
	if ((*current)->type != PIPE)
		return (false);
	*current = (*current)->next;
	return (true);
}
