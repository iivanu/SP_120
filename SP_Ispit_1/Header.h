#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct _student;
typedef struct _student* StudentNode;
typedef struct _student
{
	int indexNum;
	char* name;
	char* surname;
	int orderNum;
	StudentNode Next;
}Student;

struct _tree;
typedef struct _tree* Position;
typedef struct _tree
{
	StudentNode student;
	Position left;
	Position right;
}Tree;

struct _hash;
typedef struct _hash* position;
typedef struct _hash
{
	int el;
	Position tree;
}HashTable;

int readFromFile(StudentNode, char*);
int Rgn();
StudentNode Allocation();
int PrintList(StudentNode);
int PrintOne(StudentNode);
int SortList(StudentNode, StudentNode);
StudentNode Pop(StudentNode);
int CreateHash(position, StudentNode);
int calcHash(int);
Position AllocationTree();
Position PutInHash(Position, StudentNode);
int PrintHash(position);
int PrintTree(Position);
int GarbageHash(position);
int GarbageTree(Position);
int GarbageList(StudentNode);