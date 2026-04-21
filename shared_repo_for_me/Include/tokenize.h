/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:02:16 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/13 20:12:56 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#ifndef TOKENIZE_H
# define TOKENIZE_H

typedef struct s_split
{
	char *val;
	int flag_cat;
} t_split;

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
	int flag_cat;
	struct s_token	*next;
}					t_token;

// typedef struct s_tklist
// {
// 	char *value;
// 	t_quote quote;
// 	struct s_list * next;
// }	t_tklist;

// typedef struct s_token
// {
// 	t_type			type;
// 	t_tklist		tknode;
// 	struct s_token	*next;
// }					t_token;

//char				**input_split(char *str);
t_split *input_split(char *str);
int					token_count(char *str);
//char				*make_unit(char *str);
t_split make_unit(char *str, int num);
//void				free_str(char **str, int i);
void free_str(t_split *elem, int i);
//void				free_split(char **tab);
void free_split(t_split *tab);

int					rule_1(char *s);
int					rule_2(char *s);
int					rule_3(char *s);
int					rule_4(char *s);
int					rule_5(char *s);

//t_token				*toknizer(t_token *head, char **splited);
t_token	*toknizer(t_token *head, t_split *splited);
//t_token				*make_new_token(t_token *head, char *value);
t_token	*make_new_token(t_token *head, t_split elem);
void				type_categorizer(t_token *token);
void				quote_categorizer(t_token *token);
void				token_add_back(t_token **head, t_token *new);

void				free_tokens(t_token *tokens);
int					is_blank(char c);

#endif