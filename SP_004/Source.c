#include "Header.h"

int main()
{
	Polynom head1, head2, sum, multy;
	head1.next = NULL;
	head2.next = NULL;
	sum.next = NULL;
	multy.next = NULL;

	readFromFile(&head1);
	printf("\nPrvi polinom:\n");
	PrintList(&head1);

	readFromFile(&head2);
	printf("\n\nDrugi polinom:\n");
	PrintList(&head2);

	printf("\n\nZbroj:\n");
	PolySum(&head1, &head2, &sum);
	PrintList(&sum);

	printf("\nUmnozak:\n");
	PolyMulty(&head1, &head2, &multy);
	PrintList(&multy);

	GarbageCollector(head1.next);
	GarbageCollector(head2.next);
	GarbageCollector(sum.next);
	GarbageCollector(multy.next);
	return 0;

}