#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h> 
using namespace std;

//elso feladat listaja
struct Node {
	int kod;
	char nev[5];
	int mennyiseg;
	int ar;
	struct Node* next;
};
struct Node* head = NULL;

//harmas feladat vektor
int vektor[3];
void nullazasVektor() {
	vektor[1] = 0;
	vektor[2] = 0;
	vektor[3] = 0;

}

//masodik feladat listai
//egyszeres lista
struct Node1 {
	int adat1;
	struct Node1* next1;
};
struct Node1* head1 = NULL;
//2xes lista
struct Node2
{
	int adat2;
	struct Node2* next2;
	struct Node2* prev2;
};
struct Node2* head2 = NULL;

//2xeresen lancolt lista 4ES FELADATHOZ
struct Node4
{
	int data4;
	struct Node4* next4;
	struct Node4* prev4;
};
struct Node4* head4 = NULL;
//4 es feladathoz globalis valtozo
int elem_szamlalo = 0;

//globalis szamlalok
int oszE = 0;

////////////////////////elso feladat
void pushAR(int ujElem)
{
	struct Node* elem;

	elem = (struct Node*)malloc(sizeof(struct Node));

	elem->ar = ujElem;
	if (head == NULL) {
		head = elem;
		head->next = NULL;
	}
	oszE = oszE + ujElem;
	cout << "\n\t " << ujElem << "<---Hozzaadva\n";
}

void pushKod(int ujElem)
{
	struct Node* elem;

	elem = (struct Node*)malloc(sizeof(struct Node));

	elem->kod = ujElem;
	if (head == NULL) {
		head = elem;
		head->next = NULL;
	}
	cout << "\n\t " << ujElem << "<---Hozzaadva\n";
}
//hiba
void osszertek_bylist()
{
	int osszE2 = 0;
	while (head->next != NULL)
	{
		osszE2 = head->ar + osszE2;
	}
	cout << "\n\taz ossz ar :" << osszE2 << endl;
}

void osszertek_byszamlalo()
{
	cout << "\n\taz ossz ar :" << oszE << endl;
}

void athaladas3()
{
	struct Node* adat33;

	adat33 = head;

	if (adat33 == NULL)
	{
		cout << "\nuress a lista\n";
	}
	else {
		while (adat33->next != NULL)
		{
			cout << adat33->kod << "-->";
			adat33 = adat33->next;
		}
		cout << "NULL";
	}

}

//////harmas lenyege

void lista_feltoltes(struct Node** head_masolat, int UjADAt)
{

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->kod = UjADAt;

	newNode->next = (*head_masolat);
	(*head_masolat) = newNode;
}

void ellenorzes_3asfeladat()
{
	struct Node* temp3;

	temp3 = head;

	if (temp3 == NULL)
	{
		cout << "\nuress a lista\n";
	}
	else {
		while (temp3->next != NULL)
		{
			if (temp3->kod < 0)
			{
				//ha == - ertek
				//////vektorhoz rendeles
				vektor[1]++;
			}
			else if (temp3->kod > 0)
			{
				// ha == + ertek
					///////vektorhoz rendeles
				vektor[2]++;
			}
			else
			{
				// ha == 0
			//vektorhoz rendeles
				vektor[3]++;
			}
			temp3 = temp3->next;
		}

	}
}

////////////////////////masodik feladat


///// REKURZIV MEGOLDAS
void eloremegadott_adatokkal_valo_feltoltese(int a)
{
	struct Node1* elem;

	elem = (struct Node1*)malloc(sizeof(struct Node1));
	elem->adat1 = a;


	if (head1 == NULL)
	{
		head1 = elem;
		head1->next1 = NULL;
	}

	/*eloremegadott_adatokkal_valo_feltoltese(1);
	eloremegadott_adatokkal_valo_feltoltese(21);
	eloremegadott_adatokkal_valo_feltoltese(15);
	eloremegadott_adatokkal_valo_feltoltese(11);
	eloremegadott_adatokkal_valo_feltoltese(31);
	eloremegadott_adatokkal_valo_feltoltese(25);
	*/
}

