Napisati program koji iz datoteke cita popis studenata i sprema ih u vezanu listu:

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
programa. Programski kod napisati kozistentno, uredno te odvojeno u funkcije.
