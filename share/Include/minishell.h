/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 20:45:48 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/26 21:12:14 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "excution.h"
# include "tokenize.h"
# include "parser.h"
# include "expansion.h"
# include "std.h"

void	debug_parser(t_node *tree);
void	print_tokeninfo(t_token *tokens);
void	print_nodeinfo(t_node *node);
void	print_final_state(t_node *tree);
void	print_final_info(t_node *node);
t_node	*parse_input(char *input, t_env *env);

#endif