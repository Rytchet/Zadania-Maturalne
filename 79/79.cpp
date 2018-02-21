#include <iostream>
#include <fstream>
using namespace std;

/* Tre��
Okrag na plaszczyznie reprezentujemy za pomoca trzech liczb x, y, r ,gdzie (x, y (oznaczaja
wsp�lrzedne srodka okregu, a r � jego promien.
W pliku okregi.txt danych jest 2000 okreg�w; kazdy zapisany jest w osobnym wierszu,
zawierajacym trzy liczby rzeczywiste x, y, r (-10^9 <= x, y <= 10^9, 0 < r > 10^9). 
*/

/* Wyniki
Zadanie 1:
I: 1339
II: 274
III: 166
IV: 218
0: 3

*/

const int SIZE = 2000;
double tab[SIZE][3];

/* Zadanie 1
Podaj liczbe okreg�w, kt�re calkowicie zawieraja sie w I, II, III i IV cwiartce ukladu wsp�l-
rzednych. Podaj r�wniez liczbe okreg�w, kt�re nie zawieraja sie w calosci w zadnej cwiartce,
tzn. maja co najmniej jeden punkt wsp�lny z jedna z osi Ox lub Oy. Jako odpowiedz wypisz
piec liczb: liczba okreg�w I cwiartki, liczba okreg�w II cwiartki, liczba okreg�w III cwiartki,
liczba okreg�w IV cwiartki oraz liczba okreg�w, kt�re nie zawieraja sie w calosci w zadnej
cwiartce. 

  II | I
 --------
 III | IV
 
*/

double abs(double n) {
  if (n >= 0) return n;
  return -n;
}

bool jestCwiartka(double x, double y, double r) {
  return (abs(x) > r && abs(y) > r);
}

void z1() {
  cout << "Zadanie 1:" << endl;
  int counter1 = 0, counter2 = 0, counter3 = 0, counter4 = 0, counter0 = 0;
  for (int i = 0; i < SIZE; i++) {
    float x = tab[i][0], y = tab[i][1], r = tab[i][2];
    if (jestCwiartka(x, y, r)) {
      if (x > 0 && y > 0) counter1++;
      if (x < 0 && y > 0) counter2++;
      if (x < 0 && y < 0) counter3++;
      if (x > 0 && y < 0) counter4++;
    }
    else counter0++;
  }
  cout << "I: " << counter1 << endl;
  cout << "II: " << counter2 << endl;
  cout << "III: " << counter3 << endl;
  cout << "IV: " << counter4 << endl;
  cout << "0: " << counter0 << endl;
  cout << endl;
}

/* Zadanie 2
Powiemy, �e dwa okr�gi tworz� lustrzan� par�, je�li jeden z nich powstaje przez odbicie drugiego
wzgl�dem jednej z osi Ox lub Oy. Podaj liczb� lustrzanych par spo�r�d wszystkich
okr�g�w zapisanych w pliku okregi.txt. 
*/

bool saLustrzane(double x1, double y1, double r1, double x2, double y2, double r2) {
	if (r1 != r2) return false;
	if (x1 == x2 && y1 == y2) return false;
	if (abs(x1) == abs(x2) && y1 == y2) return true;
	if (abs(y1) == abs(y2) && x1 == x2) return true;
	return false;
}

void z2() {
	cout << "Zadanie 2:" << endl;
	int counter = 0;
	for (int i = 0; i < SIZE - 1; i++) {
		for (int j = i + 1; j < SIZE; j++) {
			if (saLustrzane(tab[i][0], tab[i][1], tab[i][2], tab[j][0], tab[j][1], tab[j][2])) {
				counter++;
			}
		}
	}
	cout << counter << endl << endl;
}

/* Zadanie 3
Powiemy, �e dwa okr�gi tworz� prostopad�� par�, je�li jeden z nich powstaje przez obr�t
drugiego o 90 stopni wzgl�dem �rodka uk�adu wsp�rz�dnych.
Przyk�ad: okr�gi o �rodkach w punktach (3,-5), (5,3) (i o tych samych promieniach) tworz�
par� prostopad��
Podaj liczb� prostopad�ych par okr�g�w spo�r�d wszystkich okr�g�w zapisanych w pliku
okregi.txt. 
*/

bool saProstopadle(double x1, double y1, double r1, double x2, double y2, double r2) {
	if (r1 != r2) return false;
	if (x1 == x2 && y1 == y2) return false;
	if (abs(x1) == abs(y2) && x2 == y1) return true;
	if (abs(x2) == abs(y1) && x1 == y2) return true;
	return false;
}

void z3() {
	cout << "Zadanie 3:" << endl;
	int counter = 0;
	for (int i = 0; i < SIZE - 1; i++) {
		for (int j = i + 1; j < SIZE; j++) {
			if (saProstopadle(tab[i][0], tab[i][1], tab[i][2], tab[j][0], tab[j][1], tab[j][2])) {
				counter++;
			}
		}
	}
	cout << counter << endl << endl;
}

int main() {
  ifstream in("okregi.txt");
  double a, b, c;
  for (int i = 0; i < SIZE; i++) {
    in >> a >> b >> c;
    tab[i][0] = a;
    tab[i][1] = b;
    tab[i][2] = c;
  }
  in.close();
  
  z1();
  z2();
  z3();
}
