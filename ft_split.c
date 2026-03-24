/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:23:05 by dshirais          #+#    #+#             */
/*   Updated: 2026/03/23 17:35:20 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	token_count(char *str) //ignore space in quotation
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (!(str[i] >= 33 && str[i] < 127)) //delete space until the first token
		i++;
	while (str[i]) // count token = white space, operater, quotation
	{
		num++;
		while(str[i] && (str[i] >= 33 && str[i] < 127) && !is_ope(str[i]))
			i++;
		if (str[i] == ' ')
		{
			while (str[i] && !(str[i] >= 33 && str[i] < 127))
				i++;
		}
		else if(is_ope(str[i]))
		{
			if(str[i - 1] != ' ')
				num++;
			if (ope_continue(&str[i]))
				i++;
			i++;
			while (str[i] && !(str[i] >= 33 && str[i] < 127))
				i++;
		}
	}
	return num;
}


int is_ope(char c)
{
	if(c == '>' || c == '<' || c == '|')
		return 1;
	return 0;
}

int ope_continue(char *c)
{
	if (*c == '<' && *(c + 1) == '<')
		return 1;
	else if (*c == '>' && *(c + 1) == '>')
		return 1;
	return 0;
}

char	*make_unit(char *str)
{
	int		size;
	int		i;
	char	*new;

	size = 0;
	i = 0;
	if(is_ope(*str))
	{
		if(ope_continue(str))
			size = 2;
		else
			size = 1;
	}
	else
		size = del_identify(str);
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

int del_identify(char *str)
{
	int size = 0;

	while((str[size] >= 33 && str[size] < 127) && !is_ope(str[size]))
		size++;
	return size;
}

void	free_str(char **str, int i)
{
	i--;
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

char	**ft_split(char *str)
{
	char	**new;
	int		size;
	int		i;

	if (!str)
		return (NULL);
	size = token_count(str);
	printf("%d\n", size);
	i = 0;
	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	while (i < size)
	{
		while (*str && !(*str >= 33 && *str < 127))
			str++;
		new[i] = make_unit(str);
		if (!new[i])
			return (free_str(new, i), NULL);
		if(*str && is_ope(*str))
		{
			if (ope_continue(str))
				str = str + 2;
			else
				str++;
		}
		else
		{
			while (*str && (*str >= 33 && *str < 127) && !is_ope(*str))
				str++;
		}
		i++;
	}
	new[i] = NULL;
	return (new);
}

// int	main(void)
// {
// 	char **test;
// 	char src[] = "echo 'hello'";

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