#include "Header.h"

int main()
{
	List head;
	int i = -1;
	head.next = NULL;
	i = readFromFile(&head);
	if (i == -1 || head.next->next != NULL)
	{
		printf("Greska!!\n");
		return -1;
	}
	printf("\nRezultat je: %d\n", head.next->el);

	GarbageCollector(head.next);

	return 0;
}