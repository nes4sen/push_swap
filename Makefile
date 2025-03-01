CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf


CFILES =split.c \
		cost.c \
		helper_functions.c \
		moves.c \
		push_swap.c \
		sorting.c \
		stack_utiles.c \
		input_handling.c \
		homeless_functions.c


OBJ = $(CFILES:.c=.o)
NAME = push_swap

B_CFILES =	test.c

B_OBJ = $(B_CFILES:.c=.o) 

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)
bonus :$(B_OBJ) 

%.o: %.c push_swap.h 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(B_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean
