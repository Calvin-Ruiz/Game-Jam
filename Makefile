
SRC = Core.cpp \
      CreeperWalk.cpp \
      GlobalActivity.cpp \
      Item.cpp \
      main.cpp \
      ThreadedModule.cpp \
      WindowManager.cpp

NAME = laby

OBJ = $(SRC:.cpp=.o)

CFLAGS = -Wall -Wextra -Werror -j12
CC = g++

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
	$(MAKE) clean
