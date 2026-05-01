/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 13:22:58 by dshirais          #+#    #+#             */
/*   Updated: 2026/05/01 22:36:20 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

# include "excution.h"
# include "parser.h"
# include "std.h"

typedef struct s_utils
{
	char	*enkey;
	char	*enval;
	size_t	key_size;
	size_t	val_size;
	size_t	size;
}			t_utils;

typedef struct s_expand
{
	size_t	ex_len;
	size_t	pos;
	size_t	copy_len;
}			t_expand;

int			expansion(t_node *tree, t_env *env, int exit_status);

t_narg		*traverse_args(t_narg *args, t_env *env, int exit_status);

char		*expand_val(t_narg *node, t_env *env, int exit_status);
char		*expand_one_val(char *src, t_env *env, t_expand *info,
				int exit_status);
char		*make_reval(char *src, char *new, size_t copy_len);
char		*update_src(char *src, char *new);

size_t		dol_finder(char *val);
void		num_init(t_expand *info, char *val);
size_t		how_many_copy(t_expand *info, t_nquote q_state, char *new);
char		*ft_strnjoin(char *s1, char *s2, size_t size);

char		*case_closed(char *val, t_env *env, t_expand *info,
				int exit_status);
char		*expand_inside(char *val, t_env *env, int exit_status,
				t_expand *info);
char		*case_exit_status(int exit_status, char *val, t_expand *info,
				int flag);
char		*val_in_curly_braces(char *val, t_env *env, t_expand *info);

int			is_exit_expand(char *val);
int			is_closed(char *val);

char		*make_new_str(char *src, char *enkey, char *enval, int flag);
size_t		closed_or_unclosed(char *src, char *enkey, char *enval, int flag);
int			info_init(t_utils *info, char *envkey, char *envval, size_t size);
void		copy_str(char *src, char *new, t_utils *info, int flag);
void		free_utils(t_utils *info);

char		*search_env(t_env *env, char *search_key);
char		*ft_strndup(const char *s, int size);
int			ft_strcmp(const char *s1, const char *s2);

char		*case_not_closed(char *val, t_env *env, t_expand *info,
				int exit_status);
char		*expand_unclosed_para(char *val, t_env *env, int exit_status,
				t_expand *info);
char		*val_without_braces(char *val, t_env *env, t_expand *info);

int			is_underscores(char c);
int			is_valid_name(char *str);
int			name_check(char c);
char		*mod_str(char *src, char *enkey);

char		*case_invalid_name(char *src, t_expand *info);
char		*make_char_invlid(char *src, int size_before, char *restart);

t_narg		*field_splitiing(t_narg *src, t_env *env);
int			is_ifs(char *str);
void		free_tab(char **tab);

char		**ifs_split(char *src, char *ifs);
char		**make_ifs_tab(int size, char *str, char *ifs);
char		*unit_gen(char *str, char *ifs);
int			ifs_count(char *str, char *ifs);
char		*trim_str(char *str, char *ifs);

t_narg		*expand_list(t_narg *src, char **tab, int size);
int			make_expanded_list(int size, char **tab, t_narg *current);
int			copy_the_first(char *src, t_narg *current);
t_narg		*gen_expanded_arg(char *str);

char		*quote_remove(t_narg *node);

void		arg_concat(t_narg *head);
void		restructure_list(t_narg *current, t_narg *next);

int			concat_args(t_node *tree);
t_node		*make_arg_tab(t_node *node);
int			args_count(t_narg *head);

void		free_string(char **str, int i);

#endif