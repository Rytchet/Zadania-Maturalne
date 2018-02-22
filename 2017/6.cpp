#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

/* Tre�� 
W pliku dane.txt znajduje si� 200 wierszy. Ka�dy wiersz zawiera 320 liczb naturalnych
z przedzia�u od 0 do 255, oddzielonych znakami pojedynczego odst�pu (spacjami).
Przedstawiaj� one jasno�ci kolejnych pikseli czarno-bia�ego obrazu o wymiarach 320 na 200
pikseli (od 0 � czarny do 255 � bia�y).
Napisz program(y), kt�ry(e) da(dz�) odpowiedzi do poni�szych zada�. Odpowiedzi zapisz
w pliku wyniki6.txt, a ka�d� odpowied� poprzed� numerem oznaczaj�cym odpowiednie
zadanie. 
*/

int tab[200][320];

/* Zadanie 1
Podaj jasno�� najja�niejszego i jasno�� najciemniejszego piksela.
Dla danych z pliku przyklad.txt wynikiem jest 255 (najja�niejszy) i 0 (najciemniejszy). 
*/

void z1() {
	int min = 256, max = 0;
	for (int i = 0; i < 200; i++) {
		for (int j = 0; j < 320; j++) {
			if (tab[i][j] < min) min = tab[i][j];
			if (tab[i][j] > max) max = tab[i][j];
		}
	}
	cout << max << " " << min << endl;
}

/* Zadanie 2
Podaj, ile wynosi najmniejsza liczba wierszy, kt�re nale�y usun��, �eby obraz mia� pionow� o�
symetrii. Obraz ma pionow� o� symetrii, je�li w ka�dym wierszu i-ty piksel od lewej strony
przyjmuje t� sam� warto��, co i-ty piksel od prawej strony, dla dowolnego 1 ? i ? 320.
Dla danych z pliku przyklad.txt wynikiem jest 3. 
*/

void z2() {
	int counter = 0;
	for (int i = 0; i < 200; i++) {
		for (int j = 0; j < 320 / 2; j++) {
			if (tab[i][j] != tab[i][320 - j - 1]) {
				counter++;
				break;
			}
		}
	}
	cout << counter << endl;
}

/* Zadanie 3
S�siednie piksele to takie, kt�re le�� obok siebie w tym samym wierszu lub w tej samej
kolumnie. Dwa s�siednie piksele nazywamy kontrastuj�cymi, je�li ich warto�ci r�ni� si�
o wi�cej ni� 128. Podaj liczb� wszystkich takich pikseli, dla kt�rych istnieje przynajmniej jeden
kontrastuj�cy z nim s�siedni piksel.
Dla danych z pliku przyklad.txt wynikiem jest 5. 
*/

void z3() {
	int counter = 0;
	bool flag;
	for (int i = 0; i < 200; i++) {
		for (int j = 0; j < 320; j++) {
			flag = false;
			if (j > 0 && abs(tab[i][j] - tab[i][j-1]) > 128) flag = true;
			if (j < 319 && abs(tab[i][j] - tab[i][j+1]) > 128) flag = true;
			if (i > 0 && abs(tab[i][j] - tab[i-1][j]) > 128) flag = true;
			if (i < 199 && abs(tab[i][j] - tab[i+1][j]) > 128) flag = true;
			if (flag) counter++;
		}
	}
	cout << counter << endl;
}

/* Zadanie 4
Podaj d�ugo�� najd�u�szej linii pionowej (czyli ci�gu kolejnych pikseli w tej samej kolumnie
obrazka), z�o�onej z pikseli tej samej jasno�ci.
Dla danych z pliku przyklad.txt wynikiem jest 198. 
*/

void z4() {
	int max = 0, prev, counter;
	for (int j = 0; j < 320; j++) {
		prev = tab[0][j];
		counter = 1;
		for (int i = 1; i < 200; i++) {
			if (tab[i][j] == prev) counter++;
			else {
				if (counter > max) max = counter;
				counter = 1;
			}
			prev = tab[i][j];
		}
		if (counter > max) max = counter;
	}
	cout << max << endl;
}

int main() {
	ifstream in("dane.txt");
	ifstream inP("przyklad.txt");
	for (int i = 0; i < 200; i++) {
		for (int j = 0; j < 320; j++) {
			in >> tab[i][j];
		}
	}
	
	z1();
	z2();
	z3();
	z4();
}
