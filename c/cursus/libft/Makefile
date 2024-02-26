CC = cc
NAME = libft.a
HEADER = libft.h
SRC := $(wildcard ft_*.c) 
OBJECTS := $(SRC:.c=.o)

C_FLAGS = -Wall -Wextra -Werror

all: $(NAME) clean

OBJECTS: $(SRC) $(HEADER)
	@echo "Making .o"
	@$(CC) $(C_FLAGS) -c $(SRC)

$(NAME): OBJECTS
	@echo "Making $(NAME)"
	@ar -crs $(NAME) $(OBJECTS)

bonus: all
	
clean:
	@echo "Cleaning Object file"
	@rm -f $(OBJECTS)

fclean: clean
	@echo "Cleaning binary"
	rm -f $(NAME)

re: fclean all

format: $(SRC)
	@c_formatter_42 ./libft.h
	@for file in ./*.c; do \
		c_formatter_42 "$$file"; \
	done
