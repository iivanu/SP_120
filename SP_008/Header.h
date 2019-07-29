    
#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _tree;
typedef struct _tree* Position;
typedef struct _tree
{
	char* name;
	Position FChild;
	Position NBrother;
}Tree;

struct _stack;
typedef struct _stack* position;
typedef struct _stack
{
	Position tree;
	position Next;
}Stack;

Position AllocationTree();
position AllocationStack();
Position ChangeDirectory(Position, position, char*);
Position popStack(position);
int pushStack(Position, position);
int MakeDirectory(Position, char*);
int ListDirectory(Position);
int GarbageCollector(Position);
#endif
