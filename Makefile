NAME= talk.a

SRCS= server.c

OBJ= $(SRCS:.c=.o)

$(NAME): $(OBJ)
	@echo "\033[36m"--Compilando--"\033[0m ";
	@make -sC ./srcs/Libft
	@cp ./srcs/Libft/libft.a .
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	gcc -Wall -Werror -Wextra  -fsanitize=address libft.a server.c -o server
	gcc -Wall -Werror -Wextra  -fsanitize=address libft.a client.c -o client
	@clear

all: $(NAME)

re: fclean all

clean:
	@rm -rf $(NAME) $(OBJ) a.out server client
	@make -sC ./srcs/Libft/ fclean
	@clear
	@echo "\033[34m"🗑️\  Todo depurado correctamente  \🗑️"\033[0m"

fclean: clean
		@rm -rf libft.a talk.a

.PHONY: all clean re