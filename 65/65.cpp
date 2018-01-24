#include <iostream>
#include <fstream>
using namespace std;

/* Tre��
W pliku dane_ulamki.txt znajduje si� 1000 par liczb naturalnych dodatnich, mniejszych
ni� 12 000. Ka�da para liczb jest zapisana w osobnym wierszu, liczby w wierszu rozdzielone
s� pojedynczym znakiem odst�pu. Par� liczb zapisanych w tym samym wierszu interpretujemy
jako u�amek, kt�rego licznikiem jest pierwsza liczba, a mianownikiem � druga liczba. 
*/

/* Wyniki
65.1: 1, 225
*/

const int SIZE = 1000;
float tab[SIZE][2];

/* Zadanie 1
Podaj u�amek o minimalnej warto�ci. Je�li w pliku wyst�puje wi�cej ni� jeden taki u�amek, to
podaj ten spo�r�d nich, kt�ry ma najmniejszy mianownik. Twoja odpowied� powinna zawiera�
par� liczb oznaczaj�c� licznik i mianownik u�amka. 
*/

void z1() {
  cout << "Zadanie 1:" << endl;
  float minLicznik = 999999999, minMianownik = 999999999, minUlamek = 999999999;
  float ulamek;
  for (int i = 0; i < SIZE; i++) {
    ulamek = tab[i][0] / tab[i][1];
    if (ulamek <= minUlamek) {
      if (ulamek == minUlamek && tab[i][1] > minMianownik) continue;
      minUlamek = ulamek;
      minLicznik = tab[i][0];
      minMianownik = tab[i][1];
    }
  }
  cout << "Licznik: " << minLicznik << " Mianownik: " << minMianownik << endl;
}

/* Zadanie 2
Podaj liczb� zapisanych w pliku u�amk�w, kt�re zosta�y podane w postaci nieskracalnej. 
*/

int main() {
  ifstream in("dane_ulamki.txt");
  for (int i = 0; i < SIZE; i++) {
    in >> tab[i][0] >> tab[i][1];
  }
  in.close();
  
  z1();
  z2();
}
