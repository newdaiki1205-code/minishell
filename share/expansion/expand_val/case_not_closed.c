/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_not_closed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 17:06:42 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/26 21:18:56 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

char	*case_not_closed(char *val, t_env *env, size_t *ex_len, int exit_status)
{
	char	*new;

	new = expand_unclosed_para(val, env, exit_status, ex_len);
	if (!new)
		return (free(val), NULL);
	free(val);
	return (new);
}

char	*expand_unclosed_para(char *val, t_env *env, int exit_status,
		size_t *ex_len)
{
	char	*new;

	if ((ft_strchr(val, '$') && *(ft_strchr(val, '$') + 1) == '?'))
		new = case_exit_status(exit_status, val, ex_len);
	else if (!is_valid_name(ft_strchr(val, '$') + 1))
		new = ft_strdup(val);
	else
		new = val_without_braces(val, env, ex_len);
	if (!new)
		return (NULL);
	return (new);
}

char	*val_without_braces(char *val, t_env *env, size_t *ex_len)
{
	char	*new;
	char	*search_key;
	char	*re_enval;

	search_key = ft_strndup(ft_strchr(val, '$') + 1,
			is_valid_name(ft_strchr(val, '$') + 1));
	if (!search_key)
		return (NULL);
	re_enval = search_env(env, search_key);
	if (!re_enval)
		return (NULL);
	if (!*re_enval)
		new = mod_str(val, search_key);
	else
		new = make_new_str(val, search_key, re_enval, 1);
	if (!new)
		return (NULL);
	*ex_len = ft_strlen(re_enval);
	free(search_key);
	free(re_enval);
	return (new);
}

// char *make_new_ncstr(char *src, char *enkey, char *enval)
// {
//     char *new;
// 	size_t size;
//     size_t i;
//     size_t j;
//     size_t key_size;
//     size_t val_size;

// 	size = ft_strlen(src) - (ft_strlen(enkey) + 1) + ft_strlen(enval);
//     //printf("src: %s(%zu char), enkey: %s(%zu char), enval: %s(%zu char)\n",
//	src, ft_strlen(src), enkey, ft_strlen(enkey), enval, ft_strlen(enval));
//     new = (char*)ft_calloc(size + 1, sizeof(char));
//     if(!new)
//         return (NULL);
//     i = 0;
//     j = 0;
//     key_size = ft_strlen(enkey);
//     val_size = ft_strlen(enval);
//     while(i < size)
//     {
//         if(src[j] == '$')
//         {
//             ft_memcpy(&new[i], enval, val_size);
//             i += val_size;
//             j = j + key_size + 1;
//             break ;
//         }
//         else
//         {
//             new[i] = src[j];
//             i++;
//             j++;
//         }
//     }
//     while(i < size)
//     {
//         new[i] = src[j];
//         i++;
//         j++;
//     }
//     new[size] = '\0';
//     return (new);
// }
