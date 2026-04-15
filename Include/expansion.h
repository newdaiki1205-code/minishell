/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 13:22:58 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/13 20:23:41 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#ifndef EXPANSION_H
# define EXPANSION_H

void	expansion(t_node *tree, t_env *env);

t_narg	*traverse_args(t_narg *args, t_env *env);
char *expand_val(char *val, t_env *env);
//char *case_closed(char *val, t_env *env);
char *case_closed(char *val, t_env *env, size_t *ex_len);



char *search_env(t_env *env, char *search_key);
char	*ft_strndup(const char *s, int size);
char *make_new_str(char *src, char *enkey, char *enval);
int	ft_strcmp(const char *s1, const char *s2);

//char *case_not_closed(char *val, t_env *env);
char *case_not_closed(char *val, t_env *env, size_t *ex_len);
int is_underscores(char c);
int is_valid_name(char *str);
int name_check(char c);
char *mod_str(char *src, char *enkey);
char *make_new_ncstr(char *src, char *enkey, char *enval);

char *field_splitiing(char *src);

char	*ft_strnjoin(char *s1, char *s2, size_t size);

#endif