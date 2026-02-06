# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -O2

# Archiving Tool
AR = ar -rc
LIB = ranlib

# File Deletion Tool
RM = rm -f

# Sources
SRC_FILES = ctype/ctype_class.c ctype/ctype_convert.c \
	atoi/ft_strtol.c atoi/ft_atoi_utils.c \
	io/input/get_next_line/get_next_line.c io/input/get_next_line/get_next_line_utils.c \
	io/output/ft_putchar_fd.c io/output/ft_putstr_fd.c io/output/ft_putnbr_fd.c \
	list/ft_lstadd.c list/ft_lstclear.c list/ft_lstiter.c list/ft_lstlast.c list/ft_lstmap.c \
	list/ft_lstnew.c list/ft_lstsize.c \
	malloc/ft_calloc.c malloc/ft_realloc.c \
	printf/parser.c \
	printf/counters/conv_len_c.c printf/counters/conv_len_d.c printf/counters/conv_len_p.c \
	printf/counters/conv_len_s.c printf/counters/conv_len_u.c printf/counters/conv_len_x.c \
	printf/counters/get_total_len.c \
	printf/loaders/load_conv_c.c printf/loaders/load_conv_d.c printf/loaders/load_conv_p.c \
	printf/loaders/load_conv_s.c printf/loaders/load_conv_u.c printf/loaders/load_conv_x.c \
	printf/loaders/dispatch_conversion.c \
	printf/count_digits.c \
	printf/ft_printf.c printf/ft_dprintf.c printf/ft_sprintf.c printf/ft_snprintf.c \
	printf/ft_asprintf.c \
	string/ft_memcpy.c string/ft_memset.c string/ft_strcat.c string/ft_strchr.c string/ft_strcmp.c \
	string/ft_strdup.c string/ft_strlen.c string/ft_strnstr.c \
	stringx/ft_split.c stringx/ft_striteri.c stringx/ft_strjoin.c stringx/ft_strmapi.c \
	stringx/ft_strtrim.c stringx/ft_substr.c \
	utils/arithmetic.c utils/comparisons.c \
	ft_itoa.c


SRC_DIR = src/

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

# Object Files
OBJ = $(SRC:.c=.o)

# Includes
INCLUDE_DIR = include/
CFLAGS += -I $(INCLUDE_DIR)

# Internal includes
CFLAGS += -I src/printf/

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
