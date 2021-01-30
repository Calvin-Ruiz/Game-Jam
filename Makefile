
SRC = Core.cpp \
      CreeperWalk.cpp \
      GlobalActivity.cpp \
      Item.cpp \
      main.cpp \
      ThreadedModule.cpp \
	  Door.cpp \
	  DynamicItem.cpp \
	  StartMenu.cpp \
	  TheExit.cpp \
	  Key.cpp

NAME = laby

OBJ = $(SRC:.cpp=.o)

CPPFLAGS = -Wall -Wextra
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
