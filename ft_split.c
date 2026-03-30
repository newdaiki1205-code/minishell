/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:49:02 by dshirais          #+#    #+#             */
/*   Updated: 2026/03/30 15:53:42 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

char **ft_split(char *str)
{
    char **new;
    int size;
    int i;
    int pos;

    if(!str)
        return NULL;
    size = token_count(str);
    new = (char **)malloc(sizeof(char *) * (size + 1));
    if(!new)
        return NULL;
    i = 0;
    pos = rule_1(&str[0]);
    while(i < size)
    {
        new[i] = make_unit(str[pos]);
        if(!new[i])
            return (free_str(new, i), NULL);
        if(str[pos] == 34 || str[pos] == 39)
            pos += rule_4(&str[pos]);
        else
            pos += rule_5(&str[pos]);
        i++;
    }
    new[i] = NULL;
    return (new);
}