/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 20:30:03 by dshirais          #+#    #+#             */
/*   Updated: 2026/03/31 15:55:25 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

int	main(void)
{
	t_token *tokens;
	char **splited;
	char *input;

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
		print_tokeninfo(tokens);
		free_split(splited);
		free_tokens(tokens);
		free(input);
	}
	rl_clear_history();
	return (0);
}

