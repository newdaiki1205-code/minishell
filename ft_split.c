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
	char quote;

	i = 0;
	num = 0;
	while (is_space(str[i])) //delete space until the first token
		i++;
	while (str[i]) // count token = white space, operater, quotation
	{
		num++;
		while(str[i] && !is_space(str[i]) && !is_ope(str[i]) && !is_quote(str[i]))
			i++;
		if (str[i] == ' ')
		{
			printf("space %d\n", num);
			while (str[i] && is_space(str[i]))
				i++;
		}
		else if(is_ope(str[i]))
		{
			printf("ope %d\n", num);
			if(!is_space(str[i - 1]) && !is_quote(str[i - 1]) && !is_ope(str[i - 1]))
				num++;
			if (ope_continue(&str[i]))
				i++;
			i++;
			while (str[i] && is_space(str[i]))
				i++;
		}
		else if (is_quote(str[i]))
		{
			printf("quote %d\n", num);
			if(!is_space(str[i - 1]) && !is_quote(str[i - 1]) && !is_ope(str[i - 1]))
				num++;
			quote = str[i];
			i++;
			while(str[i] && str[i] != quote)
				i++;
			i++;
			while (str[i] && is_space(str[i]))
				i++;
		}
	}
	return num;
}

char	*make_unit(char *str)
{
	int		size;
	int		i;
	char	*new;
	char quote;

	size = 0;
	i = 0;
	if(is_ope(*str))
	{
		if(ope_continue(str))
			size = 2;
		else
			size = 1;
	}
	else if (is_quote(*str))
	{
		quote = str[size];
		size++;
		while(str[size] && str[size] != quote)
			size++;
		size++;
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
	char quote;

	if(*str == 34 || *str == 39)
	{
		quote = *str;
		size++;
		while(str[size] && str[size] != quote)
			size++;
		return size + 1;
	}
	while(!is_space(str[size]) && !is_ope(str[size]) &&!is_quote(str[size]))
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
	char quote;

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
		while (*str && is_space(*str))
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
		else if (*str && is_quote(*str))
		{
			quote = *str;
			str++;
			while(*str && *str!= quote)
				str++;
			str++;
		}
		else
		{
			while (*str && !is_space(*str) && !is_ope(*str) &&!is_quote(*str))
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
// 	char src[] = "echo hello";

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