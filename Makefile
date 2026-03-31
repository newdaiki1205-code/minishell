NAME = lexer

SRC = main.c tokenize_utils.c token_rule.c token_counter.c ft_split.c toknizer.c ./libft/ft_strlen.c ./libft/ft_strdup.c
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