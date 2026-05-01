/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 20:30:03 by dshirais          #+#    #+#             */
/*   Updated: 2026/05/01 22:39:05 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_ifs(t_env *env)
{
	t_env	*tmp;
	t_env	*new;

	tmp = env;
	while (tmp->next)
		tmp = tmp->next;
	new = (t_env *)ft_calloc(1, sizeof(t_env));
	// if(!new)
	// 	return (NULL);
	new->key = "IFS";
	new->value = "+/";
	new->next = NULL;
	tmp->next = new;
}

int	main(int ac, char **av, char **env)
{
	char	*input;
	t_node	*ast;
	t_env	*env_cp;

	(void)ac;
	(void)av;
	env_cp = cp_env(env);
	// add_ifs(env_cp);
	while (1)
	{
		input = readline("minishell$ ");
		if (!input)
			break ;
		if (ft_strlen(input) > 0)
			add_history(input);
		ast = parse_input(input, env_cp);
		if (!ast)
			continue ;
		free_parser(ast);
	}
	free_env(env_cp);
	clear_history();
	return (0);
}

t_node	*parse_input(char *input, t_env *env)
{
	t_token	*tokens;
	t_node	*parse_tree;
	int		exit_status;

	exit_status = 0;
	tokens = lexer(input);
	if (!tokens)
		return (NULL);
	//print_tokeninfo(tokens);
	parse_tree = parser(&tokens);
	if (!parse_tree)
		return (NULL);
	// printf("Before Expansion\n");
	// debug_parser(parse_tree);
	if(redirection(parse_tree, env, exit_status))
		return(free_parser_error(parse_tree), NULL);
	if (expansion(parse_tree, env, exit_status))
		return (free_parser_error(parse_tree), NULL);
	// printf("\nAfter Expansion\n");
	// debug_parser(parse_tree);
	if (concat_args(parse_tree))
		return (free_parser_error(parse_tree), NULL);
	printf("\nAfter making argument table\n");
	print_final_state(parse_tree);
	return (parse_tree);
}
