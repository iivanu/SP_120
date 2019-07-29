#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _list;
typedef struct _list* position;
typedef struct _list
{
	char* name;
	char* surname;
	int MB;
	position next;
}List;

struct _hashTable;
typedef struct _hashTable* Position;
typedef struct _hashTable
{
	int el;
	position student;
}HashTable;

position Allocation();
int readFromFile(Position, char*);
int calcHash(char*);
position PutInList(Position, position);
int PrintList(Position);
int PrintElement(position, int);
int FindStudent(Position, char*, char*);
int GarbageCollectorHash(Position);
int GarbageCollectorList(position);
#endif
