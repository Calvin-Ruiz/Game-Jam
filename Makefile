
SRC = Items/Blaster.cpp \
	  Core.cpp \
      CreeperWalk.cpp \
	  Items/Door.cpp \
	  Items/DynamicItem.cpp \
      GlobalActivity.cpp \
	  GraphicPlayer.cpp \
      Items/Item.cpp \
	  Items/Key.cpp \
      main.cpp \
	  Player.cpp \
	  StartMenu.cpp \
	  Items/TheExit.cpp \
      ThreadedModule.cpp \
	  Door.cpp \
      Room.cpp
	  WindowManager.cpp \
	  Items/MediKit.cpp \
	  Items/ItemMgr.cpp \

NAME = laby

OBJ = $(SRC:.cpp=.o)

CPPFLAGS = -Wall -Wextra -I . -I Items
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
