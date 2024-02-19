CC = cc
NAME = libft.a
INCLUDE = libft.h
SRC := $(wildcard ft_*.c) 
C_FLAGS = -Wall -Wextra -Werror
OBJECTS := $(SRC:.c=.o)

all: $(NAME) clean

OBJECTS: $(SRC) $(INCLUDE)
	$(CC) $(C_FLAGS) -c $(SRC)

$(NAME): OBJECTS
	ar -crs $(NAME) $(OBJECTS)

clean: 
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
