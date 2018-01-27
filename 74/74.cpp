#include <iostream>
#include <fstream>
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
  cout << "Zadanie 2:" << endl;
  int counter = 0;
  for (int i = 0; i < SIZE; i++) {
    if (isOnlyNumeric(tab[i])) counter++;
  }
  cout << counter << endl << endl;
}

/* Zadanie 2

*/

int main() {
  ifstream in("hasla.txt");
  for (int i = 0; i < SIZE; i++) in >> tab[i];
  in.close();
  
  z1();
}
