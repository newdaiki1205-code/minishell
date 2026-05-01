NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS = main.c path.c pipex.c utils.c
OBJS = $(SRCS:.c=.o)

LIBFT_HEADERS = ../libft/libft.h ../libft/ft_printf.h ../libft/get_next_line.h
HEADERS = ../inc/pipex.h $(LIBFT_HEADERS)

LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT): $(LIBFT_HEADERS)
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
