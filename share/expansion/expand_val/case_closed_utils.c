/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_closed_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 18:15:17 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/26 18:16:06 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

int	is_exit_expand(char *val)
{
	char	*dol_pos;

	dol_pos = ft_strchr(val, '$');
	if (!ft_strncmp("${?}", dol_pos, 4))
		return (1);
	return (0);
}

int	is_closed(char *val)
{
	if (!ft_strchr(val, '}'))
	{
		printf("bad substitution\n");
		return (1);
	}
	return (0);
}
