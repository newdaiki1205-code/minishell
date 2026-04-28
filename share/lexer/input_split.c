/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:49:02 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/23 19:20:14 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

t_split	*input_split(char *str)
{
	t_split	*new;
	int		size;
	int		i;
	int		pos;

	if (!str)
		return (NULL);
	size = token_count(str);
	if (size < 1)
		return (error_in_input(size));
	new = (t_split *)malloc((size + 1) * sizeof(t_split));
	if (!new)
		return (NULL);
	i = 0;
	pos = 0;
	while (i < size)
	{
		new[i] = make_unit(&str[pos], i);
		if (!new[i].val)
			return (free_str(new, i), NULL);
		pos += (rule_1(&str[pos]) + ft_strlen(new[i].val));
		i++;
	}
	new[i].val = NULL;
	return (new);
}

void	*error_in_input(int num)
{
	if (num < 0)
		return (printf("minishell: quotation should be closed\n"), NULL);
	return (NULL);
}

t_split	make_unit(char *str, int num)
{
	int		size;
	int		i;
	t_split	new;

	i = 0;
	i += rule_1(&str[i]);
	new.flag_cat = 0;
	if (num && !i)
		new.flag_cat = 1;
	if (str[i] == '>' || str[i] == '<' || str[i] == '|')
		size = rule_2(&str[i]);
	else if (str[i] == 34 || str[i] == 39)
		size = rule_4(&str[i]);
	else
		size = rule_5(&str[i]);
	new.val = (char *)malloc(sizeof(char) * (size + 1));
	if (!new.val)
		return (new);
	ft_memcpy(&new.val[0], &str[i], size);
	new.val[size] = '\0';
	return (new);
}

void	free_str(t_split *elem, int i)
{
	i--;
	while (i >= 0)
	{
		free(elem[i].val);
		i--;
	}
	free(elem);
}

void	free_split(t_split *tab)
{
	int	i;

	i = 0;
	while (tab && tab[i].val)
	{
		free(tab[i].val);
		i++;
	}
	free(tab);
}
