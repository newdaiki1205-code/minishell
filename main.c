/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 20:30:03 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/16 14:45:30 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*input;
	t_split	*splited;
	t_token	*tokens;
	t_node	*ast;
	t_env *env_cp;

    (void)ac;
    (void)av;
	//(void)env;

	env_cp = cp_env(env);
	while (1)
	{
		tokens = NULL;
		input = readline("minishell$ ");
		if (!input)
			break ;
		if (ft_strlen(input) > 0)
			add_history(input);
		splited = input_split(input);
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
		expansion(ast, env_cp);
		printf("Aftre Expansion\n");
		debug_parser(ast);
		free_parser(ast);
	}
	clear_history();
	return (0);
}
