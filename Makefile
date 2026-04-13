NAME = test

SRC = main.c debug.c ft_env.c\
	lexer/tokenize_utils.c lexer/token_rule.c lexer/token_counter.c lexer/input_split.c lexer/toknizer.c \
	parser/parser.c parser/parser_utils.c parser/recursive_descent.c parser/node_gen.c \
	expansion/expansion.c expansion/expansion_utils.c expansion/case_not_closed.c
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