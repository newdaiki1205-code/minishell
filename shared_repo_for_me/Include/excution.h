/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 13:28:29 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/12 14:35:07 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#ifndef EXCUTION_H
# define EXCUTION_H

typedef struct s_env
{
    char *key;
    char *value;
    struct s_env *next;
}   t_env;

t_env *cp_env(char **env);
t_env *make_new_list(t_env **head, char *env);
int copy_keyvalue(t_env *new, char *src);
char *key_is(char *src);
char *value_is(char *src);
void print_env(t_env* head);
void free_env(t_env* head);

#endif