NAME = cows_and_bulls

FLAGS =	-Wall -Wextra -Werror 

SRC = main.c\

all: $(NAME)

$(NAME): $(SRC)
	    @echo "-----------------------------------"
		@echo "Compiling cows_and_bulls game"
		@gcc $(FLAGS) -o $(NAME) $(SRC)
		@echo "-----------------------------------"
		@echo "cows_and_bulls game is ready"
fclean:
	@rm -f $(NAME)
	@echo "-----------------------------------"
	@echo "game successfully removed"
	@echo "-----------------------------------"

re: 
	@make fclean
	@make all
