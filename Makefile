# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Archiving Tool
AR = ar -rc
LIB = ranlib

# File Deletion Tool
RM = rm -f

# Sources
SRC_FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_strnlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
	ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c \
	ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
	ft_utoa_stack.c conv_len_c.c conv_len_d.c conv_len_p.c conv_len_s.c \
	conv_len_u.c conv_len_x.c get_total_len.c count_digits.c load_conv_c.c \
	load_conv_d.c load_conv_p.c load_conv_s.c load_conv_u.c load_conv_x.c \
	load_conv_xx.c load_string.c

SRC_DIR = src/

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

# Object Files
OBJ = $(SRC:.c=.o)

# Includes
INCLUDE_DIR = include/
CFLAGS += -I $(INCLUDE_DIR)

# Output File
NAME = libft.a

# Rules

all:	$(NAME)

$(NAME):	$(OBJ)
	$(AR) $(NAME) $(OBJ)
	$(LIB) $(NAME)

%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

# Phony targets
.PHONY:	all clean fclean re
