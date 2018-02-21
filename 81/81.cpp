#include <iostream>
#include <fstream>
using namespace std;

/* Tre�� 
Plik wierzcholki.txt zawiera 100 wierszy. W ka�dym wierszu zapisano 6 liczb ca�kowitych
z przedzia�u <�100; 100>, b�d�cych wsp�rz�dnymi trzech r�nych punkt�w: A, B i C
w kartezja�skim uk�adzie wsp�rz�dnych (odpowiednio xa, ya, xb, yb, xc, yc). Liczby w wierszu
s� oddzielone pojedynczymi znakami tabulacji.
Podobny plik wierzcholkiTR.txt zawiera r�wnie� 100 wierszy. W ka�dym wierszu
zapisano 6 liczb ca�kowitych nale��cych do przedzia�u <�100; 100>, b�d�cych wsp�rz�dnymi
trzech wierzcho�k�w tr�jk�ta ABC (odpowiednio xa, ya, xb, yb, xc, yc). Liczby w wierszu s�
oddzielone pojedynczymi znakami tabulacji. 
*/

/* Wyniki
Zadanie 1:
2

*/

const int SIZE = 100;
int tab[SIZE][6];

/* Zadanie 1
Podaj liczb� wierszy z pliku wierzcholki.txt, w kt�rych wszystkie zapisane punkty
le�� w I �wiartce uk�adu wsp�rz�dnych i nie nale�� do osi OX i OY.
*/

void z1() {
	cout << "Zadanie 1:" << endl;
	int counter = 0;
	bool flag;
	for (int i = 0; i < SIZE; i++) {
		flag = true;
		for (int j = 0; j < 6; j++) {
			if (tab [i][j] <= 0) flag = false;
		}
		if (flag) counter++;
	}
	cout << counter << endl << endl;
}

int main() {
	ifstream in("wierzcholki.txt");
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < 6; j++) {
			in >> tab[i][j];
		}
	}
	in.close();
	
	z1();
}
