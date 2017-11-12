OBJS = main.c Utility.c Screen.c Game.c
CC = gcc
INCLUDE_PATHS = -IC:\TDM-GCC-64\include
LIBRARY_PATHS = -IC:\TDM-GCC-64\lib
COMPILER_FLAGS = -w 
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2_image -lSDL2
OBJ_NAME = pacmanRU
all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)