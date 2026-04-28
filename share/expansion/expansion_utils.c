/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 16:29:56 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/26 16:34:08 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

char	*ft_strndup(const char *s, int size)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (i < size)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*search_env(t_env *env, char *search_key)
{
	t_env	*tmp;
	char	*re;

	tmp = env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, search_key))
		{
			re = ft_strdup(tmp->value);
			return (re);
		}
		tmp = tmp->next;
	}
	re = (char *)ft_calloc(1, sizeof(char));
	if (!re)
		return (NULL);
	return (re);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (!s1[i] && !s2[i])
		return (0);
	return (1);
}
