#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _tree;
typedef struct _tree* Position;
typedef struct _tree
{
	char* el;
	Position left;
	Position right;
}Tree;

struct _stack;
typedef struct _stack* position;
typedef struct _stack
{
	Position operand;
	position Next;
}Stack;

Position AllocationT();
position AllocationS();
int ReadFromFile(position, char*);
int pushStack(position, Position);
Position popStack(position);
int operation(position, char*);
int PrintTree(Position);
int GarbageCollector(Position);