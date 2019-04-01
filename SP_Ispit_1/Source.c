#include "Header.h"

int main()
{
	Student head, sort;
	char* name;
	int i = 0;
	position hashFile = NULL;
	
	hashFile = (position)malloc(8 * sizeof(HashTable));
	name = (char*)malloc(21 * sizeof(char));
	sort.Next = NULL;
	head.Next = NULL;
	for (i = 0; i < 8; i++)
		hashFile[i].tree = NULL;

	printf("Unesite ime datoteke: ");
	scanf(" %s", name);

	i = readFromFile(&head, name);
	if (i != 0)
	{
		printf("Greska u programu!!\n");
		return -1;
	}
	printf("\n\n\t\tNesortirana lista:\n");
	PrintList(&head);


	SortList(&head, &sort);
	printf("\n\n\t\tSortirana lista po OrderNum:\n");
	PrintList(&sort);

	CreateHash(hashFile, &sort);
	PrintHash(hashFile);

	GarbageHash(hashFile);
	GarbageList(head.Next);
	GarbageList(sort.Next);
	free(name);

	return 0;
}