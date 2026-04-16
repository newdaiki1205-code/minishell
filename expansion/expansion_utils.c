/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 16:29:56 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/16 15:01:19 by dshirais         ###   ########.fr       */
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
        if(!ft_strcmp(tmp->key, search_key))
            return tmp->value;
        tmp = tmp->next;
    }
    re = (char*)ft_calloc(1, sizeof(char));
    if(!re)
        return NULL;
    return re;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;
	
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (!s1[i] && !s2[i])
		return (0);
	return (1);
}

char *make_new_str(char *src, char *enkey, char *enval)
{
    char *new;
	size_t size;
    size_t i;
    size_t j;
    size_t key_size;
    size_t val_size;    

	// size = ft_strlen(src) - (ft_strlen(enkey) + 1) + ft_strlen(enval);
    size = ft_strlen(src) - (ft_strlen(enkey) + 3) + ft_strlen(enval);
    new = (char*)ft_calloc(size + 1, sizeof(char));
    if(!new)
        return NULL;
    i = 0;
    j = 0;
    key_size = ft_strlen(enkey);
    val_size = ft_strlen(enval);
    while(i < size)
    {
        if(src[j] == '$')
        {
            ft_memcpy(&new[i], enval, val_size);
            i += val_size;
            j = j + key_size + 3;
            break;
        }
        else
        {
            new[i] = src[j];
            i++;
            j++;
        }
    }
    while(i < size)
    {
        new[i] = src[j];
        i++;
        j++;
    }
    new[size] = '\0';
    return new;
}
