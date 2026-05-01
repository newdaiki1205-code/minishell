/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 16:23:39 by dshirais          #+#    #+#             */
/*   Updated: 2026/05/01 16:27:06 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "excution.h"
# include "expansion.h"
# include "parser.h"
# include "tokenize.h"

void	debug_parser(t_node *tree);
void	print_tokeninfo(t_token *tokens);
void	print_nodeinfo(t_node *node);
void	print_final_state(t_node *tree);
void	print_final_info(t_node *node);
void	print_red_info(t_nred *head);
void	print_heredoc(t_narg *head);
void	print_red_info_final(t_nred *head);

#endif