void lista_feltoltese(int a)
{
	struct Node1* elem;

	elem = (struct Node1*)malloc(sizeof(struct Node1));
	elem->adat1 = a;


	if (head1 == NULL)
	{
		head1 = elem;
		head1->next1 = NULL;
	}
}

void duplalista_ellenorzes()
{
	if (head2 == NULL)
	{
		cout << "\na lista uress, folytathatja a muveletet\n";
	}
}

void BeIllestes(struct Node1* node)
{


	if (node != NULL)
	{
		int newdata = head1->adat1;
		//head2->adat2 = newdata;
		struct Node2* newnode = (struct Node2*)malloc(sizeof(struct Node2));
		newnode->adat2 = newdata;
		newnode->prev2 = NULL;
		newnode->next2 = head2;
		if (head2 != NULL)
			head2->prev2 = newnode;
		head2 = newnode;
		cout << head2->adat2 << "-->";
	}
}

void node_torlese(Node2** head_ref, Node2* del)
{

	if (*head_ref == NULL || del == NULL)
		return;

	if (*head_ref == del)
		*head_ref = del->next2;

	if (del->next2 != NULL)
		del->next2->prev2 = del->prev2;

	if (del->prev2 != NULL)
		del->prev2->next2 = del->next2;

	free(del);
	return;
}

void limittorles(struct Node2** headReferencia, int limit)
{
	struct Node2* p = *headReferencia;

	while (head2 != NULL)
	{
		if (head2->adat2 >= limit)
		{
			node_torlese(headReferencia, p);
		}
	}


}

///////////////4ES FELADAT FUNKCIOI

void uj_elem_beilesztese(int ujElem, int pozicio)
{

	//uj elem helyenek lefoglalasa
	Node4* newNode = new Node4();
	newNode->data4 = ujElem;
	newNode->next4 = NULL;
	newNode->prev4 = NULL;

	//ellenorzes,hogy a pozicio nagyobb legyen mint 1
	if (pozicio < 1) {
		cout << "\na pozicio  >1 vagy =1 kell legyen ";
	}
	else if (pozicio == 1)
	{

		// ha a pozicio 1, akkor csinal egy uj node-ot ->> newNode
		newNode->next4 = head4;
		newNode->prev4 = head4;////////////////HIBA
		head4 = newNode;
	}
	else {

		//maskepp csinaljon egy ideigleneset
		Node4* temp = head4;
		for (int i = 1; i < pozicio - 1; i++)
		{
			if (temp != NULL)
			{
				temp = temp->next4;
			}
		}

		// lista rendezese ha az elozo nem nulla
		if (temp != NULL)
		{
			newNode->next4 = temp->next4;
			newNode->prev4 = temp;
			temp->next4 = newNode;
			if (newNode->next4 != NULL)
				newNode->next4->prev4 = newNode;
		}
		else
		{

			//ha ez elozo node = nulla akkor 
			cout << "\naz elozo node nulla";
		}
	}


	///
	elem_szamlalo++;
}

void sorting()
{
	Node4* p = head4;//elso elem pointer
	Node4* q = head4;//kovetkezo elem pointer
	if (head4 == NULL)
	{
		cout << "######uress a lista######\n";
	}
	else
	{
		for (int i = 0; i < elem_szamlalo; i++)
		{
			for (int j = 0; j < elem_szamlalo - 1; j++)
			{//nem szamoljuk a NULL ra mutatast
				if (p->data4 < q->data4) {//ha p nagyobb e mint q
					int temp = p->data4;//akkor swapoljanak
					p->data4 = q->data4;
					q->data4 = temp;

				}
				q = q->next4;//q halad tovabb
			}
			q = head4;
			p = head4->next4;
			for (int k = 0; k < i; k++)
			{
				p = p->next4;//elemek inkrementalasa
			}
		}
	}
}

void lista_kiiratasa(struct Node4* node4)
{


	while (node4 != NULL)
	{
		cout << node4->data4 << "--->";
		node4 = node4->next4;
	}
	if (node4 == NULL)
		cout << "NULL\n\n";

}

void beszuras_rendezve(int ujELEM) {

	//uj elem helyenek lefoglalasa
	Node4* uj = new Node4();
	uj->data4 = ujELEM;
	uj->next4 = NULL;
	uj->prev4 = NULL;

	//ha elso elemnel kisebb ?
	if (uj->data4 < head4->data4) {
		uj_elem_beilesztese(ujELEM, 0);
	}
	//ha nagyobb mint az elso
	else {
		Node4* temp4 = head4;
		// ha nagyobb mint az utolso
		while (temp4->next4 == NULL) {
			if (uj->data4 > temp4->data4) {
				//--beillesztes utolsonak

				uj->next4 = temp4;
				uj->prev4 = temp4->prev4;
				temp4->prev4->next4 = uj;
				temp4->prev4 = uj;
			}
			//ha kisebb mint az utolso
			temp4 = temp4->next4;
		}

	}
}

int main()
{

	int opcioFO;
	int opcio1;
	int opcio2;
	int opcio3;
	int opcio4;

	do
	{
		cout << "******************FO MENU******************\n\n"
			<< "\t1. ELSO FELADAT\n"
			<< "\t2. MASODIK FELADAT\n"
			<< "\t3. HARMADIK FELADAT\n"
			<< "\t4. NEGYEDIK FELADAT\n"
			<< "\t10. EXIT\n"
			<< endl;
		cin >> opcioFO;

		switch (opcioFO)
		{

		case 1:
			do
			{
				system("Color E4");
				cout << "\t\t111 ELSO FELADAT 111\n"
					<< "\t1. ar megadasa\n"
					<< "\t2. ossz ertek \n"
					<< "\t3. ossz ertek by szamlalo\n"
					<< "\t10. EXIT\n"
					<< endl;
				cin >> opcio1;

				switch (opcio1)
				{

				case 1:
					int ujelem;
					cout << "uj elem megadasa";
					cin >> ujelem;
					pushAR(ujelem);
					break;
				case 2:
					osszertek_bylist();
					break;
				case 3:
					osszertek_byszamlalo();
					break;

				}

			} while (opcio1 != 10);
			break;
		case 2:
			do
			{
				system("Color F4");
				cout << "\n\t\t222 MASODIK FELADAT 222\n"
					<< "\t1. egyszeresen lancolt lista eloremegadott adatokkal valo feltoltese\n"
					<< "\t2. egyszeresen lancolt lista adatainak bevitele billentyuzetrol\n"
					<< "\t3. ketszeresen lancolt lista ellenorzese ha uress\n"
					<< "\t4. egyszeresen lancolt lista bemasolasa a ketszeresenlancolt listaba \n"
					<< "\t5. ketszeresen lancolt listabol megadott elemnel nagyobbak torlese \n"
					<< "\t10. EXIT\n"
					<< endl;
				cin >> opcio2;

				switch (opcio2)
				{

				case 1:
					eloremegadott_adatokkal_valo_feltoltese(1);
					eloremegadott_adatokkal_valo_feltoltese(21);
					eloremegadott_adatokkal_valo_feltoltese(15);
					eloremegadott_adatokkal_valo_feltoltese(11);
					eloremegadott_adatokkal_valo_feltoltese(31);
					eloremegadott_adatokkal_valo_feltoltese(25);
					cout << "\n \t\t  A LISTA FEL LETT TOLTVE 1->21->15->11->31->25\n\n";
					break;
				case 2:

					int listaFeltoltese;
					int n;
					cout << "\n\thany elemet szeretne a listahoz adni ? :\t";
					cin >> n;
					for (int i = 0; i < n; i++) {
						cout << "\n\t\tadja meg az  " << i << "-edik elemet:";
						cin >> listaFeltoltese;
						lista_feltoltese(listaFeltoltese);
					}
					break;
				case 3:
					duplalista_ellenorzes();
					break;
				case 4:
					BeIllestes(head1);
					break;
				case 5:
					int limit;
					cout << "\n\t\t\tAdja meg a limitet amelyel egyenlo vagy annal nagyobb elemeket eltavolitana a listabol";
					cin >> limit;
					limittorles(&head2, limit);
					break;

				}

			} while (opcio2 != 10);
			break;
		case 3:
			nullazasVektor();
			do
			{
				system("Color C7");
				cout << "\n\t\t333 HARMADIK FELADAT 333     side note : ez a kod az elso feladat listajat hasznalja\n"
					<< "\t1. lista feltoltese elore megadott adatokkal (2 --> 4 --> -7 -->10--> -8 --> 0 -->NULL)\n"
					<< "\t2. lista feltoltese manualisan\n"
					<< "\t3. lista kiiratasa\n"
					<< "\t4. 3 elemu vectorba implementalas -/+/0 ertekeket\n"
					<< "\t5. ^^ezen kiiratasa^^\n"
					<< "\t10. EXIT\n"
					<< endl;
				cin >> opcio3;

				switch (opcio3)
				{

				case 1:
					//lista beolvasas
					lista_feltoltes(&head, 2);
					lista_feltoltes(&head, 4);
					lista_feltoltes(&head, -7);
					lista_feltoltes(&head, 0);
					lista_feltoltes(&head, -8);
					lista_feltoltes(&head, 0);
					//lista ellenorzese
					athaladas3();
					//3 elemu matrix feltoltese
					break;
				case 2:

					int adatka3;
					cout << "\t adja meg az elso elemet :\n";
					cin >> adatka3;
					pushKod(adatka3);
					break;
				case 3:
					athaladas3();
					break;
				case 4:
					ellenorzes_3asfeladat();
					break;
				case 5:
					for (int i = 0; i < 3; i++) {
						cout << vektor[i] << "--";
					}
					cout << "\n";
					break;
				}

			} 			while (opcio3 != 10);
			break;
		case 4:
			do
			{
				system("Color E4");
				cout << "\t\t444 NEGYEDIK FELADAT 444\n"
					<< "\t1. lista feltoltese sajat elemekkel\n"
					<< "\t2. lista feltoltese elore megadott elemekkel 2-->1-->6-->4-->11-->4-->NULL \n"
					<< "\t3. rendezes\n"
					<< "\t4. beszuras rendezetten\n"
					<< "\t5. lista kiirasa\n"
					<< "\t10. EXIT\n"
					<< endl;
				cin >> opcio4;

				switch (opcio4)
				{

				case 1:
					int poziciotura, beillesztendoertekecske;
					cout << "\n\t\t\tadja meg az elem poziciojat :";
					cin >> poziciotura;
					cout << "\n\t\t\tadja meg az elemet amit beszeretne illeszteni :";
					cin >> beillesztendoertekecske;
					uj_elem_beilesztese(beillesztendoertekecske, poziciotura);
					break;
				case 2:
					uj_elem_beilesztese(2, 1);
					uj_elem_beilesztese(1, 2);
					uj_elem_beilesztese(6, 3);
					uj_elem_beilesztese(4, 4);
					uj_elem_beilesztese(11, 5);
					uj_elem_beilesztese(4, 6);
					break;
				case 3:
					sorting();
					break;
				case 4:
					int UJELEMWAO;
					cout << "\n adja meg a beilleszteno elemet:\n";
					cin >> UJELEMWAO;
					beszuras_rendezve(UJELEMWAO);

					break;
				case 5:
					lista_kiiratasa(head4);
					break;

				}
			} 			while (opcio4 != 10);
			break;
		}



	} 	while (opcioFO != 10);
	return 0;
}
