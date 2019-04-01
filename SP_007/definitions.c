#include "Header.h"

int readFromFile(Position P)
{
	char* name;
	char *buffer;
	int i;
	FILE *f = NULL;
	name = (char*)malloc(21*sizeof(char));
	buffer = (char*)malloc(10 * sizeof(char));
	printf("Unesite ime datoteke: ");
	scanf(" %s", name);

	f = fopen(name, "r");
	if (f == NULL)
	{
		printf("Datoteka nije otvorena!!\n");
		return -1;
	}

	while (!feof(f))
	{
		fscanf(f, " %s", buffer);
		i = Operation(P, buffer);
		if (i != 0)
			return -1;
	}

	free(buffer);
	free(name);
	fclose(f);

	return 0;
}

int Operation(Position P, char* buff)
{
	int i;
	int a, b;

	switch (*buff)
	{
	case '+':
		a = pop(P);
		b = pop(P);
		if (a == -2 || b == -2)
			return -1;
		push(P, b + a);
		break;
	case '-':
		a = pop(P);
		b = pop(P);
		if (a == -2 || b == -2)
			return -1;
		push(P, b - a);
		break;
	case'*':
		a = pop(P);
		b = pop(P);
		if (a == -2 || b == -2)
			return -1;
		push(P, b * a);
		break;
	case '/':
		a = pop(P);
		b = pop(P);
		if (a == -2 || b == -2 || a == 0)
			return -1;
		push(P, b / a);
		break;
	default:
		if (sscanf(buff, "%d", &i) != 1)
		{
			printf("Znak nije procitan!!\n");
			return -1;
		}
		else
			push(P, i);
	}

	return 0;
}

int push(Position P, int x)
{
	Position q = Allocation();
	q->el = x;
	q->next = P->next;
	P->next = q;

	return 0;
}

int pop(Position P)
{
	int y;
	Position temp;
	if (P->next == NULL)
	{
		printf("Stog je prazan!!\n");
		return -2;
	}

	temp = P->next;
	y = temp->el;
	P->next = temp->next;
	free(temp);

	return y;
}

Position Allocation()
{
	Position q = (Position)malloc(sizeof(List));
	if (q == NULL)
	{
		printf("Memorija nije alocirana!!\n");
		return NULL;
	}

	return q;
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