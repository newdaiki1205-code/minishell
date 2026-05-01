/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 19:13:05 by dshirais          #+#    #+#             */
/*   Updated: 2026/05/01 16:22:43 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "std.h"
# include "tokenize.h"

typedef enum s_ntype
{
	ND_PIPE,
	ND_COMMAND
}					t_ntype;

typedef enum s_redtyp
{
	ND_INPUT,
	ND_OUTPUT,
	ND_APPEND,
	ND_HEREDOC
}					t_redtyp;

typedef enum s_nquote
{
	ND_DEF,
	ND_SINGLE,
	ND_DOUBLE
}					t_nquote;

typedef struct s_narg
{
	char			*val;
	t_nquote		q_state;
	int				flag_cat;
	struct s_narg	*next;
}					t_narg;

// typedef struct s_infile
// {
// 	char			*str;
// 	struct s_infile	*next;
// }					t_infile;

typedef struct s_nred
{
	t_redtyp		type;
	t_narg			*filename;
	t_narg			*delimiter;
	t_narg			*infile_head;
	char			**here_doc;
	int				here_doc_flag;
	struct s_nred	*next;
}					t_nred;

typedef struct s_node
{
	t_ntype			type;
	struct s_node	*lhs;
	struct s_node	*rhs;
	t_narg			*args;// used only in WORD
	t_nred			*red;// used only in IO_RED
	char			**argument;// used for the final argument(after expansion)
}					t_node;

t_node				*parser(t_token **tokens);

t_node				*pipe_sequence(t_token **current);
t_node				*command(t_token **current);

t_node				*new_node_pipe(t_ntype kind, t_node *lhs, t_node *rhs);
bool				pipe_check(t_token **current);
bool				command_check(t_token **current);

t_node				*new_node_command(t_token **current);
bool				is_valid_start(t_token **current);

t_nred				*rd_handler(t_nred *node, t_token **current);
int					word_fill(t_nred *node, t_token **current);
t_narg				*red_list_gen(t_narg *node, t_token **current);
t_nred				*red_add_back(t_nred *head, t_nred *new);

void				which_red(t_nred *new, t_token *current);
void				move_to_next_token(t_token **current);
void				error_in_redirect(int i, char *value);

t_narg				*make_arg_list(t_narg **args, t_token *current);
void				quotation_handler(t_narg *new, t_token *current);
void				arg_add_back(t_narg **head, t_narg *new);

void				free_parser(t_node *tree);
void				free_parser_error(t_node *tree);

void				free_args(t_narg *args);
void				free_arg_table(char **tab);
void				free_redirection(t_nred *head);
//void				free_infile(t_narg *head);

#endif