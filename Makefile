CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCE_DIR = ./src/

SOURCE_FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isprint.c ft_isascii.c \
	ft_toupper.c ft_tolower.c \
	ft_calloc.c \
	ft_strlen.c \
	ft_memset.c ft_bzero.c

SOURCES = $(addprefix $(SOURCE_DIR), $(SOURCE_FILES))
OBJECTS = $(SOURCES:.c=.o)

INCLUDE_DIR = ./

NAME = libft.a

AR = ar -rc
LIB = ranlib

all:	$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -I $(INCLUDE_DIR) $< -o $@

$(NAME):	$(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)
	$(LIB) $(NAME)

clean:
	rm -f $(OBJECTS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
