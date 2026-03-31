/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 19:13:05 by dshirais          #+#    #+#             */
/*   Updated: 2026/03/31 19:24:43 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef enum
{
    PIPE_SEQ,
    COMMAND,
    ELEMENT,
    IO_RED,
    WORD
} t_type;

typedef struct s_node
{
    t_type type;
    struct s_node *lhs;
    struct s_node *rhs;
    char *val; //used only in WORD
} t_node;


#endif