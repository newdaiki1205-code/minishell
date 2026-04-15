/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 13:22:34 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/15 20:40:08 by dshirais         ###   ########.fr       */
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
            if(tmp->q_state == ND_DEF)
                tmp = field_splitiing(tmp);
		}
        tmp = tmp->next;
	}
    return args;
}


char *expand_val(char *val, t_env *env)
{
    char *doller_pos;
    char *new;
    char *re;
    size_t ex_len;
    size_t pos;

    re = NULL;
    while(ft_strchr(val, '$'))
    {
        ex_len = 0;
        pos = 0;
        doller_pos = ft_strchr(val, '$');
        while(val[pos] && val[pos] != '$')
            pos++;
        // if(*(doller_pos + 1) == '?') //need to ask Nur san
        //     return print_endval();
        if(*(doller_pos + 1) == '{')
        {
            if(!ft_strchr(val, '}'))
                return printf("bad substitution\n"), NULL; 
            new = case_closed(val, env, &ex_len);   
        }
        else
            new = case_not_closed(val, env, &ex_len);
        if(!new)
            return free(val), NULL;
        if(!ex_len)
        {
            ex_len++;
            while(new[ex_len] && new[ex_len] != '$')
                ex_len++;
        }
        if(!re)
            re = ft_strndup(new, pos + ex_len);
        else
            re = ft_strnjoin(re, new, pos + ex_len);
        if(!re)
            return NULL;
        val = ft_strdup(new + pos + ex_len);
        free(new);
    }
    free(val);
    return re;
}

char	*ft_strnjoin(char *s1, char *s2, size_t size)
{
	size_t	sum;
	char	*str;
	size_t	i;
    size_t  j;

	if (!s1 || !s2)
		return (NULL);
	sum = ft_strlen(s1) + size;
	str = (char *)malloc(sizeof(char) * (sum + 1));
	if (!str)
		return (NULL);
	i = 0;
    j = 0;
	while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
	while (j < size)
        str[i++] = s2[j++];
	str[i] = '\0';
    free(s1);
	return (str);
}

// char *expand_val(char *val, t_env *env)
// {
//     char *doller_pos;
//     char *new;
//     size_t ex_len;
//     //char *head;

//     new = val;
//     ex_len = 0;
//     int i = 0;
//     //int flag = 0;
//     while(ft_strchr(new + i, '$'))
//     {
//         doller_pos = ft_strchr(new, '$');
//         // if(*(doller_pos + 1) == '?') //need to ask Nur san
//         //     return print_endval();
//         // while(new[i] != '$')
//         //     i++;
//         printf("%s\n", doller_pos);
//         if(*(doller_pos + 1) == '{')
//         {
//             if(!ft_strchr(new, '}'))
//                 return printf("bad substitution\n"), NULL; 
//             new = case_closed(new, env, &ex_len);   
//         }
//         else
//             new = case_not_closed(new, env, &ex_len);
//         if(!new)
//             return free(val), NULL;
//         // printf("%s %zu\n", new, ex_len);
//         // if(flag == 0)
//         // {
//         //     head = new;
//         //     flag++;
//         // }
//         i = (doller_pos - new) + ex_len;
//         //new = new + (i + ex_len);
//         printf("%s\n", new + i);
//         //free(val);
//     }
//     return new;
// }

char *case_closed(char *val, t_env *env, size_t *ex_len)
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
    *ex_len = ft_strlen(re_enval);
    free(val);
    return new;
}
