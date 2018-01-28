#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

/* Tre��
W pliku hasla.txt danych jest 200 hase� u�ytkownik�w pewnego systemu. Ka�dy u�ytkownik
posiada jedno has�o (ka�de zapisane jest w osobnym wierszu), kt�re zawiera od 1 do
20 znak�w alfanumerycznych, tzn. cyfr od 0 do 9 lub liter alfabetu �aci�skiego (ma�ych lub
du�ych). Polityka bezpiecze�stwa systemu wymaga, aby has�a by�y odpowiednio skomplikowane
i nie powtarza�y si�.
Poni�ej podano pierwsze pi�� hase� zapisanych w pliku hasla.txt:
ZXUhkPLcjKo
ikfLDegQXj
8Y7JGYXXR5
603624722555
50q4252ax5
*/

/* Wyniki
Zadanie 1:
16
Zadanie 2:
8Y7JGYXXR5
Ehz018657
PAsCMQaervw
cefdi
cek
ikfLDegQXj
jir
yvm249t83o04
*/

const int SIZE = 200;
string tab[SIZE];

/* Zadanie 1
Podaj liczb� hase� z�o�onych jedynie ze znak�w numerycznych, tzn. cyfr od 0 do 9.
*/

bool isNumeric(char c) {
  return (c >= '0' && c <= '9');
}

bool isOnlyNumeric(string s) {
  for (int i = 0; i < s.length(); i++) {
    if (!isNumeric(s[i])) return false;
  }
  return true;
}

void z1() {
  cout << "Zadanie 1:" << endl;
  int counter = 0;
  for (int i = 0; i < SIZE; i++) {
    if (isOnlyNumeric(tab[i])) counter++;
  }
  cout << counter << endl << endl;
}

/* Zadanie 2
Wypisz has�a, kt�re zosta�y u�yte przez co najmniej dw�ch r�nych u�ytkownik�w, tzn. wyst�puj�ce
w dw�ch r�nych wierszach. Has�a wypisz (bez powt�rze�) w kolejno�ci leksykograficznej.
*/

void z2() {
  cout << "Zadanie 2:" << endl;
  
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      if (i == j) continue;
      if (tab[i] == tab[j]) {
        cout << tab[i] << endl;
        i++;
        break;
      }
    }
  }
}

int main() {
  ifstream in("hasla.txt");
  for (int i = 0; i < SIZE; i++) in >> tab[i];
  in.close();
  sort(tab, tab + SIZE);

  z1();
  z2();
}
