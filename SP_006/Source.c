#include "Header.h"

int main()
{
	int i = 1;
	List headS, headA;
	headS.next = NULL;
	headA.next = NULL;

	while (i != 0)
	{
		int x;
		printf("\n\nOdaberite radnju:\n");
		printf("1. Push stog\n");
		printf("2. Push red\n");
		printf("3. Pop stog\n");
		printf("4. Pop red\n");
		printf("5. Ispisi stog\n");
		printf("6. Ispisi red\n");
		printf("Vas odabir: ");
		scanf(" %d", &i);

		switch (i)
		{
		case 1:
			x = ((rand() % 91) + 10);
			pushStack(&headS, x);
			break;
		case 2:
			x = ((rand() % 91) + 10);
			pushArray(&headA, x);
			break;
		case 3:
			pop(&headS);
			break;
		case 4:
			pop(&headA);
			break;
		case 5:
			PrintList(&headS);
			break;
		case 6:
			PrintList(&headA);
			break;
		case 0:
			break;
		}
	}

	GarbageCollector(headA.next);
	GarbageCollector(headS.next);

	return 0;
}