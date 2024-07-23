CC = cc
FLAGS = -Wall -Wextra -Werror 
RFLAGS = -lreadline -lncurses
NAME = minishell
SRC = parsing.c libft_functions.c
OBJ = $(SRC:.c=.o)

all         : $(NAME)

$(NAME)     : $(OBJ)
	            $(CC) $(FLAGS) -o $(NAME) $(OBJ) $(RFLAGS)

%.o			:	%.c minishell.h
			$(CC) $(FLAGS) -c $< -o $@

clean       :
	            @rm -f $(OBJ)

fclean      : clean
	            @rm -f $(NAME)

re          : fclean all

.PHONY      : clean