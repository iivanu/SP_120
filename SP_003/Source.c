#include "Header.h"

int main()
{
	Student head;
	int i = 1;
	char *surname = NULL;
	head.next = NULL;
	surname = (char*)malloc(20 * sizeof(char));

	while (i != 0)
	{
		printf("\n\n\tMENI\n");
		printf("1. Dodaj na pocetak\n");
		printf("2. Ispisi listu\n");
		printf("3. Dodaj na kraj\n");
		printf("4. Pronadi po prezimenu\n");
		printf("5. Brisi odredeni\n");
		printf("6. Dodaj iza odredenog\n");
		printf("7. Dodaj ispred odredenog\n");
		printf("8. Sortiraj listu\n");
		printf("9. Upisi u datoteku\n");
		printf("10. Ucitaj iz datoteke\n");
		printf("0. izlaz\n");
		printf("Vas odabir: ");
		scanf(" %d", &i);


		switch (i)
		{
		case 1:
			CreateOnBegin(&head);
			break;
		case 2:
			PrintList(&head);
			break;
		case 3:
			CreateOnEnd(&head);
			break;
		case 4:
			printf("Unesite prezime za pretragu: ");
			scanf(" %s", surname);
			FindEl(&head, surname);
			break;
		case 5:
			printf("Unesite prezime za brisanje: ");
			scanf(" %s", surname);
			DeleteEl(&head, surname);
			break;
		case 6:
			printf("Unesite prezime iza kojeg zelite dodati: ");
			scanf(" %s", surname);
			AddBehind(&head, surname);
			break;
		case 7:
			printf("Unesite prezime ispred kojeg zelite dodati: ");
			scanf(" %s", surname);
			AddBefore(&head, surname);
			break;
		case 8:
			head.next=Sort(&head);
			break;
		case 9:
			Export(&head);
			break;
		case 10:
			Import(&head);
			break;
		case 0:
			break;

		}
	}

	free(surname);
	GarbageCollector(head.next);

	return 0;
}