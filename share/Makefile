NAME = test

SRC = main.c debug.c ft_env.c\
	lexer/tokenize_utils.c lexer/token_rule.c lexer/token_counter.c lexer/input_split.c lexer/toknizer.c lexer/lexer.c lexer/categorize.c\
	parser/parser.c parser/parser_utils.c parser/recursive_descent.c parser/node_pipe.c parser/node_command.c parser/arg_list.c parser/free_parser.c\
	expansion/expansion.c expansion/expansion_utils.c\
	expansion/expand_val/expand_val.c expansion/expand_val/expand_val_utils.c expansion/expand_val/case_closed.c expansion/expand_val/case_closed_utils.c\
	expansion/expand_val/case_not_closed.c expansion/expand_val/make_new_str.c expansion/expand_val/case_not_closed_utils.c\
	expansion/field_split/field_spliting.c expansion/field_split/fsp_utils.c expansion/field_split/expand_list.c \
	expansion/after_fsp/quote_remove.c expansion/after_fsp/finalize_argument.c	expansion/after_fsp/passed_arg_table.c
OBJ = $(SRC:.c=.o)

LIBFT       = libft/libft.a 

INCLUDE = -I./Include 

CC  = cc
CFLAGS = -Wall -Werror -Wextra $(INCLUDE) -g
LDFLAGS     = -lreadline -L./libft -lft 

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) $(LINK) -o $(NAME)

$(LIBFT):
	make -C ./libft

%.o: %.c
	$(CC) $(CFLAGS) -I./Include -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C ./libft clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re