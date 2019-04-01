#include "Header.h"

int readFromFile(Position P)
{
	Position start = P;
	FILE *f;
	char *name;
	name = (char*)malloc(21 * sizeof(char));
	printf("\nUnesite ime datoteke: ");
	scanf(" %s", name);
	
	f = fopen(name, "r");
	if (f == NULL)
	{
		printf("Datoteka nije otvorena!\n");
		return -1;
	}

	while (!feof(f))
	{
		Position q = Allocation();
		fscanf(f, "%d %d", &q->exp, &q->coef);

		while (start->next != NULL && q->exp < start->next->exp)
			start = start->next;

		if (start->next != NULL && start->next->exp == q->exp)
		{
			start->next->coef += q->coef;
			free(q);
		}

		else
		{
			q->next = start->next;
			start->next = q;
		}

		start = P;
	}

	free(name);
	fclose(f);
	return 0;
}

Position Allocation()
{
	Position q = (Position)malloc(sizeof(Polynom));
	if (q == NULL)
	{
		printf("Memorija nije alocirana!\n");
		return NULL;
	}

	q->next = NULL;

	return q;
}

int PrintList(Position P)
{
	if (P->next == NULL)
	{
		printf("Lista je prazna!!\n");
		return -1;
	}

	printf("Eksponent\tKoeficijent:\n");
	while (P->next != NULL)
	{
		PrintEl(P->next);
		P = P->next;
	}

	return 0;
}

int PrintEl(Position P)
{
	if (P->coef != 0)
		printf("%d\t\t%d\n", P->exp, P->coef);
	return 0;
}

int PolySum(Position P1, Position P2, Position Sum)
{
	while (P1->next != NULL && P2->next != NULL)
	{
		Position q = Allocation();
		if (P1->next->exp > P2->next->exp)
		{
			q->exp = P1->next->exp;
			q->coef = P1->next->coef;
			q->next = Sum->next;
			Sum->next = q;
			Sum = Sum->next;
			P1 = P1->next;
		}

		else if (P1->next->exp < P2->next->exp)
		{
			q->exp = P2->next->exp;
			q->coef = P2->next->coef;
			q->next = Sum->next;
			Sum->next = q;
			Sum = Sum->next;
			P2 = P2->next;
		}
		else
		{
			q->exp = P2->next->exp;
			q->coef = P2->next->coef + P1->next->coef;
			q->next = Sum->next;
			Sum->next = q;
			Sum = Sum->next;
			P1 = P1->next;
			P2 = P2->next;
		}
	}

	return 0;
}

int PolyMulty(Position P1, Position P2, Position Multy)
{
	Position P2Start = P2;
	Position MultyStart = Multy;
	Position q = NULL;
	while (P1->next != NULL)
	{
		while (P2Start->next != NULL)
		{
			q = Allocation();
			q->exp = P1->next->exp + P2Start->next->exp;
			q->coef = P1->next->coef * P2Start->next->coef;

			while (MultyStart->next != NULL && MultyStart->next->exp > q->exp)
				MultyStart = MultyStart->next;

			if (MultyStart->next != NULL && MultyStart->next->exp == q->exp)
			{
				MultyStart->next->coef += q->coef;
				free(q);
			}

			else
			{
				q->next = MultyStart->next;
				MultyStart->next = q;
			}

			MultyStart = Multy;
			P2Start = P2Start->next;
		}

		P2Start = P2;
		P1 = P1->next;
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