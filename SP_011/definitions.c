#include "Header.h"

position Allocation()
{
	position q = (position)malloc(sizeof(List));
	if (q == NULL)
	{
		printf("Alokacija memorije nije uspijela!!\n");
		return NULL;
	}
	q->next = NULL;
	q->name = NULL;
	q->surname=NULL;
	return q;
}

int readFromFile(Position hashTable, char* name)
{
	FILE *f = NULL;
	position q = NULL;
	int hash = -1;
	char* name1 = NULL;
	char* surname = NULL;


	name1 = (char*)malloc(21 * sizeof(char));
	surname = (char*)malloc(21 * sizeof(char));

	f = fopen(name, "r");

	if (f == NULL)
	{
		printf("Datoteka nije otvorena!!\n");
		return -1;
	}

	while (!feof(f))
	{
		name1 = (char*)malloc(21 * sizeof(char));
		surname = (char*)malloc(21 * sizeof(char));
		q = Allocation();
		fscanf(f, " %s %s %d", name1, surname, &q->MB);
		
		q->name = (char*)malloc(strlen(name1) + 1);
		q->surname = (char*)malloc(strlen(surname) + 1);
		
		strcpy(q->surname, surname);
		strcpy(q->name, name1);

		hash = calcHash(q->surname);
		hashTable[hash].el = hash;
		hashTable[hash].student = PutInList(&hashTable[hash], q);
	}


	free(name1);
	free(surname);
	fclose(f);

	return 0;
}

int calcHash(char* surname)
{
	int counter = 0;
	int i = 0;
	while (i < 5 && surname[i] != '\0')
	{
		counter += (int)surname[i];
		i++;
	}

	return counter % 11;
}

position PutInList(Position hashTable, position q)
{
	position x = hashTable->student;
	
	if (x == NULL)
		return q;

	if (strcmp(q->surname, x->surname) > 0 ||
		(strcmp(q->surname, x->surname) == 0 && strcmp(q->name, x->name) > 0))
	{
		q->next = x;
		return q;
	}

	else
	{
		while (x->next != NULL && (strcmp(q->surname, x->next->surname) < 0))
			x = x->next;

		if (strcmp(q->surname, x->next->surname) == 0)
			while (x->next != NULL && strcmp(q->surname, x->next->surname) == 0 && strcmp(q->name, x->name) < 0)
				x = x->next;

		q->next = x->next;
		x->next = q;

		return hashTable->student;
	}

}

int PrintList(Position hashTable)
{
	printf("\n\n\tHASH TABLE\n");
	for (int i = 0; i < 11; i++)
		if (hashTable[i].student != NULL)
			PrintElement(hashTable[i].student, i);

	return 0;
}

int PrintElement(position student, int i)
{
	printf("\nPozicija %d:\n", i);
	while (student != NULL)
	{
		printf("Ime: %s\tPrezime:%s\n", student->name, student->surname);
		student = student->next;
	}

	return 0;
}

int FindStudent(Position hashTable, char* name, char* surname)
{
	int hash = calcHash(surname);
	position q = hashTable[hash].student;

	while (q != NULL)
	{
		if (strcmp(q->name, name) == 0 && strcmp(q->surname, surname) == 0)
		{
			printf("\nTrazeni student: %s %s %d\n", q->name, q->surname, q->MB);
			return 0;
		}
		q = q->next;
	}

	printf("Trazeni student ne postoji u tablici!!\n");
	return -1;
}

int GarbageCollectorHash(Position hash)
{
	int i = 0;

	for (i = 0; i < 11; i++)
	{
		if (hash[i].student != NULL)
			GarbageCollectorList(hash[i].student);
	}
	free(hash);
	return 0;
}

int GarbageCollectorList(position student)
{
	if (student == NULL)
		return -1;

	else if (student->next != NULL)
		GarbageCollectorList(student->next);

	free(student->name);
	free(student->surname);
	free(student);

	return 0;
}