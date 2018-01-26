#include <iostream>
#include <fstream>
using namespace std;

/* Tre��
W pliku napisy.txt znajduje si� 200 wierszy, z kt�rych ka�dy zawiera dwa napisy
o d�ugo�ci od 1 do 50 znak�w, oddzielone pojedynczym odst�pem. Napisy sk�adaj� si� wy��cznie
z ma�ych liter alfabetu angielskiego.
Napisz program (lub kilka program�w), kt�ry pozwoli rozwi�za� poni�sze zadania. Odpowiedzi
zapisz w pliku wyniki.txt. 
*/

/* Wyniki
72.1:
70
feycznvjtboxfx gthzgbpglrwjqxqlculgwzdhuevrmvssozrwdjcqcb
72.2:
kxazlp kxazlpe
e
ifvjhuqvh ifvjhuqvhcupzcpw
cupzcpw
aznqxr aznqxryrbgshtceaylwak
yrbgshtceaylwak
*/

const int SIZE = 200;

/* Zadanie 1
Oblicz, w ilu wierszach jeden (kt�rykolwiek) z napis�w jest przynajmniej trzy razy d�u�szy
od drugiego. Jako odpowied� wypisz liczb� takich wierszy oraz par� napis�w z pierwszego
z nich. 
*/

void z1() {
  cout << "Zadanie 1:" << endl;
  ifstream in("napisy.txt");
  string a, b;
  bool flag = true;
  int counter = 0;
  for (int i = 0; i < SIZE; i++) {
    in >> a >> b;
    if (a.length() * 3 <= b.length() || b.length() * 3 <= a.length()) {
      if (flag) {
        cout << a << " " << b << endl;
        flag = false;
      }
      counter++;
    }
  }
  cout << counter << endl << endl;
}

/* Zadanie 2
Znajd� (i wypisz) wszystkie takie wiersze pliku, w kt�rych drugi napis da si� otrzyma�
z pierwszego przez dopisanie na jego ko�cu pewnej dodatniej liczby liter (na przyk�ad kot
i kotara). Dla ka�dego wiersza podaj oba znajduj�ce si� w nim napisy, a osobno wypisz 
litery, kt�re nale�y dopisa�. 
*/

bool compareTask2(string a, string b) {
  if (b.length() <= a.length()) return false;
  for (int i = 0; i < a.length(); i++) {
    if (a[i] != b[i]) return false;
  }
  return true;
}

void z2() {
  cout << "Zadanie 2:" << endl;
  ifstream in("napisy.txt");
  string a, b;
  for (int i = 0; i < SIZE; i++) {
    in >> a >> b;
    if (compareTask2(a, b)) {
      cout << a << " " << b << endl;
      for (int j = a.length(); j < b.length(); j++)
        cout << b[j];
      cout << endl;
    }
  }
  cout << endl;
}

int main() {
  z1();
  z2();
}
