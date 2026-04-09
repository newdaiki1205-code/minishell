/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 20:30:03 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/09 13:43:57 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

int	main(void)
{
	char	*input;
	char	**splited;
	t_token	*tokens;
	t_node	*ast;

	while (1)
	{
		tokens = NULL;
		input = readline("minishell$ ");
		if (!input)
			break ;
		if (ft_strlen(input) > 0)
			add_history(input);
		splited = ft_split(input);
		free(input);
		if(!splited)
			continue;
		tokens = toknizer(tokens, splited);
		if (!tokens)
		{
			free_split(splited);
			continue;
		}
		print_tokeninfo(tokens);
		ast = parser(&tokens);
		if (!ast)
		{
			free_tokens(tokens);
			continue;
		}
		free_parser(ast);
	}
	clear_history();
	return (0);
}
