#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>

struct _Polynom;
typedef struct _Polynom* Position;
typedef struct _Polynom
{
	int coef;
	int exp;
	Position next;
}Polynom;

int readFromFile(Position);
Position Allocation();
int PolySum(Position, Position, Position);
int PolyMulty(Position, Position, Position);
int PrintList(Position);
int PrintEl(Position);
int GarbageCollector(Position);
#endif
