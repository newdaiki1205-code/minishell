/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 13:22:58 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/12 17:11:26 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#ifndef EXPANSION_H
# define EXPANSION_H

void	expansion(t_node *tree, t_env *env);

t_nword	*traverse_args(t_nword *args, t_env *env);
char *expand_val(char *val, t_env *env);
char *case_closed(char *val, t_env *env);
char *case_not_closed(char *val, t_env *env);
char *make_new_str(char *src, char *enkey, char *enval, size_t size);

char *search_env(t_env *env, char *search_key);
char	*ft_strndup(const char *s, int size);

#endif