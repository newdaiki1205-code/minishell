/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_rule.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:08:57 by dshirais          #+#    #+#             */
/*   Updated: 2026/03/30 14:26:53 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

int	rule_1(char *s) // skip space
{
	int i;

	i = 0;
	if (s[i] && (s[i] < 33 || s[i] > 127))
		i++;
	return (i);
}

int	rule_2(char *s) // tokenize operator
{
	if (*s && (*s == '>' || *s == '<' || *s == '|'))
	{
		if (*(s + 1) && rule_3(s))
			return (2);
		else
			return (1);
	}
	return (0);
}

int	rule_3(char *s) // tokenize append and heredoc
{
	if (*s == '<' && *(s + 1) == '<')
		return (1);
	else if (*s == '>' && *(s + 1) == '>')
		return (1);
	return (0);
}

int	rule_4(char *s) // tokenize quotation sets
{
	int i;
	char c;

	i = 0;
	if (s[i] && (s[i] == 34 || s[i] == 39))
	{
		c = s[i];
		i++;
		while (s[i] && s[i] != c)
			i++;
		return (i + 1);
	}
	return (0);
}

int	rule_5(char *s) // read until space or ope
{
	int i;

	i = 0;
	while (s[i] && (s[i] >= 33 && s[i] < 127) && !rule_2(s))
		i++;
	return (i);
}
