NAME = test

SRC = main.c \
	lexer/tokenize_utils.c lexer/token_rule.c lexer/token_counter.c lexer/ft_split.c lexer/toknizer.c ./libft/ft_strlen.c ./libft/ft_strdup.c \
	parser/parser.c parser/parser_utils.c parser/recursive_descent.c libft/ft_calloc.c libft/ft_memset.c
OBJ = $(SRC:.c=.o)

CC  = cc
FLAGS = -Wall -Werror -Wextra -g

LINK = -I./Include -lreadline

all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(FLAGS) $(OBJ) $(LINK) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -I./Include -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re