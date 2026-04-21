/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_not_closed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 17:06:42 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/21 17:22:48 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "excution.h"

char *case_not_closed(char *val, t_env *env, size_t *ex_len)
{
    char *new;
    char *search_key;
    char *re_enval;
    int key_size;
    
    key_size = is_valid_name(ft_strchr(val, '$') + 1);
    if(!key_size)
    {
        new = ft_strdup(val);
        free(val);
        return new;
    }
    search_key = ft_strndup(ft_strchr(val, '$') + 1, key_size);
    if(!search_key)
        return NULL;
    re_enval = search_env(env, search_key);
    if(!re_enval)
        return NULL;
    if(!*re_enval)
        new = mod_str(val, search_key);
    else
        new = make_new_ncstr(val, search_key, re_enval);
    if(!new)
        return NULL;
    *ex_len = ft_strlen(re_enval);
    free(val);
    free(search_key);
    free(re_enval); 
    return new;
}

int is_valid_name(char *str)
{
    int i;

    i = 0;
    if(!str[i])
        return 0;
    if(!ft_isalpha(str[i]) && !is_underscores(str[i]))
        return 0;
    i++;
    while(str[i] && name_check(str[i]))
        i++;
    return i;
} 

int is_underscores(char c)
{
	if(c == '_')
		return 1;
	return 0;
}

int name_check(char c)
{
	if(ft_isalnum(c) || is_underscores(c))
		return 1;
	return 0;
}

char *mod_str(char *src, char *enkey)
{
    char *new;
	size_t size;
    size_t i;
    size_t j;
    size_t key_size;

	//size = ft_strlen(src) - (ft_strlen(enkey) + 1);
    size = ft_strlen(src) - (ft_strlen(enkey) + 1);
    new = (char*)ft_calloc(size + 1, sizeof(char));
    if(!new)
        return NULL;
    i = 0;
    j = 0;
    key_size = ft_strlen(enkey);
    while(i < size)
    {
        if(src[j] == '$')
            j = j + key_size + 1;
        else
        {
            new[i] = src[j];
            i++;
            j++;
        }
    }
    // new[size] = '\0';
    return new;
}

char *make_new_ncstr(char *src, char *enkey, char *enval)
{
    char *new;
	size_t size;
    size_t i;
    size_t j;
    size_t key_size;
    size_t val_size;    

	size = ft_strlen(src) - (ft_strlen(enkey) + 1) + ft_strlen(enval);
    //printf("src: %s(%zu char), enkey: %s(%zu char), enval: %s(%zu char)\n", src, ft_strlen(src), enkey, ft_strlen(enkey), enval, ft_strlen(enval));
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
            j = j + key_size + 1;
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
    printf("%s\n", new);
    return new;
}

