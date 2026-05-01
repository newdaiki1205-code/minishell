/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 18:05:36 by dshirais          #+#    #+#             */
/*   Updated: 2026/05/01 15:39:05 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

# include "excution.h"
# include "expansion.h"
# include "parser.h"
# include "std.h"

int		redirection(t_node *tree, t_env *env, int exit_status);
t_nred	*traverse_red(t_nred *red, t_env *env, int exit_status);
t_nred	*here_doc_handler(t_nred *node, t_env *env, int exit_status);

t_narg	*quote_remove_delimiter(t_narg *del, int *flag);

t_narg	*make_here_doc(t_nred *node, char *delimiter);
t_narg	*make_heredoc_list(t_narg *args, char *input);
void	heredoc_add_back(t_narg *head, t_narg *new);

t_narg	*traverse_heredoc(t_narg *args, t_env *env, int exit_status);
t_nred	*finalize_here_doc(t_nred *node);
t_nred	*free_except_last(t_nred *node);
char	**make_here_doc_tab(t_narg *list, int size);

#endif