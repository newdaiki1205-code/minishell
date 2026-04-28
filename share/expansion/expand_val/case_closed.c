/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_closed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 22:32:42 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/26 18:30:18 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

char	*case_closed(char *val, t_env *env, size_t *ex_len, int exit_status)
{
	char	*new;

	if (is_closed(val))
		return (NULL);
	new = expand_inside(val, env, exit_status, ex_len);
	if (!new)
		return (free(val), NULL);
	free(val);
	return (new);
}

char	*expand_inside(char *val, t_env *env, int exit_status, size_t *ex_len)
{
	char	*new;

	if (is_exit_expand(val))
		new = case_exit_status(exit_status, val, ex_len);
	else
		new = val_in_curly_braces(val, env, ex_len);
	if (!new)
		return (NULL);
	return (new);
}

char	*case_exit_status(int exit_status, char *val, size_t *ex_len)
{
	char	*new;
	char	*search_key;
	char	*re_enval;

	search_key = ft_strdup("?");
	if (!search_key)
		return (NULL);
	re_enval = ft_itoa(exit_status);
	if (!re_enval)
		return (free(search_key), (NULL));
	new = make_new_str(val, search_key, re_enval, 3);
	if (!new)
		return (free(search_key), free(re_enval), (NULL));
	*ex_len = ft_strlen(re_enval);
	free(search_key);
	free(re_enval);
	return (new);
}

char	*val_in_curly_braces(char *val, t_env *env, size_t *ex_len)
{
	char	*new;
	char	*search_key;
	char	*re_enval;
	int		cp_size;

	cp_size = ft_strchr(val, '}') - ft_strchr(val, '{') - 1;
	search_key = ft_strndup(ft_strchr(val, '{') + 1, cp_size);
	if (!search_key)
		return (NULL);
	re_enval = search_env(env, search_key);
	if (!re_enval)
		return (free(search_key), (NULL));
	new = make_new_str(val, search_key, re_enval, 3);
	if (!new)
		return (free(search_key), free(re_enval), (NULL));
	*ex_len = ft_strlen(re_enval);
	free(search_key);
	free(re_enval);
	return (new);
}
