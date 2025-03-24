CC = cc
CFLAGS = -Wall -Wextra -Werror 
RM = rm -rf


P_FILES =split.c \
		cost.c \
		helper_functions.c \
		moves.c \
		sorting.c \
		stack_utiles.c \
		input_handling.c \
		homeless_functions.c

B_CFILES =./bonus/checker.c \
		  ./bonus/get_next_line.c \
		  ./bonus/get_next_line_utils.c \

C_FILES = $(P_FILES) push_swap.c


P_OBJ = $(P_FILES:.c=.o)
OBJ = $(C_FILES:.c=.o)
B_OBJ = $(B_CFILES:.c=.o) 

NAME = push_swap
B_NAME = checker


all: $(NAME)

bonus: $(B_NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(B_NAME) :$(B_OBJ)  $(P_OBJ) 
	$(CC) $(B_OBJ)  $(P_OBJ) -o $(B_NAME)
%.o: %.c push_swap.h 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(B_OBJ)

fclean: clean
	$(RM) $(NAME) $(B_NAME)

re: fclean all

.PHONY: clean 
