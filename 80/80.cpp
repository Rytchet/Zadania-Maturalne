#include <iostream>
#include <fstream>
using namespace std;

/* Tre��
W pliku dane_trojkaty.txt znajduje si� 500 liczb ca�kowitych dodatnich. Ka�da liczba
jest zapisana w osobnym wierszu, �adna liczba nie wyst�puje w pliku wi�cej ni� jeden raz.
Liczby podane w pliku dane_trojkaty.txt to d�ugo�ci odcink�w, z kt�rych b�dziemy
pr�bowa� budowa� tr�jk�ty. 
*/

/* Wyniki
Zadanie 1:
4, 3, 5
13, 85, 84
33, 65, 56
28, 45, 53

Zadanie 2:
29694

Zadanie 3:
2343790
*/

const int SIZE = 500;
int tab[SIZE];

/* Zadanie 1
Wypisz wszystkie tr�jki kolejnych liczb z pliku dane_trojkaty.txt, kt�re s� d�ugo�ciami
bok�w tr�jk�ta prostok�tnego. 
*/

void wyswietl(int a, int b, int c) {
	cout << a << ", " << b << ", " << c << endl;
}

bool saDlugosciamiTrojkataProstokatnego(int a, int b, int c) {
	return (a * a + b * b == c * c ||
			a * a + c * c == b * b ||
			c * a + c * b == a * a);
}

void z1() {
	cout << "Zadanie 1:" << endl;
	for (int i = 0; i < SIZE - 2; i++) {
		if (saDlugosciamiTrojkataProstokatnego(tab[i], tab[i+1], tab[i+2])) {
			wyswietl(tab[i], tab[i+1], tab[i+2]);
		}
	}
	cout << endl;
}

/* Zadanie 2
Podaj najwi�kszy obw�d tr�jk�ta, kt�rego boki maj� d�ugo�ci r�wne liczbom wyst�puj�cym
w r�nych wierszach pliku dane_trojkaty.txt. 
*/

bool saTrojkatem(int a, int b, int c) {
	return (a + b > c && a + c > b && b + c > a);
}

void z2() {
	cout << "Zadanie 2:" << endl;
	int max = 0;
	for (int i = 0; i < SIZE - 2; i++) {
		for (int j = i + 1; j < SIZE - 1; j++) {
			for (int k = j + 1; k < SIZE; k++) {
				if (saTrojkatem(tab[i], tab[j], tab[k])) {
					int obwod = tab[i] + tab[j] + tab[k];
					if (obwod > max) max = obwod;
				}
			}
		}
	}
	cout << max << endl << endl;
}

/* Zadanie 3
Podaj, ile nieprzystaj�cych tr�jk�t�w mo�na utworzy� z odcink�w o d�ugo�ciach podanych
w pliku dane_trojkaty.txt. 
Uwaga: Dwa tr�jk�ty s� przystaj�ce wtedy i tylko wtedy, gdy trzy boki jednego tr�jk�ta s�
odpowiednio r�wne trzem bokom drugiego tr�jk�ta, np. tr�jk�t o bokach (10, 18, 15) jest
przystaj�cy z tr�jk�tem o bokach (18, 15, 10). 
*/

void z3() {
	cout << "Zadanie 3:" << endl;
	int counter = 0;
	for (int i = 0; i < SIZE - 2; i++) {
		for (int j = i + 1; j < SIZE - 1; j++) {
			for (int k = j + 1; k < SIZE; k++) {
				if (saTrojkatem(tab[i], tab[j], tab[k])) counter++;
			}
		}
	}
	cout << counter << endl << endl;
}

int main() {
	ifstream in("dane_trojkaty.txt");
	for (int i = 0; i < SIZE; i++) {
		in >> tab [i];
	}
	in.close();
	
	z1();
	z2();
	z3();
}
