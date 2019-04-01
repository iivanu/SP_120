#include "Header.h"

int main()
{
	List head1, head2, uni, sec;
	head1.next = NULL;
	head2.next = NULL;
	uni.next = NULL;
	sec.next = NULL;

	readFromFile(&head1);
	printf("\n\nPrva lista:\n");
	PrintList(&head1);

	readFromFile(&head2);
	printf("\n\nDruga lista:\n");
	PrintList(&head2);

	Union(&head1, &head2, &uni);
	printf("\nUnija:\n");
	PrintList(&uni);

	Section(&head1, &head2, &sec);
	printf("\nPresjek:\n");
	PrintList(&sec);

	GarbageCollector(head1.next);
	GarbageCollector(head2.next);
	GarbageCollector(uni.next);
	GarbageCollector(sec.next);

	return 0;
}
