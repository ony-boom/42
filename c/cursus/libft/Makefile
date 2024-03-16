CC = cc
NAME = libft.a
HEADER = libft.h
SRC = ft_abs.c\
ft_atoi.c\
ft_bzero.c\
ft_calloc.c\
ft_isalnum.c\
ft_isalpha.c\
ft_isascii.c\
ft_isdigit.c\
ft_isinrange.c\
ft_islower.c\
ft_isnum.c\
ft_isprint.c\
ft_isspace.c\
ft_isupper.c\
ft_itoa.c\
ft_memchr.c\
ft_memcmp.c\
ft_memcpy.c\
ft_memmove.c\
ft_memset.c\
ft_putchar_fd.c\
ft_putendl_fd.c\
ft_putnbr_fd.c\
ft_putstr_fd.c\
ft_split.c\
ft_strchr.c\
ft_strcmp.c\
ft_strdup.c\
ft_striteri.c\
ft_strjoin.c\
ft_strlcat.c\
ft_strlcpy.c\
ft_strlen.c\
ft_strmapi.c\
ft_strncat.c\
ft_strncmp.c\
ft_strnstr.c\
ft_strrchar.c\
ft_strstr.c\
ft_strtrim.c\
ft_substr.c\
ft_tolower.c\
ft_toupper.c\
ft_trim_start.c

BONUS_SRC = ft_lstadd_back_bonus.c\
ft_lstadd_front_bonus.c\
ft_lstclear_bonus.c\
ft_lstdelone_bonus.c\
ft_lstiter_bonus.c\
ft_lstlast_bonus.c\
ft_lstmap_bonus.c\
ft_lstnew_bonus.c\
ft_lstsize_bonus.c

OBJECTS := $(SRC:.c=.o)
BONUS_OBJECTS := $(BONUS_SRC:.c=.o)

C_FLAGS = -Wall -Wextra -Werror

all: $(NAME) 

OBJECTS: $(SRC) $(HEADER)
	@echo "Making .o"
	@$(CC) $(C_FLAGS) -c $(SRC)

BONUS_OBJECTS: $(BONUS_SRC) $(HEADER)
	@echo "Making bonus .o"
	@$(CC) $(C_FLAGS) -c $(BONUS_SRC)

$(NAME): OBJECTS
	@echo "Making $(NAME)"
	@ar -crs $(NAME) $(OBJECTS)

bonus: BONUS_OBJECTS OBJECTS
	@echo "Making $(NAME) with bonus"
	@ar -crs $(NAME) $(OBJECTS) $(BONUS_OBJECTS)
	
clean:
	@echo "Cleaning Object file"
	@rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	@echo "Cleaning binary"
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean
