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
	q->surname = (char*)malloc(strlen(surname) + 1);
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
	printf("%s\t%s\t\t%d\n", q->name, q->surname, q->year);
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

int AddBehind(Position P, char* surname)
{
	Position q = FindEl(P, surname);
	Position z = NULL;
	if (q == NULL)
	{
		free(z);
		return -1;
	}
	q = q->next;
	z = Allocation();
	z = CreateNew(z);
	z->next = q->next;
	q->next = z;

	return 0;
}

int AddBefore(Position P, char* surname)
{
	Position q = FindEl(P, surname);
	Position z = NULL;
	if (q == NULL)
	{
		free(z);
		return -1;
	}
	z = Allocation();
	z = CreateNew(z);
	z->next = q->next;
	q->next = z;

	return 0;
}

Position Sort(Position P) //Nije napisano po njegovom kodu
{
	Student q;
	Position head = &q;
	Position z = NULL;
	q.next = NULL;
	while (P->next != NULL)
	{
		while (head->next != NULL && strcmp(P->next->surname, head->next->surname) > 0)
			head = head->next;

		z = Allocation();
		z->name = (char*)malloc(sizeof(P->next->name) + 1);
		z->surname = (char*)malloc(sizeof(P->next->surname) + 1);
		strcpy(z->name, P->next->name);
		strcpy(z->surname, P->next->surname);
		z->year = P->next->year;

		z->next = head->next;
		head->next = z;
		P = P->next;
		head = &q;
	}

	GarbageCollector(P->next);
	return q.next;
}

int Export(Position P)
{
	char *name=NULL;
	FILE *f;

	name = (char*)malloc(21 * sizeof(char));

	printf("Unesite ime datoteke za ispis: ");
	scanf(" %s", name);
	f = fopen(name, "w");
	
	if (f == NULL)
	{
		printf("Datoteka nije otvorena");
		return -1;
	}

	while (P->next != NULL)
	{
		fprintf(f, "%s %s %d\n", P->next->name, P->next->surname, P->next->year);
		P = P->next;
	}

	printf("\nLista je uspjesno ispisana u datoteku!!\n");

	free(name);
	fclose(f);

	return 0;
}

int Import(Position P)
{
	char* name=NULL;
	char* a = NULL;
	char* b = NULL;
	FILE *f;
	Position q = NULL;

	name = (char*)malloc(21 * sizeof(char));
	a = (char*)malloc(21 * sizeof(char));
	b = (char*)malloc(21 * sizeof(char));
	printf("Unesite ime datoteke: ");
	scanf(" %s", name);

	f = fopen(name, "r");
	if (f == NULL)
	{
		printf("Datoteka nije otvorena!!\n");
		return -1;
	}

	while (P->next != NULL)
		P = P->next;


	while (!feof(f))
	{
		q = Allocation();
		fscanf(f, " %s %s %d", a, b, &q->year);
		q->name = (char*)malloc(strlen(a) + 1);
		q->surname = (char*)malloc(strlen(b) + 1);
		strcpy(q->name, a);
		strcpy(q->surname, b);
		q->next = P->next;
		P->next = q;
		P = P->next;
	}

	printf("\nLista je uspjesno procitana iz datoteke!!\n");

	free(a);
	free(b);
	free(name);
	fclose(f);
	return 0;
}