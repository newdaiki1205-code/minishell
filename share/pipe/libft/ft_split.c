/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:45:23 by nhamad            #+#    #+#             */
/*   Updated: 2025/10/21 14:45:26 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t	in_word;
	size_t	word_counter;

	word_counter = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			word_counter++;
			in_word = 1;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (word_counter);
}

static char	*next_word(char const **s, char c)
{
	const char	*start;
	size_t		len;

	while (**s == c && **s)
		(*s)++;
	start = *s;
	while (**s != c && **s)
		(*s)++;
	len = *s - start;
	return (ft_substr(start, 0, len));
}

static char	**cleanup(char **res, ssize_t filled)
{
	while (filled > 0)
	{
		free(res[filled - 1]);
		filled--;
	}
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	wordcount;
	size_t	i;
	char	**res;

	if (!s)
	{
		return (NULL);
	}
	wordcount = word_count(s, c);
	res = malloc(sizeof(char *) * (wordcount + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < wordcount)
	{
		res[i] = next_word(&s, c);
		if (!res[i])
			return (cleanup(res, i));
		i++;
	}
	res[i] = NULL;
	return (res);
}
