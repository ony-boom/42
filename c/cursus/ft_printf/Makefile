CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes -I./libft

LIBFT_DIR = libft
SRC_DIR = ./src
OBJ_DIR = obj

LIBFT_SRC = libft/ft_lstclear_bonus.c libft/ft_lstsize_bonus.c\
						libft/ft_lstmap_bonus.c libft/ft_putstr_fd.c\
						libft/ft_memcmp.c libft/ft_memcpy.c\
						libft/ft_lstadd_front_bonus.c libft/ft_atoi.c\
						libft/ft_putchar_fd.c libft/ft_strlcat.c\
						libft/ft_toupper.c libft/ft_strmapi.c\
						libft/ft_isascii.c libft/ft_isalpha.c\
						libft/ft_strjoin.c libft/ft_strrchar.c\
						libft/ft_isdigit.c libft/ft_itoa.c\
						libft/ft_isspace.c libft/ft_strchr.c\
						libft/ft_memset.c libft/ft_char_repeat.c\
						libft/ft_abs.c libft/ft_isinrange.c\
						libft/ft_putnbr_fd.c libft/ft_lstiter_bonus.c\
						libft/ft_lstadd_back_bonus.c libft/ft_lstlast_bonus.c\
						libft/ft_strncmp.c libft/ft_strdup.c\
						libft/ft_strlcpy.c libft/ft_strcmp.c\
						libft/ft_strnstr.c libft/ft_trim_start.c\
						libft/ft_split.c libft/ft_isupper.c\
						libft/ft_strncat.c libft/ft_strtrim.c\
						libft/ft_bzero.c libft/ft_lstnew_bonus.c\
						libft/ft_isnum.c libft/ft_tolower.c\
						libft/ft_lstdelone_bonus.c libft/ft_substr.c\
						libft/ft_islower.c libft/ft_isprint.c\
						libft/ft_striteri.c libft/ft_putendl_fd.c\
						libft/ft_strstr.c libft/ft_isalnum.c\
						libft/ft_strlen.c libft/ft_memchr.c\
						libft/ft_calloc.c libft/ft_memmove.c

PRINTF_SRC = src/ft_printf.c src/hex_to_str.c\
						 src/parser.c src/pointer_to_str.c\
						 src/str_builder.c src/str_to_printstr.c src/unsignedint_to_str.c

LIBFT_OBJ = $(LIBFT_SRC:$(LIBFT_DIR)/%.c=$(OBJ_DIR)/%.o)
PRINTF_OBJ = $(PRINTF_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME = libftprintf.a

all: $(NAME)
bonus: all

$(NAME): $(LIBFT_OBJ) $(PRINTF_OBJ)
	@ar rc $@ $^
	@ar s $@
	@echo "libftprintf.a has been created successfully!"

$(OBJ_DIR)/%.o: $(LIBFT_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Object files have been removed."

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) has been removed."

re: fclean all

my_test:
	@echo "Running personnal test:\n"
	@$(CC) $(CFLAGS) -g ./main.c $(SRC_DIR)/*.c $(LIBFT_DIR)/*.c

format: $(SRC)
	@c_formatter_42 src/*.c 
	@c_formatter_42 libft/*.c
	@c_formatter_42 libft/*.h
	@c_formatter_42 includes/*.h

.PHONY: all clean fclean re format
