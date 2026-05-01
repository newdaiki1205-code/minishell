/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_handler_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 16:16:25 by dshirais          #+#    #+#             */
/*   Updated: 2026/05/01 16:17:16 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	which_red(t_nred *new, t_token *current)
{
	if (current->type == I_RED)
		new->type = ND_INPUT;
	else if (current->type == O_RED)
		new->type = ND_OUTPUT;
	else if (current->type == APPEND)
		new->type = ND_APPEND;
	else
		new->type = ND_HEREDOC;
}

void	move_to_next_token(t_token **current)
{
	*current = (*current)->next;
}

void	error_in_redirect(int i, char *value)
{
	if (i == 0)
		printf("minihsell: syntax error near unexpected token `newline'\n");
	else
		printf("minishell: syntax error near unexpected token '%s'\n", value);
}
