/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 13:22:34 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/21 18:31:09 by dshirais         ###   ########.fr       */
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
			tmp->val = expand_val(tmp, env);
			if (!tmp->val)
				return (NULL);
			if (tmp->q_state == ND_DEF)
				tmp = field_splitiing(tmp, env);
			if (!tmp)
				return (NULL);
		}
        if (tmp->q_state != ND_DEF)
			tmp->val = quote_remove(tmp);
		if (!tmp->val)
			return (NULL);
		tmp = tmp->next;
	}
    tmp = args;
    arg_concat(tmp);
	return (args);
}

char	*quote_remove(t_narg *node)
{
	char	*new;
	size_t	size;
	size_t	content;
	size_t	q_start;
	char	quot;

    size = ft_strlen(node->val) - 2;
	if (node->q_state == ND_DOUBLE)
		quot = 34;
	else
		quot = 39;
	q_start = 0;
	while (node->val[q_start] && node->val[q_start] != quot)
		q_start++;
	content = ft_strlen(node->val) - (q_start + 1) - 1;
	new = (char *)ft_calloc(size + 1, sizeof(char));
	if (!new)
		return (NULL);
	ft_memcpy(new, node->val, q_start);
	ft_memcpy(&new[q_start], &node->val[q_start + 1], content);
	//new[size] = '\0';
	free(node->val);
	return (new);
}

void arg_concat(t_narg *head)
{
    t_narg *current;
    t_narg *next;
    char *new;

    current = head;
    while(current->next)
    {
        next = current->next;
        if(current->next && next->flag_cat)
        {
            new = ft_strjoin(current->val, next->val);
            free(current->val);
            current->val = new;
            restructure_list(current, next);
        }
        next = current->next;
        if(current->next && !next->flag_cat)
            current = current->next;
    }
}

void restructure_list(t_narg *current, t_narg *next)
{
    t_narg *tmp;

    tmp = next->next;
    free(next->val);
    free(next);
    current->next = tmp;
}


char	*expand_val(t_narg *node, t_env *env)
{
	char	*doller_pos;
	char	*new;
	char	*re;
	size_t	ex_len;
	size_t	pos;
	size_t	copy_len;

	re = NULL;
	while (ft_strchr(node->val, '$'))
	{
		ex_len = 0;
		pos = 0;
		doller_pos = ft_strchr(node->val, '$');
		while (node->val[pos] && node->val[pos] != '$')
			pos++;
		// if(*(doller_pos + 1) == '?') //need to ask Nur san
		//     return (print_endval());
		if (*(doller_pos + 1) == '{')
		{
			if (!ft_strchr(node->val, '}'))
				return (printf("bad substitution\n"), NULL);
			new = case_closed(node->val, env, &ex_len);
		}
		else
			new = case_not_closed(node->val, env, &ex_len);
		if (!new)
			return (free(node->val), NULL);
		if (!ex_len)
		{
			if (*new)
				ex_len++;
			while (new[ex_len] && new[ex_len] != '$')
				ex_len++;
		}
		if (node->q_state != ND_DEF)
        {
            if(ft_strlen(new) == 2)
                copy_len = 2;
            else
                copy_len = pos + ex_len + 1;
        }
		else
			copy_len = pos + ex_len;
		if (!re)
			re = ft_strndup(new, copy_len);
		else
			re = ft_strnjoin(re, new, copy_len);
		if (!re)
			return (NULL);
		node->val = ft_strdup(new + copy_len);
		free(new);
	}
	free(node->val);
	return (re);
}


char	*ft_strnjoin(char *s1, char *s2, size_t size)
{
	size_t	sum;
	char	*str;
	size_t	i;
	size_t	j;

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
//         //     return (print_endval());
//         // while(new[i] != '$')
//         //     i++;
//         printf("%s\n", doller_pos);
//         if(*(doller_pos + 1) == '{')
//         {
//             if(!ft_strchr(new, '}'))
//                 return (printf("bad substitution\n"), NULL);
//             new = case_closed(new, env, &ex_len);
//         }
//         else
//             new = case_not_closed(new, env, &ex_len);
//         if(!new)
//             return (free(val), NULL);
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
//     return (new);
// }

char	*case_closed(char *val, t_env *env, size_t *ex_len)
{
	char	*new;
	char	*search_key;
	char	*re_enval;
	int		cp_size;

	cp_size = ft_strchr(val, '}') - ft_strchr(val, '{') - 1;
	search_key = ft_strndup(ft_strchr(val, '{') + 1, cp_size);
	if (!search_key)
		return (NULL);
	re_enval = search_env(env, search_key);
	if (!re_enval)
		return free(search_key), (NULL);
	new = make_new_str(val, search_key, re_enval);
	if (!new)
		return free(search_key), free(re_enval), (NULL);
	*ex_len = ft_strlen(re_enval);
	free(val);
    free(search_key);
    free(re_enval);
	return (new);
}
