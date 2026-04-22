/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 20:30:03 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/21 19:33:35 by dshirais         ###   ########.fr       */
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
	int exit_status;

    (void)ac;
    (void)av;
	//(void)env;

	env_cp = cp_env(env);
	exit_status = 0;
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
		printf("Before Expansion\n");
		debug_parser(ast);
		printf("\n");
		expansion(ast, env_cp, exit_status);
		printf("Aftre Expansion\n");
		debug_parser(ast);
		free_parser(ast);
	}
	free_env(env_cp);
	clear_history();
	return (0);
}
