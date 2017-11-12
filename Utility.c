#include <stdio.h>
#include <stdlib.h>
#include "Utility.h"
#include <stdbool.h>

#define MAX_WIDTH 1000

ptrMap createMapFromFile(const unsigned char* name)
{
	ptrMap map = NULL;
	FILE* inputFile = NULL;
	unsigned char *buffer;
	unsigned i,j;
	int width;
	int height;
	int linesRead;
	int temp;

	buffer = (unsigned char*)calloc(MAX_WIDTH,sizeof(char));
	if(buffer == NULL)
		return NULL;

	map = (ptrMap)malloc(sizeof(Map));
	if(map == NULL)
		return NULL;

	inputFile = fopen(name,"r");
	if(name == NULL)
	{
		puts("Failed to open file");
		return NULL;
	}

	fscanf(inputFile,"%s",buffer);
    width = atoi(buffer);
    fscanf(inputFile,"%s",buffer);
    height = atoi(buffer);

    map->width = width;
    map->height = height;
    linesRead = height;
    map->matrix = (int**)calloc(width,sizeof(int*));
    if(map->matrix == NULL)
    	return NULL;
    for(i = 0; i < width; i++)
    {
    	map->matrix[i] = (int*)calloc(height,sizeof(int));
    	if(map->matrix[i] == NULL)
    		return NULL;
    }
    i = 0;

    while(linesRead > 0)
    {
    	linesRead--;
    	for(j = 0; j < width; j++)
    	{
    		fscanf(inputFile,"%s",buffer);
    		temp = atoi(buffer);
    		map->matrix[i][j] = temp;
    	}	
    	i++;
    }

	fclose(inputFile);

	return map;
}

bool printMap(const ptrMap map)
{
	unsigned i,j;

	if(map == NULL)
		return false;

	if(map->matrix == NULL)
		return false;

	for(i = 0; i < map->width; i++)
	{
		for(j = 0; j < map->height; j++)
		{
			printf("%i ",map->matrix[i][j]);
		}
		puts(" ");
	}
}

bool destroyMap(ptrMap map)
{
	unsigned i;

	if(map == NULL)
		return false;

	for(i = 0; i < map->width; i++)
		free(map->matrix[i]);

	free(map->matrix);
	free(map);

	return true;
}