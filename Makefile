CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCE_DIR = ./srcs/

SOURCE_FILES = *.c

SOURCES = $(addprefix $(SOURCE_DIR), $(SOURCE_FILES))
OBJECTS = $(SRCS:.c=.o)

NAME = libft.a

AR = ar -rc
LIB = ranlib

all:	$(NAME)

%.o: %.c
	$(CC) $(CFLAGS)

$(NAME):	$(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)
	$(LIB) $(NAME)

clean:
	rm -f $(OBJECTS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
