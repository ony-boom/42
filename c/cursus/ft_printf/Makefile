CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes

LIBFT_DIR = libft
SRC_DIR = .
OBJ_DIR = obj

LIBFT_SRC = $(wildcard $(LIBFT_DIR)/*.c)
PRINTF_SRC = $(SRC_DIR)/*.c

LIBFT_OBJ = $(LIBFT_SRC:$(LIBFT_DIR)/%.c=$(OBJ_DIR)/%.o)
PRINTF_OBJ = $(PRINTF_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME = libftprintf.a

all: $(NAME)

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

format: $(SRC)
	@c_formatter_42 *.c 
	@c_formatter_42 libft/*.c
	@c_formatter_42 libft/*.h
	@c_formatter_42 includes/*.h

.PHONY: all clean fclean re format
