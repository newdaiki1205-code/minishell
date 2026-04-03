/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 20:30:03 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/03 15:10:17 by dshirais         ###   ########.fr       */
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
		tokens = toknizer(tokens, splited);
		if (!tokens)
			return (free_split(splited), free(input), 1);
		print_tokeninfo(tokens);
		ast = parser(tokens);
		if (!ast)
			return (free_tokens(tokens), free_split(splited), free(input), 1);
		free_split(splited);
		free_tokens(tokens);
		free(input);
	}
	rl_clear_history();
	return (0);
}
