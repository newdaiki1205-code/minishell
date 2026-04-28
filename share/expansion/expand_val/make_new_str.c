/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_new_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 15:41:07 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/24 16:29:33 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

char	*make_new_str(char *src, char *enkey, char *enval, int flag)
{
	char	*new;
	size_t	size;
	t_utils	*info;

	size = closed_or_unclosed(src, enkey, enval, flag);
	new = (char *)ft_calloc(size + 1, sizeof(char));
	if (!new)
		return (NULL);
	info = (t_utils *)malloc(sizeof(t_utils));
	if (!info)
		return (NULL);
	if (info_init(info, enkey, enval, size))
		return (NULL);
	copy_str(src, new, info, flag);
	free_utils(info);
	return (new);
}

size_t	closed_or_unclosed(char *src, char *enkey, char *enval, int flag)
{
	size_t	size;

	if (flag == 3)
		size = ft_strlen(src) - (ft_strlen(enkey) + 3) + ft_strlen(enval);
	else
		size = ft_strlen(src) - (ft_strlen(enkey) + 1) + ft_strlen(enval);
	return (size);
}

int	info_init(t_utils *info, char *envkey, char *envval, size_t size)
{
	info->enkey = ft_strdup(envkey);
	if (!info->enkey)
		return (1);
	info->enval = ft_strdup(envval);
	if (!info->enval)
		return (1);
	info->key_size = ft_strlen(envkey);
	info->val_size = ft_strlen(envval);
	info->size = size;
	return (0);
}

void	copy_str(char *src, char *new, t_utils *info, int flag)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < info->size)
	{
		if (src[j] == '$')
		{
			ft_memcpy(&new[i], info->enval, info->val_size);
			i += info->val_size;
			j = j + info->key_size + flag;
			break ;
		}
		else
			new[i++] = src[j++];
	}
	while (i < info->size)
		new[i++] = src[j++];
	new[info->size] = '\0';
}

void	free_utils(t_utils *info)
{
	if (info->enkey)
		free(info->enkey);
	if (info->enval)
		free(info->enval);
	free(info);
}
