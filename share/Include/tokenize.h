/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:02:16 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/26 21:19:51 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
# define TOKENIZE_H

# include "std.h"

typedef struct s_split
{
	char			*val;
	int				flag_cat;
}					t_split;

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
	int				flag_cat;
	struct s_token	*next;
}					t_token;

t_token				*lexer(char *input);

t_split				*input_split(char *str);
void				*error_in_input(int num);
t_split				make_unit(char *str, int num);
void				free_str(t_split *elem, int i);
void				free_split(t_split *tab);

int					rule_1(char *s);
int					rule_2(char *s);
int					rule_3(char *s);
int					rule_4(char *s);
int					rule_5(char *s);

int					token_count(char *str);
int					case_not_operater(char *str);

t_token				*toknizer(t_split *splited);
t_token				*make_new_token(t_token *head, t_split elem);
void				token_add_back(t_token **head, t_token *new);

void				type_categorizer(t_token *token);
void				type_pipe(t_token *token);
void				type_redir_left(t_token *token);
void				type_redir_right(t_token *token);
void				quote_categorizer(t_token *token);

void				free_tokens(t_token *tokens);
int					is_blank(char c);

#endif