/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_rule.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:08:57 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/13 19:49:25 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

int	rule_1(char *s) // skip space
{
	int i;

	i = 0;
	while (s[i] && (is_blank(s[i])))
		i++;
	return (i);
}

int	rule_2(char *s) // tokenize operator
{
	int i;

	i = 0;
	if (s[i] && (s[i] == '>' || s[i] == '<' || s[i] == '|'))
	{
		return (rule_3(&s[i]));
	}
	return (0);
}

int	rule_3(char *s) // tokenize append and heredoc
{
	int i;
	char c;

	i = 1;
	c = s[0];
	if(s[i] && s[i] == c)
		i++;
	// while (s[i] && s[i] == c)
	// 	i++;
	return (i);
}

// int	rule_3(char *s) // tokenize append and heredoc
// {
// 	if (*s == '<' && *(s + 1) == '<')
// 		return (1);
// 	else if (*s == '>' && *(s + 1) == '>')
// 		return (1);
// 	return (0);
// }

// int	rule_4(char *s) // handle "hello""world" as one token
// {
// 	int i;
// 	int flag;
// 	char c;

// 	i = 0;
// 	flag = 0;
// 	if (s[i] && (s[i] == 34 || s[i] == 39))
// 	{
// 		c = s[i];
// 		i++;
// 		while (s[i]) //change here if the quotation is not closed
// 		{
// 			if(s[i] == c)
// 				flag++;
// 			if(flag % 2 != 0 && is_blank(s[i]) && rule_2(&s[i]))
// 				break;
// 			i++;
// 		}
// 		if(!s[i] && flag % 2 == 0)
// 			return -1;
// 		return (i + 1);
// 	}
// 	return (0);
// }

int	rule_4(char *s) // tokenize quotation sets
{
	int i;
	int flag;
	char c;

	i = 0;
	flag = 0;
	if (s[i] && (s[i] == 34 || s[i] == 39))
	{
		c = s[i];
		i++;
		while (s[i] && s[i] != c) //change here if the quotation is not closed
		{
			if(s[i] == c)
			{
				flag = 1;
				break;
			}
			i++;
		}
		if(!s[i] && flag != 1)
			return -1;
		return (i + 1);
	}
	return (0);
}

int	rule_5(char *s) // read until space or ope
{
	int i;
	int unclosed;

	i = 0;
	while (s[i] && (s[i] >= 33 && s[i] < 127))
	{
		if (rule_2(&s[i]))
			break ;
		unclosed = rule_4(&s[i]);
		if (unclosed < 0)
			return -1;
		else if(unclosed > 0)
			break;
		i++;
	}
	// printf("return: %d\n", i);
	return (i);
}
