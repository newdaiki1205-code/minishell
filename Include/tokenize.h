/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:02:16 by dshirais          #+#    #+#             */
/*   Updated: 2026/03/31 20:47:30 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#ifndef TOKENIZE_H
# define TOKENIZE_H

typedef enum e_type
{
	WORD,
	APPEND,
	HEREDOC,
	I_RED,
	O_RED,
	PIPE
}					t_type;

typedef enum e_quote
{
	DEF,
	SINGLE,
	DOUBLE
}					t_quote;

typedef struct s_token
{
	t_type			type;
	char			*value;
	t_quote			quote;
	struct s_token	*next;
}					t_token;

char				**ft_split(char *str);
int					token_count(char *str);
char				*make_unit(char *str);
void				free_str(char **str, int i);
void				free_split(char **tab);

int					rule_1(char *s);
int					rule_2(char *s);
int					rule_3(char *s);
int					rule_4(char *s);
int					rule_5(char *s);

t_token				*toknizer(t_token *head, char **splited);
t_token				*make_new_token(t_token *head, char *value);
void				type_categorizer(t_token *token);
void				quote_categorizer(t_token *token);
void				token_add_back(t_token **head, t_token *new);

void				print_tokeninfo(t_token *tokens);
void				free_tokens(t_token *tokens);

#endif