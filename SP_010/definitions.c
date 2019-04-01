#include "Header.h"

Position AllocationT()
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

position AllocationS()
{
	position q = (position)malloc(sizeof(Stack));
	if (q == NULL)
	{
		printf("Memorija nije alocirana!!\n");
		return NULL;
	}

	return q;
}

int ReadFromFile(position stack, char* name)
{
	FILE *f = fopen(name, "r");
	char *buffer;
	buffer = (char*)malloc(10 * sizeof(char));

	if (f == NULL)
	{
		printf("Datoteka nije otvorena!!\n");
		return -1;
	}

	while (!feof(f))
	{
		fscanf(f, " %s", buffer);
		if (operation(stack, buffer) == -1)
			return -1;
	}
}

int operation(position stack, char* buffer)
{
	int i;
	Position tmp1 = AllocationT();
	Position tmp2 = AllocationT();
	Position P = AllocationT();
	switch (*buffer)
	{
	case '+':
		tmp2 = popStack(stack);
		tmp1 = popStack(stack);
		if (tmp1 == NULL)
			return -1;
		P = AllocationT();
		P->el = (char*)malloc(strlen(buffer) + 1);
		strcpy(P->el, "+");
		P->left = tmp1;
		P->right = tmp2;
		pushStack(stack, P);
		break;
	case '-':
		tmp2 = popStack(stack);
		tmp1 = popStack(stack);
		if (tmp1 == NULL)
			return -1;
		P = AllocationT();
		P->el = (char*)malloc(strlen(buffer) + 1);
		strcpy(P->el, "-");
		P->left = tmp1;
		P->right = tmp2;
		pushStack(stack, P);
		break;
	case '*':
		tmp2 = popStack(stack);
		tmp1 = popStack(stack);
		if (tmp1 == NULL)
			return -1;
		P = AllocationT();
		P->el = (char*)malloc(strlen(buffer) + 1);
		strcpy(P->el, "*");
		P->left = tmp1;
		P->right = tmp2;
		pushStack(stack, P);
		break;
	case '/':
		tmp2 = popStack(stack);
		tmp1 = popStack(stack);
		if (tmp1 == NULL || tmp2 == '0')
			return -1;
		P = AllocationT();
		P->el = (char*)malloc(strlen(buffer) + 1);
		strcpy(P->el, "/");
		P->left = tmp1;
		P->right = tmp2;
		pushStack(stack, P);
		break;
	default:
		if (sscanf(buffer, "%d", &i) != 1)
		{
			printf("Nepoznat znak u datoteci!!\n");
			return -1;
		}

		else
		{
			P->el = (char*)malloc(strlen(buffer) + 1);
			strcpy(P->el, buffer);
			pushStack(stack, P);
		}
		break;
	}

	return 0;
}

int pushStack(position stack, Position P)
{
	position q = AllocationS();

	q->operand = P;
	q->Next = stack->Next;
	stack->Next = q;

	return 0;
}

Position popStack(position stack)
{
	position temp = NULL;

	if (stack->Next == NULL)
	{
		printf("Nema niceg na stogu!!\n");
		return NULL;
	}
	temp = stack->Next;
	stack->Next = temp->Next;

	return temp->operand;
}

int PrintTree(Position P)
{
	if (P != NULL)
	{
		PrintTree(P->left);
		printf("%s ", P->el);
		PrintTree(P->right);
	}
	return 0;
}

int GarbageCollector(Position P)
{
	if (P == NULL)
		return -1;

	else if (P->left != NULL)
		GarbageCollector(P->left);

	else if (P->right != NULL)
		GarbageCollector(P->right);

	free(P->el);
	free(P);

	return 0;
}