#include "Header.h"

int CreateOnBegin(Position head)
{
	Position q = Allocation();
	q = CreateNew(q);

	q->next = head->next;
	head->next = q;

	return 0;
}

int CreateOnEnd(Position P)
{
	Position q = Allocation();
	q = CreateNew(q);

	while (P->next != NULL)
		P = P->next;

	q->next = P->next;
	P->next = q;

	return 0;
}

Position CreateNew(Position q)
{
	char *name;
	char *surname;
	name = (char*)malloc(21 * sizeof(char));
	surname = (char*)malloc(21 * sizeof(char));

	printf("\nDodaj novog:\n");
	printf("Unesite ime: ");
	scanf(" %s", name);
	printf("Unesite prezime: ");
	scanf(" %s", surname);
	printf("Unesite godiste: ");
	scanf(" %d", &q->year);

	q->name = (char*)malloc(strlen(name) + 1);
	q->surname= (char*)malloc(strlen(surname) + 1);
	strcpy(q->name, name);
	strcpy(q->surname, surname);
	
	free(name);
	free(surname);
	
	return q;
}

Position Allocation()
{
	Position q = (Position)malloc(sizeof(Student));

	if (q == NULL)
	{
		printf("\nMemorija nije alocirana!!\n");
		return NULL;
	}

	q->next = NULL;

	return q;
}

int PrintList(Position P)
{
	if (P->next == NULL)
	{
		printf("\nLista je prazna!!\n");
		return -1;
	}

	printf("\nIspis liste:\n");
	while (P->next != NULL)
	{
		PrintOne(P->next);
		P = P->next;
	}

	return 0;
}

int PrintOne(Position q)
{
	printf("%s\t%s\t%d\n", q->name, q->surname, q->year);
	return 0;
}

Position FindEl(Position P, char* surname)
{
	if (P->next == NULL)
	{
		printf("\nLista je prazna!\n");
		return NULL;
	}

	while (P->next != NULL && strcmp(P->next->surname, surname) != 0)
		P = P->next;

	if (P->next == NULL)
	{
		printf("\nStudent nije pronaden!!\n");
		return NULL;
	}

	printf("\nStudent je pronaden:\n");
	printf("%s\t%s\t%d\n", P->next->name, P->next->surname, P->next->year);

	return P;
}


int DeleteEl(Position P, char* surname)
{
	Position q = FindEl(P, surname);
	Position temp = NULL;
	if (q == NULL)
		return -1;

	temp = q->next;
	printf("\nStudent %s %s ce bit izbrisan.\n", temp->name, temp->surname);

	q->next = temp->next;
	free(temp);
	return 0;
}

int GarbageCollector(Position P)
{
	if (P == NULL)
		return 0;
	else if (P->next != NULL)
		GarbageCollector(P->next);

	free(P->name);
	free(P->surname);
	free(P);
	return 0;
}