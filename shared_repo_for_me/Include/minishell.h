/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 20:45:48 by dshirais          #+#    #+#             */
/*   Updated: 2026/04/12 17:17:23 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H


# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# include "../libft/libft.h"
# include "tokenize.h"
# include "parser.h"
# include "excution.h"
# include "expansion.h"


void debug_parser(t_node *tree);
void				print_tokeninfo(t_token *tokens);
void print_nodeinfo(t_node *node);

#endif