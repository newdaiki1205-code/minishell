/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toknizer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 20:36:08 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/15 20:31:46 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

t_token	*toknizer(t_token *head, t_split *splited)
{
	int	i;

	i = 0;
	while (splited[i].val)
	{
		head = make_new_token(head, splited[i]);
		if(!head)
			return NULL;
		i++;
	}
	free_split(splited);
	return (head);
}

t_token	*make_new_token(t_token *head, t_split elem)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->value = ft_strdup(elem.val);
	if (!new->value)
		return (NULL);
	if(elem.flag_cat)
		new->flag_cat = 1;
	else
		new->flag_cat = 0;
	type_categorizer(new);
	quote_categorizer(new);
	token_add_back(&head, new);
	return (head);
}

void	type_categorizer(t_token *token)
{
	if (token->value[0] == '|')
	{
		if (rule_2(token->value) == 1)
			token->type = PIPE;
		else
			token->type = WORD;
	}
	else if (token->value[0] == '<')
	{
		if (rule_2(token->value) == 1)
			token->type = I_RED;
		else if (rule_2(token->value) == 2)
			token->type = HEREDOC;
		else
			token->type = WORD;
	}
	else if (token->value[0] == '>')
	{
		if (rule_2(token->value) == 1)
			token->type = O_RED;
		else if (rule_2(token->value) == 2)
			token->type = APPEND;
		else
			token->type = WORD;
	}
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

void	token_add_back(t_token **head, t_token *new)
{
	t_token *tmp;

	if (!*head)
	{
		*head = new;
        new->next = NULL;
	}
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->next = NULL;
	}
}

