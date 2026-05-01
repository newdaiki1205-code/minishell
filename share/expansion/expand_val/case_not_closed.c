/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_not_closed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 17:06:42 by dshirais          #+#    #+#             */
/*   Updated: 2026/05/01 22:35:19 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

char	*case_not_closed(char *val, t_env *env, t_expand *info, int exit_status)
{
	char	*new;

	new = expand_unclosed_para(val, env, exit_status, info);
	if (!new)
		return (free(val), NULL);
	free(val);
	return (new);
}

char	*expand_unclosed_para(char *val, t_env *env, int exit_status,
		t_expand *info)
{
	char	*new;

	if ((ft_strchr(val, '$') && *(ft_strchr(val, '$') + 1) == '?'))
		new = case_exit_status(exit_status, val, info, 1);
	else if (!is_valid_name(ft_strchr(val, '$') + 1))
		new = case_invalid_name(val, info);
	else
		new = val_without_braces(val, env, info);
	if (!new)
		return (NULL);
	return (new);
}

char	*val_without_braces(char *val, t_env *env, t_expand *info)
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
	info->ex_len = ft_strlen(re_enval);
	free(search_key);
	free(re_enval);
	return (new);
}
