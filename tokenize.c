/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 20:30:03 by dshirais          #+#    #+#             */
/*   Updated: 2026/03/30 20:35:36 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

int	main(void)
{
	t_token *tokens;
	char **splited;
	char *input;
	int i;

	while (1)
	{
		input = readline("minishell$ ");
		if (!input)
			break ;
		if (ft_strlen(input) > 0)
			add_history(input);
		splited = ft_split(input);
        tokens = toknizer(tokens, splited);
		while (tokens)
		{
			printf("%s\n", tokens->value);
			tokens = tokens->next;
		}
		i = 0;
		while (splited && splited[i])
		{
			free(splited[i]);
			i++;
		}
		free(input);
	}
	return (0);
}