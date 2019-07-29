#ifndef
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>

struct _List;
typedef struct _List* Position;
typedef struct _List
{
	int el;
	Position next;
}List;

int readFromFile(Position);
int Operation(Position, char*);
int push(Position, int);
int pop(Position);
int GarbageCollector(Position);
Position Allocation();
#endif
