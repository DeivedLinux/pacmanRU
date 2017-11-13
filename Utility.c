#include <stdio.h>
#include <stdlib.h>
#include "Utility.h"
#include <stdbool.h>





ptrMap createMapFromFile(const unsigned char* name)
{
	ptrMap map = NULL;
	FILE* inputFile = NULL;
	unsigned char *buffer;
	unsigned i,j;
	int column;
	int row;
	int linesRead;
	int temp;

	buffer = (unsigned char*)calloc(1000,sizeof(char));
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
    row = atoi(buffer);
    fscanf(inputFile,"%s",buffer);
    column = atoi(buffer);

    map->column = column;
    map->row = row;
    linesRead = row;
    map->matrix = (int**)calloc(row,sizeof(int*));
    if(map->matrix == NULL)
    	return NULL;
    for(i = 0; i < row; i++)
    {
    	map->matrix[i] = (int*)calloc(column,sizeof(int));
    	if(map->matrix[i] == NULL)
    		return NULL;
    }
    
    for(i = 0; i < row; i++)
    {
    	for(j = 0; j < column; j++)
    	{
    		fscanf(inputFile,"%s",buffer);
    		temp = atoi(buffer);
    		map->matrix[i][j] = temp;
    	}
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

	for(i = 0; i < map->row; i++)
	{
		for(j = 0; j < map->column; j++)
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

	for(i = 0; i < map->row; i++)
		free(map->matrix[i]);

	free(map->matrix);
	free(map);

	return true;
}