#include "Header.h"

Position Allocation()
{
	Position q = (Position)malloc(sizeof(List));
	if (q == NULL)
	{
		printf("Memorija nije alocirana!\n");
		return NULL;
	}

	return q;
}

int pushStack(Position P, int x)
{
	Position q = Allocation();
	q->el = x;
	q->next = P->next;
	P->next = q;
	return 0;
}

int pushArray(Position P, int x)
{
	Position q = Allocation();
	q->el = x;

	while (P->next != NULL)
		P = P->next;

	q->next = P->next;
	P->next = q;

	return 0;
}

int pop(Position P)
{
	Position tmp = P->next;

	if (tmp == NULL)
	{
		printf("Lista je prazna!!\n");
		return -1;
	}

	P->next = tmp->next;
	free(tmp);

	return 0;
}

int PrintList(Position P)
{
	if (P->next == NULL)
	{
		printf("Lista je prazna!!\n");
		return -1;
	}

	while (P->next != NULL)
	{
		PrintEl(P->next);
		P = P->next;
	}

	return 0;
}

int PrintEl(Position P)
{
	printf("%d\n", P->el);
	return 0;
}

int GarbageCollector(Position P)
{
	if (P == NULL)
		return -1;

	else if (P->next != NULL)
		GarbageCollector(P->next);

	free(P);
	return 0;
}