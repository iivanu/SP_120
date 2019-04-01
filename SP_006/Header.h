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
int pushStack(Position, int);
int pushArray(Position, int);
int pop(Position);
int PrintList(Position);
int PrintEl(Position);
int GarbageCollector(Position);