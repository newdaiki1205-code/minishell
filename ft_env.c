/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:24:38 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/09 16:24:17 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef struct s_env
{
    char *key;
    char *value;
    struct s_env *next;
}   t_env;

char *key_is(char *src)
{
    char *key;
    size_t len;

    len = 0;
    while(src[len])
    {
        if(src[len] == '=')
            break;
        len++;
    }
    key = (char*)ft_calloc(len + 1, sizeof(char));
    if(!key)
        return NULL;
    key = ft_memcpy(key, src, len);
    key[len] = '\0';
    return key;    
}

char *value_is(char *src)
{
    char *value;
    char *start;
    int pos;
    int len;

    pos = 0;
    while(src[pos] != '=')
        pos++;
    len = ft_strlen(src) - (pos + 1);
    value = (char*)ft_calloc(len + 1, sizeof(char));
    if(!value)
        return NULL;
    start = ft_strchr(src, '=') + 1;
    value = ft_memcpy(value, start, len);
    value[len] = '\0';
    return value;
}

int copy_keyvalue(t_env *new, char *src)
{
    new->key = key_is(src);
    if(!new->key)
        return 1;
    new->value = value_is(src);
    if(!new->value)
        return 1;
    return 0;
}

t_env *make_new_list(t_env **head, char *env)
{
    t_env *new;
    t_env *tmp;

    new = (t_env*)ft_calloc(1, sizeof(t_env));
    if(!new)
        return NULL;
    if(copy_keyvalue(new, env))
        return NULL;
    if(!*head)
        *head = new;
    else
    {
        tmp = *head;
        while(tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
    return *head;
}

t_env *cp_env(char **env)
{
    int i;
    t_env *head;

    if(!env)
        return NULL;
    head = NULL;
    i = 0;
    while(env[i])
    {
        head = make_new_list(&head, env[i]);
        if(!head)
            return NULL;
        i++;
    }
    return head;
}

void print_env(t_env* head)
{
    while(head)
    {
        printf("%s=%s\n", head->key, head->value);
        head = head->next;
    }
}

int main (int ac, char **av, char **env)
{
    t_env *head;

    (void)ac;
    (void)av;
    
    head = cp_env(env);
    print_env(head);
    return 0;
}
