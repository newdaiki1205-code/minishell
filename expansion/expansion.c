/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 13:22:34 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/12 17:31:22 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

void	expansion(t_node *tree, t_env *env)
{
	if (tree->lhs)
		expansion(tree->lhs, env);
	if (tree->type == ND_COMMAND)
		tree->args = traverse_args(tree->args, env);
	if (tree->rhs)
		expansion(tree->rhs, env);
}

t_nword	*traverse_args(t_nword *args, t_env *env)
{
	t_nword	*tmp;

    tmp = args;
	while (tmp)
	{
		if ((tmp->q_state == ND_DEF || tmp->q_state == ND_DOUBLE)
			&& ft_strchr(tmp->val, '$'))
		{
			tmp->val = expand_val(tmp->val, env);
			if (!tmp->val)
				return (NULL);
            //printf("%s\n", tmp->val);
		}
        tmp = tmp->next;
	}
    return args;
}

char *expand_val(char *val, t_env *env)
{
    char *doller_pos;
    char *new;

    doller_pos = ft_strchr(val, '$');
    // if(*(doller_pos + 1) == '?') //need to ask Nur san
    //     return print_endval();
    if(*(doller_pos + 1) == '{')
    {
        if(!ft_strchr(val, '}'))
            return printf("bad substitution\n"), NULL;
        new = case_closed(val, env);   
    }
    else
        new = case_not_closed(val, env);
    free(val);
    if(!new)
        return NULL;
    return new;
}

char *case_closed(char *val, t_env *env)
{
    char *new;
    char *search_key;
    char *re_enval;
    int cp_size;
    size_t size;
    
    cp_size = ft_strchr(val, '}') - ft_strchr(val, '{') - 1;
    search_key = ft_strndup(ft_strchr(val, '{') + 1, cp_size);
    if(!search_key)
        return NULL;
    re_enval = search_env(env, search_key);
    if(!re_enval)
        return NULL;
    size = ft_strlen(val) - (ft_strlen(search_key) + 3) + ft_strlen(re_enval);
    new = make_new_str(val, search_key, re_enval, size);
    if(!new)
        return NULL;
    return new;
}

char *case_not_closed(char *val, t_env *env)
{
    (void)val;
    (void)env;
    return NULL;
}

char *make_new_str(char *src, char *enkey, char *enval, size_t size)
{
    char *new;
    size_t i;
    size_t j;
    size_t key_size;
    size_t val_size;    

    new = (char*)ft_calloc(size + 1, sizeof(char));
    if(!new)
        return NULL;
    i = 0;
    j = 0;
    key_size = ft_strlen(enkey);
    val_size = ft_strlen(enval);
    while(i < size)
    {
        if(src[i] == '$')
        {
            ft_memcpy(&new[i], enval, val_size);
            i += val_size;
            j = j + key_size + 3;
        }
        else
        {
            new[i] = src[j];
            i++;
            j++;
        }
    }
    new[size] = '\0';
    return new;
}



