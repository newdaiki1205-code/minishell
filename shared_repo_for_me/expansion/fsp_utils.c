/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fsp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 16:38:46 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/16 17:32:06 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

char *trim_str(char *str, char *ifs)
{
	char *new;
	int size;
	int head;
	int tail;

	head = 0;
	tail = ft_strlen(str) - 1;
	while(str[head] && ft_strchr(ifs, str[head]))
		head++;
	while(tail >= 0 && ft_strchr(ifs, str[tail]))
		tail--;
	size = (tail + 1) - head;
	new = ft_strndup(&str[head], size);
	if(!new)
		return NULL;
	return new; 
}

int	ifs_count(char *str, char *ifs)
{
	int	i;
	int	re;

	i = 0;
	re = 0;
    while(str[i++])
    {
        if(ft_strchr(ifs, str[i]))
		{
			re++;
			while(str[i] && ft_strchr(ifs, str[i]))
				i++;
		}
    }
	return re;
}

char	*unit_gen(char *str, char *ifs)
{
	int		size;
	int		i;
	char	*new;

	size = 0;
	i = 0;
	while (str[size] && !ft_strchr(ifs, str[size]))
		size++;
	new = (char *)malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	while (i < size)
	{
		new[i] = *str;
		str++;
		i++;
	}
	new[size] = '\0';
	return (new);
}

// void	free_string(char **str, int i)
// {
// 	i--;
// 	while (i >= 0)
// 	{
// 		free(str[i]);
// 		i--;
// 	}
// 	free(str);
// }

char	**ifs_split(char *src, char *ifs)
{
	char	**new;
	int		size;
	int		i;
	int		j;
	char *str;

	if (!src)
		return (NULL);
	str = trim_str(src, ifs);
	if(!str)
		return NULL;
	size = ifs_count(str, ifs);
	i = 0;
	j = 0;
	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	while (i < size)
	{
		while (str[j] && ft_strchr(ifs, str[j]))
			j++;
		new[i] = unit_gen(&str[j], ifs);
		if (!new[i])
			return (free_string(new, i), NULL);
		while (str[j] && !ft_strchr(ifs, str[j]))
			j++;
		i++;
	}
	new[i] = NULL;
	if(ft_strlen(src) != ft_strlen(str))
		free(str);
	return (new);
}

// int main(void)
// {
//     char **test;
//     char src[] = "abc_ eafg_ hibj";
// 	char ifs[] = "abc";

//     test = ifs_split(src, ifs);
//     int i = 0;
//     while(test && test[i])
//     {
//         printf("%s\n", test[i]);
//         i++;
//     }
//     i = 0;
//     while(test && test[i])
//     {
//         free(test[i]);
//         i++;
//     }
//     free(test);
//     return (0);
// }