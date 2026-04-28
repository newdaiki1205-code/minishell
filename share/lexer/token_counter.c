/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_counter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:39:26 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/23 20:03:07 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

int	token_count(char *str)
{
	int	pos;
	int	num;

	pos = 0;
	num = 0;
	while (str[pos])
	{
		pos += rule_1(&str[pos]);
		if (str[pos])
			num++;
		else
			break ;
		if (str[pos] == '>' || str[pos] == '<' || str[pos] == '|')
			pos += rule_2(&str[pos]);
		else
		{
			if (case_not_operater(&str[pos]) < 0)
				return (-1);
			pos += case_not_operater(&str[pos]);
		}
	}
	return (num);
}

int	case_not_operater(char *str)
{
	if (*str == 34 || *str == 39)
	{
		if (rule_4(str) < 0)
			return (-1);
		return (rule_4(str));
	}
	else
	{
		if (rule_5(str) < 0)
			return (-1);
		return (rule_5(str));
	}
}
