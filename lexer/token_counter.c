/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_counter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:39:26 by dshirais          #+#    #+#             */
/*   Updated: 2026/03/30 17:23:57 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

int	token_count(char *str)
{
	int pos;
	int num;

	pos = 0;
	num = 0;
	while (str[pos])
	{
		pos += rule_1(&str[pos]);
		//printf("current_pos: %d\n", pos);
		if (str[pos])
			num++;
		else
			break ;
		if (str[pos] == '>' || str[pos] == '<' || str[pos] == '|')
			pos += rule_2(&str[pos]);
		else if (str[pos] == 34 || str[pos] == 39)
			pos += rule_4(&str[pos]);
		else
			pos += rule_5(&str[pos]);
		//printf("before_space: %d\n", pos);
	}
	return (num);
}