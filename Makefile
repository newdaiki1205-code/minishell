NAME = lexer

SRC = tokenize.c tokenize_utils.c token_rule.c token_counter.c ft_split.c ./libft/ft_strlen.c ./libft/ft_strdup.c
OBJ = $(SRC:.c=.o)

CC  = cc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(FLAG) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(FLAG) -I./Include -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re