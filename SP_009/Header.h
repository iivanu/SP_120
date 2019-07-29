#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>

struct _tree;
typedef struct _tree* Position;
typedef struct _tree
{
	int el;
	Position left;
	Position right;
}Tree;

Position Allocation();
Position AddNew(Position, int);
Position FindEl(Position, int);
Position DeleteEl(Position, int);
Position FindMin(Position);
Position FindMax(Position);
int PrintTree(Position);
int GarbageCollector(Position);
#endif
