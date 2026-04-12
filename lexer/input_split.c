/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:49:02 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/12 14:08:41 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

char **input_split(char *str)
{
    char **new;
    int size;
    int i;
    int pos;

    if(!str)
        return NULL;
    size = token_count(str);
    printf("Num_of_Token: %d\n", size);
    if(size < 0)
        return (printf("minishell: quotation should be closed\n"), NULL);
    if(size == 0)
        return NULL; //need to fix?
    new = (char **)malloc(sizeof(char *) * (size + 1));
    if(!new)
        return NULL;
    i = 0;
    pos = 0;
    while(i < size)
    {
        pos += rule_1(&str[pos]);
        new[i] = make_unit(&str[pos]);
        if(!new[i])
            return (free_str(new, i), NULL);
        if (str[pos] == '>' || str[pos] == '<' || str[pos] == '|')
			pos += rule_2(&str[pos]);
        else if(str[pos] == 34 || str[pos] == 39)
            pos += rule_4(&str[pos]);
        else
            pos += rule_5(&str[pos]);
        i++;
    }
    new[i] = NULL;
    return (new);
}

char *make_unit(char *str)
{
    int size;
    int i;
    char *new;

    i = 0;
    if (str[0] == '>' || str[0] == '<' || str[0] == '|')
		size = rule_2(&str[0]);
    else if (str[0] == 34 || str[0] == 39)
		size = rule_4(&str[0]);
    else
        size = rule_5(&str[0]);
    new = (char *)malloc(sizeof(char) * (size + 1));
    if(!new)
        return NULL;
    while (i < size)
    {
        new[i] = str[i];
        i++;
    }
    new[size] = '\0';
    return (new);
}

void free_str(char **str, int i)
{
    i--;
    while(i >= 0)
    {
        free(str[i]);
        i--;
    }
    free(str);
}

void free_split(char **tab)
{
    int i;
    
    i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
    free(tab);
}

// int	main(void)
// {
// 	char **test;
// 	char src[] = "echo hello                |ls";

// 	test = ft_split(src);
// 	if (!test)
// 		return (1);
// 	int i = 0;
// 	while (test && test[i])
// 	{
// 		printf("%s\n", test[i]);
// 		i++;
// 	}
// 	i = 0;
// 	while (test && test[i])
// 	{
// 		free(test[i]);
// 		i++;
// 	}
// 	free(test);
// 	return (0);
// }