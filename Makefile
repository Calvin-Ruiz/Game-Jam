
SRC = Core.cpp \
      CreeperWalk.cpp \
      GlobalActivity.cpp \
      Item.cpp \
      main.cpp \
      ThreadedModule.cpp \
	Door.cpp \
      WindowManager.cpp \
      Room.cpp

NAME = laby

OBJ = $(SRC:.cpp=.o)

CFLAGS = -Wall -Wextra -Werror -g -g3
CC = g++
BINFLAGS = -lpthread -lsfml-system -lsfml-window -lsfml-graphics

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(BINFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
	$(MAKE) clean
