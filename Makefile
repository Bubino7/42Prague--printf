NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft/
PRINTF_DIR = ft_printf/

# Source files
LIBFT_SRCS = $(addprefix $(LIBFT_DIR), ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c)
PRINTF_SRCS = $(addprefix $(PRINTF_DIR), ft_printf.c ft_printf_helpers.c ft_printf_helpers_2.c ft_printf_handlers.c ft_printf_handlers_2.c)

# Object files
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)
OBJS = $(LIBFT_OBJS) $(PRINTF_OBJS)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(LIBFT_DIR)%.o: $(LIBFT_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(PRINTF_DIR)%.o: $(PRINTF_DIR)%.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I. -c $< -o $@

test: $(NAME)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I. main.c $(NAME) -o test_program

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) test_program

re: fclean all

.PHONY: all clean fclean re test
