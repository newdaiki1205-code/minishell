/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 20:45:48 by dshirais          #+#    #+#             */
/*   Updated: 2026/05/01 16:25:59 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "excution.h"
# include "tokenize.h"
# include "parser.h"
# include "expansion.h"
# include "redirection.h"
# include "std.h"
# include "debug.h"

t_node	*parse_input(char *input, t_env *env);

#endif