/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 19:13:05 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/03 16:23:43 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#ifndef PARSER_H
# define PARSER_H

typedef enum
{
	ND_PIPE,
	ND_COMMAND,
	ND_IO_RED,
	ND_WORD
}					t_ntype;

// typedef enum
// {
// 	ND_INPUT,
// 	ND_OUTPUT,
// 	ND_APPEND,
// 	ND_HEREDOC
// }					t_nred;

// typedef enum
// {
// 	ND_DEF,
// 	ND_SINGLE,
// 	ND_DOUBLE
// }					t_nquote;

typedef struct s_node
{
	t_ntype			type;
	struct s_node	*lhs;
	struct s_node	*rhs;
	char *val; // used only in WORD
	//t_nred redirect; //used only token_type=RED
	//t_nquote quote; //used only token_quote !=DEF
}					t_node;

t_node				*parser(t_token *tokens);

t_node				*pipe_sequence(t_token *current);
t_node				*command(t_token *current);
t_node				*element(t_token *current);

t_node				*new_node(t_ntype kind, t_node *lhs, t_node *rhs);
t_node				*new_node_word(char *val);
t_node				*new_node_redirect(char *val);
bool				pipe_check(t_token *current);
bool				command_check(t_token *current);

#endif