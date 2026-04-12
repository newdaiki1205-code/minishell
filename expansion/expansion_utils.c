/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 16:29:56 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/12 17:11:04 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

char	*ft_strndup(const char *s, int size)
{
	//size_t	size;
	//size_t	i;
	char	*str;
    int i;

	//size = ft_strlen(s);
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

char *search_env(t_env *env, char *search_key)
{
    t_env *tmp;
    char *re;
    
    tmp = env;
    while(tmp)
    {
        if(!ft_strncmp(tmp->key, search_key, ft_strlen(search_key)))
            return tmp->value;
        tmp = tmp->next;
    }
    re = (char*)ft_calloc(1, sizeof(char));
    if(!re)
        return NULL;
    return re;
}
