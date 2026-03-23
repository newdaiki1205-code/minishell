/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:02:16 by dshirais          #+#    #+#             */
/*   Updated: 2026/03/23 17:31:21 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
# define TOKENIZE_H

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
size_t				ft_strlen(const char *s);
int					token_count(char *str);
char				*make_unit(char *str);
void				free_str(char **str, int i);
int					is_ope(char c);
int					ope_continue(char *c);

#endif