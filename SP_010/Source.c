#include "Header.h"

int main()
{
	Stack head;
	char* name = NULL;
	head.Next = NULL;
	name = (char*)malloc(21 * sizeof(char));

	printf("Unesite ime datoteke: ");
	scanf(" %s", name);
	if (ReadFromFile(&head, name) == -1 || head.Next->Next != NULL)
	{
		printf("Nemoguca kalkulacija!!\n");
		return -1;
	}

	PrintTree(head.Next->operand);

	GarbageCollector(head.Next->operand);
	free(head.Next);
	free(name);

	return 0;
}