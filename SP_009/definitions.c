#include "Header.h"

Position Allocation()
{
	Position q = (Position)malloc(sizeof(Tree));
	if (q == NULL)
	{
		printf("Memorija nije alocirana!!\n");
		return NULL;
	}

	q->left = NULL;
	q->right = NULL;

	return q;
}

Position AddNew(Position P, int x)
{
	if (P == NULL)
	{
		P = Allocation();
		P->el = x;
	}

	else if (P->el > x)
		P->left = AddNew(P->left, x);

	else if (P->el < x)
		P->right = AddNew(P->right, x);

	return P;
}

Position FindEl(Position P, int x)
{
	if (P->el == x)
	{
		printf("Element je pronaden!!\n");
		return P;
	}

	else if (P->el > x)
		return FindEl(P->left, x);

	else if (P->el < x)
		return FindEl(P->right, x);
}

int PrintTree(Position P)
{
	if (P == NULL)
		return P;
	printf("%d\n", P->el);
	PrintTree(P->left);
	PrintTree(P->right);

	return 0;
}

Position DeleteEl(Position P, int x)
{
	Position temp = NULL;
	if (P == NULL)
		printf("Trazeni element ne postoji u stablu!!\n");

	else if (x < P->el)
		P->left = DeleteEl(P->left, x);

	else if (x > P->el)
		P->right = DeleteEl(P->right, x);

	else
	{
		if (P->left != NULL && P->right != NULL)
		{
			temp = FindMin(P->right);
			P->el = temp->el;
			P->right = DeleteEl(P->right, P->el);
		}

		else
		{
			temp = P;
			if (P->left == NULL)
				P = P->right;

			else
				P = P->left;

			free(temp);
		}
	}

	return P;
}

Position FindMin(Position P)
{
	if (P == NULL)
		return P;

	while (P->left != NULL)
		P = P->left;

	return P;
}

int GarbageCollector(Position P)
{
	if (P == NULL)
		return -1;

	else if (P->left != NULL)
		GarbageCollector(P->left);

	else if(P->right !=NULL)
	{
		GarbageCollector(P->right);
	}

	free(P);
	
	return 0;
}