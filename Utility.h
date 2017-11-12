#ifndef UTILITY_H_
#define UTILITY_H_

#include <stdbool.h>

typedef struct Map
{
	int** matrix;
	int width;
	int height;
}*ptrMap;

typedef struct Map Map;
ptrMap createMapFromFile(const unsigned char* name);
bool printMap(const ptrMap map);
bool destroyMap(ptrMap map);

#endif