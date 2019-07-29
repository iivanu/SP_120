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

Position Allocation();
int readFromFile(Position);
int Union(Position, Position, Position);
int Section(Position, Position, Position);
int PrintList(Position);
int PrintEl(Position);
int GarbageCollector(Position);
#endif
