#ifndef OBJECT_H_
#define OBJECT_H_
	
#include "Vector.h"

typedef enum direction{
	NORTH, SOUTH, EAST, WEST
} Direction;

typedef struct object{
	Vector4 pos;
	Uint32 color;
} Object;

#endif