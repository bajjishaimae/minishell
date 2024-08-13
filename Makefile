CC = cc
FLAGS = -g -Wall -Wextra -Werror -fsanitize=address
RFLAGS = -lreadline -lncurses
NAME = minishell
SRC = check_errors.c init_shell.c minishell.c tokenize.c helpers.c expand.c expand_home.c
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