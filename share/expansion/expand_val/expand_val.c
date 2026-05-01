/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_val.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 22:25:32 by dshirais          #+#    #+#             */
/*   Updated: 2026/05/01 22:35:14 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

// char	*expand_val(t_narg *node, t_env *env, int exit_status)
// {
// 	char	*new;
// 	char	*re;
// 	size_t	ex_len;
// 	size_t	pos;
// 	size_t	copy_len;

// 	re = NULL;
// 	while (*node->val)
// 	{
// 		num_init(&ex_len, &pos, node->val);
// 		new = expand_one_val(node->val, env, &ex_len, exit_status);
// 		if (!new)
// 			return (free(node->val), NULL);
// 		if (!ex_len)
// 			copy_len = how_many_copy(node->q_state, new);
// 		else
// 			copy_len = pos + ex_len;
// 		re = make_reval(re, new, copy_len);
// 		if (!re)
// 			return (free(node->val), free(new), NULL);
// 		node->val = update_src(new + copy_len, new);
// 		if (!node->val)
// 			return (NULL);
// 	}
// 	return (free(node->val), re);
// }

char	*expand_val(t_narg *node, t_env *env, int exit_status)
{
	char		*new;
	char		*re;
	t_expand	*info;

	re = NULL;
	info = (t_expand *)ft_calloc(1, sizeof(t_expand));
	if (!info)
		return (free(node->val), NULL);
	while (*node->val)
	{
		num_init(info, node->val);
		new = expand_one_val(node->val, env, info, exit_status);
		if (!new)
			return (free(info), NULL);
		re = make_reval(re, new, how_many_copy(info, node->q_state, new));
		if (!re)
			return (free(node->val), free(new), NULL);
		node->val = update_src(new + info->copy_len, new);
		if (!node->val)
			return (free(info), NULL);
	}
	free(info);
	return (free(node->val), re);
}

char	*expand_one_val(char *src, t_env *env, t_expand *info, int exit_status)
{
	char	*new;

	if (!ft_strchr(src, '$'))
		new = src;
	else if (*(ft_strchr(src, '$') + 1) == '{')
		new = case_closed(src, env, info, exit_status);
	else
		new = case_not_closed(src, env, info, exit_status);
	if (!new)
		return (NULL);
	return (new);
}

char	*make_reval(char *src, char *new, size_t copy_len)
{
	char	*re;

	if (!src)
		re = ft_strndup(new, copy_len);
	else
		re = ft_strnjoin(src, new, copy_len);
	if (src)
		free(src);
	if (!re)
		return (NULL);
	return (re);
}

char	*update_src(char *src, char *new)
{
	char	*re;

	re = ft_strdup(src);
	if (!re)
		return (free(new), NULL);
	free(new);
	return (re);
}
