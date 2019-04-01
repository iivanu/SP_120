#include "Header.h"

int main()
{
	char *name;
	char *name1;
	char *surname;
	Position hashTable = (Position)malloc(11 * sizeof(HashTable));

	name1 = (char*)malloc(21 * sizeof(char));
	name = (char*)malloc(21 * sizeof(char));
	surname = (char*)malloc(21 * sizeof(char));

	for (int i = 0; i < 11; i++)
		hashTable[i].student = NULL;

	printf("Unesite ime datoteke: ");
	scanf(" %s", name1);

	readFromFile(hashTable, name1);
	PrintList(hashTable);


	printf("\n\nUnesite ime i prezime studenta za ispis MB-a: ");
	scanf(" %s %s", name, surname);
	FindStudent(hashTable, name, surname);

	GarbageCollectorHash(hashTable);

	return 0;
}