/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paser.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 20:48:36 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/03 15:09:56 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node	*parser(t_token *tokens)
{
	t_node *ret;

	ret = pipe_sequence(tokens);
	if (!ret)
		return (NULL);
	return (ret);
}