/*Napisati program koji iz datoteke cita popis studenata i sprema ih u vezanu listu:
struct _student;
typedef struct _student *StudentNode;
typedef struct _student {
int brojIndeksa;
char *ime;
char *prezime;
int orderNum;
StudentNode next;
} Student;

a) Prilikom spremanja studenta u vezanu listu potrebno je studentu dodijeliti orderNum, 
kao slucajno generirani cijeli broj u rasponu od 1 do 1000. Ispisati listu.

b) Iz tako kreirane liste potrebno je kreirati novu vezanu listu u kojoj ce studenti biti sortirani po orderNum.
Ispisati listu. NAPOMENA: Nije dozvoljena nova alokacija elementata pri unosu u novu vezanu listu vec je potrebno 
prebaciti cvorove iz postojece liste.

c) Iz sortirane liste kreirati hash tablicu sa zasebnim redovima od 8 (osam) mjesta. Funkcija preslikavanja kljuc 
racuna kao ostatak cjelobrojnog dijeljenja orderNum s ukupnim brojem elemenata tablice. Studenti s izracunatim kljucem 
se spremaju u binarno stablo po broju indexa.

NAPOMENA: Zatvoriti sve otvorene datoteke, pobrisati svu dinamicki alociranu memoriju i mirnim putem prekinuti rad 
programa. Programski kod napisati kozistentno, uredno te odvojeno u funkcije.*/

#include "Header.h"

int readFromFile(StudentNode P, char* fileName)
{
	FILE *f = NULL;
	char *name;
	char *surname;
	StudentNode q = NULL;
	StudentNode pos = P;

	srand(time(NULL));
	name = (char*)malloc(21 * sizeof(char));
	surname = (char*)malloc(21 * sizeof(char));

	f = fopen(fileName, "r");
	if (f == NULL)
	{
		printf("Datoteka nije otvorena!!\n");
		return -1;
	}

	while (!feof(f))
	{
		q = Allocation();

		fscanf(f, "%d %s %s", &q->indexNum, name, surname);
		q->name = (char*)malloc(strlen(name) + 1);
		q->surname = (char*)malloc(strlen(surname) + 1);
		strcpy(q->name, name);
		strcpy(q->surname, surname);
		q->orderNum = Rgn();

		while (pos->Next != NULL)
			pos = pos->Next;

		q->Next = pos->Next;
		pos->Next = q;
	}

	free(name);
	free(surname);
	fclose(f);
	return 0;
}

int Rgn()
{
	return (1 + (rand() % 1000));
}

StudentNode Allocation()
{
	StudentNode q = (StudentNode)malloc(sizeof(Student));
	if (q == NULL)
	{
		printf("Memorija nije alocirana!!\n");
		return -1;
	}

	return q;
}

int PrintList(StudentNode P)
{
	if (P->Next == NULL)
	{
		printf("Lista je prazna!!\n");
		return -1;
	}

	printf("Ispis liste:\n");
	printf("Indeks         Ime         Prezime         OrderNum\n");
	while (P->Next != NULL)
	{
		PrintOne(P->Next);
		P = P->Next;
	}

	return 0;
}

int PrintOne(StudentNode P)
{
	printf("%2d\t%10s\t%10s\t\t%3d\n", P->indexNum, P->name, P->surname, P->orderNum);
	return 0;

}

int SortList(StudentNode P, StudentNode S)
{
	StudentNode start = S;
	StudentNode q = NULL;

	while (P->Next != NULL)
	{
		q = Pop(P);
		while (start->Next != NULL && start->Next->orderNum < q->orderNum)
			start = start->Next;

		q->Next = start->Next;
		start->Next = q;

		start = S;
	}

	return 0;
}

StudentNode Pop(StudentNode P)
{
	StudentNode temp = P->Next;

	if (temp == NULL)
	{
		printf("Lista je prazna!!\n");
		return NULL;
	}

	P->Next = temp->Next;

	return temp;
}

int CreateHash(position hashfile, StudentNode P)
{
	StudentNode q;
	int hashPos;
	while (P->Next != NULL)
	{
		q = Pop(P);
		q->Next = NULL;
		hashPos = calcHash(q->orderNum);
		hashfile[hashPos].el = hashPos;
		hashfile[hashPos].tree = PutInHash(hashfile[hashPos].tree, q);
	}

	return 0;
}

Position AllocationTree()
{
	Position q = (Position)malloc(sizeof(Tree));

	if (q == NULL)
	{
		printf("Alokacija memorije nije uspijela!!\n");
		return NULL;
	}

	q->left = NULL;
	q->right = NULL;
	return q;
}


int calcHash(int orderNum)
{
	return orderNum % 8;
}

Position PutInHash(Position tree, StudentNode q)
{
	if (tree == NULL)
	{
		tree = AllocationTree();
		tree->student = q;
	}
	else if (tree->student->indexNum > q->indexNum)
		tree->left = PutInHash(tree->left, q);
	else if (tree->student->indexNum < q->indexNum)
		tree->right = PutInHash(tree->right, q);

	return tree;
}

int PrintHash(position hash)
{
	int i = 0;

	printf("\n\n\n\n\t\t\tHash Tablica:");
	for (i = 0; i < 8; i++)
	{
		if (hash[i].tree != NULL)
		{
			printf("\n\nPozicija %d:\n", i);
			printf("Indeks         Ime         Prezime         OrderNum\n");
			PrintTree(hash[i].tree);
		}
	}

	return 0;
}

int PrintTree(Position tree)
{
	if (tree == NULL)
		return 0;
	PrintTree(tree->left);
	printf("%2d\t%10s\t%10s\t\t%3d\n", tree->student->indexNum, tree->student->name, tree->student->surname, tree->student->orderNum);
	PrintTree(tree->right);

	return 0;
}

int GarbageHash(position hash)
{
	int i = 0;

	for (i = 0; i < 8; i++)
	{
		if (hash[i].tree != NULL)
			GarbageTree(hash[i].tree);
	}

	free(hash);
	return 0;
}

int GarbageTree(Position tree)
{
	if (tree->left != NULL)
		GarbageTree(tree->left);

	else if (tree->right != NULL)
		GarbageTree(tree->right);

	free(tree->student->name);
	free(tree->student->surname);
	free(tree->student);
	free(tree);

	return 0;
}

int GarbageList(StudentNode P)
{
	if (P == NULL)
		return -1;

	else if (P->Next != NULL)
		GarbageList(P->Next);

	free(P->name);
	free(P->surname);
	free(P);

	return 0;
}