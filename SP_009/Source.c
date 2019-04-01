#include "Header.h"

int main()
{
	Position root = NULL;
	int i = -1;
	int el;

	while (i != 0)
	{
		printf("\n\nOdaberite radnju:\n");
		printf("1. Dodaj novi element\n");
		printf("2. Ispis stablo(preorder)\n");
		printf("3. Pronadi element\n");
		printf("4. Izbrisi element\n");
		printf("0. Izlaz\n");
		printf("Vas odabir: ");
		scanf(" %d", &i);

		switch (i)
		{
		case 1:
			printf("\n\nUnesite element za dodavanje: ");
			scanf(" %d", &el);
			root = AddNew(root, el);
			break;
		case 2:
			printf("\n\nIspis stabla:\n");
			PrintTree(root);
			break;
		case 3:
			printf("Unesite element za pretragu: ");
			scanf(" %d", &el);
			FindEl(root, el);
			break;
		case 4:
			printf("Unesite element za brisanje: ");
			scanf(" %d", &el);
			DeleteEl(root, el);
			break;
		case 0:
			break;
		default:
			printf("Nepoznata naredba!!\n");
			break;
		}
	}

	GarbageCollector(root);

	return 0;
}