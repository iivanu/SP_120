#include "Header.h"

int readFromFile(Position P)
{
	char* name = NULL;
	Position Start = P;
	Position q = NULL;
	FILE *f;
	name = (char*)malloc(21 * sizeof(char));

	printf("\nUnesite ime datoteke: ");
	scanf(" %s", name);

	f = fopen(name, "r");
	if (f == NULL)
	{
		printf("Datoteka nije otvorena!!\n");
		return -1;
	}

	while (!feof(f))
	{
		q = Allocation();

		fscanf(f, " %d", &q->el);

		while (Start->next != NULL && Start->next->el > q->el)
			Start = Start->next;

		if (Start->next != NULL && q->el == Start->next->el)
			free(q);

		else
		{
			q->next = Start->next;
			Start->next = q;
		}

		Start = P;
	}

	fclose(f);
	free(name);

	return 0;
}

Position Allocation()
{
	Position q = (Position)malloc(sizeof(List));
	if (q == NULL)
	{
		printf("Alokacija memorije nije uspijela!!\n");
		return NULL;
	}

	return q;
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

int Union(Position P1, Position P2, Position uni)
{
	Position q = NULL;

	while (P1->next != NULL && P2->next != NULL) //Radi ako je isto elemenata
	{
		q = Allocation();

		if (P1->next->el > P2->next->el)
		{
			q->el = P1->next->el;
			q->next = uni->next;
			uni->next = q;

			uni = uni->next;
			P1 = P1->next;
		}
		else if (P1->next->el < P2->next->el)
		{
			q->el = P2->next->el;
			q->next = uni->next;
			uni->next = q;

			uni = uni->next;
			P2 = P2->next;
		}

		else
		{
			q->el = P2->next->el;
			q->next = uni->next;
			uni->next = q;

			uni = uni->next;
			P2 = P2->next;
			P1 = P1->next;
		}
	}

	return 0;
}

int Section(Position P1, Position P2, Position sec)
{
	Position q = NULL;

	while (P1->next != NULL && P2->next != NULL)
	{
		if (P1->next->el > P2->next->el)
			P1 = P1->next;

		else if (P1->next->el < P2->next->el)
			P2 = P2->next;

		if (P1->next != NULL && P2->next != NULL && P1->next->el == P2->next->el)
		{
			q = Allocation();
			q->el = P1->next->el;

			q->next = sec->next;
			sec->next = q;

			sec = sec->next;
			P1 = P1->next;
			P2 = P2->next;
		}
	}

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