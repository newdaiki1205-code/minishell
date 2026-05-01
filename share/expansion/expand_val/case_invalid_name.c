/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_invalid_name.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:37:55 by dshirais          #+#    #+#             */
/*   Updated: 2026/05/01 22:36:58 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

char	*case_invalid_name(char *src, t_expand *info)
{
	char	*dol_pos;
	char	*new;

	dol_pos = ft_strchr(src, '$');
	info->ex_len = 1;
	if (!ft_strcmp(src, "$"))
		return (ft_strdup(src));
	if (!ft_isdigit(*(dol_pos + 1)))
		return (ft_strdup(src));
	info->copy_len = 1;
	new = make_char_invlid(src, dol_pos - src, &dol_pos[info->ex_len + 1]);
	if (!new)
		return (NULL);
	return (new);
}

char	*make_char_invlid(char *src, int size_before, char *restart)
{
	char	*new;
	char	*remake;

	new = ft_strndup(src, size_before);
	if (!new)
		return (NULL);
	if (!*new && !restart)
		return (new);
	if (!*new)
		remake = ft_strdup(restart);
	else
		remake = ft_strjoin(new, restart);
	if (!remake)
		return (NULL);
	free(new);
	return (remake);
}
