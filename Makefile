NAME 				= 	libft.a
HEAD				=	libft.h
INC_DIR				=	.
OBJ_DIR				=	obj/
CC 					= 	gcc
CFLAGS 				= 	-Wall -Wextra -Werror
AR					=	ar rcs
RM					=	rm -f
SRC 				=	ft_atoi.c \
						ft_bzero.c \
						ft_calloc.c \
						ft_isalnum.c \
						ft_isalpha.c \
						ft_isascii.c \
						ft_isdigit.c \
						ft_isprint.c \
						ft_itoa.c \
						ft_memchr.c \
						ft_memcmp.c \
						ft_memcpy.c \
						ft_memmove.c \
						ft_memset.c \
						ft_putchar_fd.c \
						ft_putendl_fd.c \
						ft_putnbr_fd.c \
						ft_putstr_fd.c \
						ft_split.c \
						ft_strchr.c \
						ft_strdup.c \
						ft_striteri.c \
						ft_strjoin.c \
						ft_strlcat.c \
						ft_strlcpy.c \
						ft_strlen.c \
						ft_strmapi.c \
						ft_strncmp.c \
						ft_strnstr.c \
						ft_strrchr.c \
						ft_strtrim.c \
						ft_substr.c \
						ft_tolower.c \
						ft_toupper.c
SRC_BONUS			=	ft_lstadd_back.c \
						ft_lstadd_front.c \
						ft_lstclear.c \
						ft_lstdelone.c \
						ft_lstiter.c \
						ft_lstlast.c \
						ft_lstmap.c \
						ft_lstnew.c \
						ft_lstsize.c

OBJ 				= 	$(SRC:%.c=$(OBJ_DIR)%.o)
OBJ_BONUS			= 	$(SRC_BONUS:%.c=$(OBJ_DIR)%.o)

# $< = SOURCE FILE && $@ = OUTPUT FILE
$(OBJ_DIR)%.o: 					%.c $(HEAD) | $(OBJ_DIR)
							@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

all: 					$(NAME)

$(NAME):				$(OBJ) Makefile
							$(AR) $@ $^

$(OBJ_DIR):
							@mkdir -p $(OBJ_DIR)

bonus:					$(OBJ) $(OBJ_BONUS)
							@$(AR) $(NAME) $(OBJ) $(OBJ_BONUS)

clean:
							@rm -rf $(OBJ_DIR)
							@echo "Deleting repository 'obj'"

fclean: 				clean
							@$(RM) $(NAME)
							@echo "Deleting libft.a"

re: 					fclean all

.PHONY: 				all bonus clean fclean re