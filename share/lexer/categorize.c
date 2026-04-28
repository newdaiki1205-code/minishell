/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   categorize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:33:39 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/23 19:36:04 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

void	type_categorizer(t_token *token)
{
	if (token->value[0] == '|')
		type_pipe(token);
	else if (token->value[0] == '<')
		type_redir_left(token);
	else if (token->value[0] == '>')
		type_redir_right(token);
	else
		token->type = WORD;
}

void	type_pipe(t_token *token)
{
	if (rule_2(token->value) == 1)
		token->type = PIPE;
	else
		token->type = WORD;
}

void	type_redir_left(t_token *token)
{
	if (rule_2(token->value) == 1)
		token->type = I_RED;
	else if (rule_2(token->value) == 2)
		token->type = HEREDOC;
	else
		token->type = WORD;
}

void	type_redir_right(t_token *token)
{
	if (rule_2(token->value) == 1)
		token->type = O_RED;
	else if (rule_2(token->value) == 2)
		token->type = APPEND;
	else
		token->type = WORD;
}

void	quote_categorizer(t_token *token)
{
	if (token->value[0] == 34)
		token->quote = DOUBLE;
	else if (token->value[0] == 39)
		token->quote = SINGLE;
	else
		token->quote = DEF;
}
