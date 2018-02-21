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

int main() {
	ifstream in("dane_trojkaty.txt");
	for (int i = 0; i < SIZE; i++) {
		in >> tab [i];
	}
	in.close();
	
	z1();
}
