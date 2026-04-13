/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 13:22:34 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/13 20:14:36 by dshirais         ###   ########.fr       */
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

t_narg	*traverse_args(t_narg *args, t_env *env)
{
	t_narg	*tmp;

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
    if(!new)
        return free(val), NULL;
    return new;
}

char *case_closed(char *val, t_env *env)
{
    char *new;
    char *search_key;
    char *re_enval;
    int cp_size;
    
    cp_size = ft_strchr(val, '}') - ft_strchr(val, '{') - 1;
    search_key = ft_strndup(ft_strchr(val, '{') + 1, cp_size);
    if(!search_key)
        return NULL;
    re_enval = search_env(env, search_key);
    if(!re_enval)
        return NULL;
    new = make_new_str(val, search_key, re_enval);
    if(!new)
        return NULL;
    return new;
}
