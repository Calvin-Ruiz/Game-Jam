
SRC = Blaster.cpp \
	  Core.cpp \
      CreeperWalk.cpp \
	  Door.cpp \
	  DynamicItem.cpp \
      GlobalActivity.cpp \
	  GraphicPlayer.cpp \
      Item.cpp \
	  Key.cpp \
      main.cpp \
	  Player.cpp \
	  StartMenu.cpp \
	  TheExit.cpp \
      ThreadedModule.cpp \
	  WindowManager.cpp \

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
