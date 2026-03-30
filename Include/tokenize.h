/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:02:16 by dshirais          #+#    #+#             */
/*   Updated: 2026/03/30 20:59:35 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
# define TOKENIZE_H

# include "/home/dshirais/Project_C/minishell/token/Include/libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>

typedef enum e_type
{
	WORD,
	APPEND,
	HEREDOC,
	I_RED,
	O_RED,
	PIPE,
	EoF
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
size_t				ft_strlen(const char *s);
int					token_count(char *str);
char				*make_unit(char *str);
void				free_str(char **str, int i);
int					is_ope(char c);
int					ope_continue(char *c);
int					del_identify(char *str);
int					is_space(char c);
int					is_quote(char c);

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

#endif