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
Zadanie 1:
feycznvjtboxfx gthzgbpglrwjqxqlculgwzdhuevrmvssozrwdjcqcb
70

Zadanie 2:
kxazlp kxazlpe
e
ifvjhuqvh ifvjhuqvhcupzcpw
cupzcpw
aznqxr aznqxryrbgshtceaylwak
yrbgshtceaylwak

Zadanie 3:
15
zccvywdcmjrdokqzcnayixplhkrf sarkqzcnayixplhkrf
iokvlepqzeyvycfjkliiutmzqawwjxgf dfcfyddwodduznkmivqxnrdliiutmzqawwjxgf
psmwjyystgwchofokzvmkmgusfakroambngky mabgusfakroambngky
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

/* Zadanie 3
Niekt�re z podanych par napis�w maj� identyczne zako�czenia (na przyk�ad komputer i krater).
Znajd� i wypisz najwi�ksz� mo�liw� d�ugo�� takiego zako�czenia, a tak�e wszystkie
pary napis�w w wierszach, kt�re osi�gaj� t� maksymaln� d�ugo��. 
*/

int commonEndingLen(string a, string b) {
  int counter = 0;
  for (int i = 1; i < a.length() && i < b.length(); i++) {
    if (a[a.length() - i] == b[b.length() - i]) counter++;
    else return counter;
  }
  return counter;
}

void z3() {
  cout << "Zadanie 3:" << endl;
  ifstream in("napisy.txt");
  string a, b;
  int maxLen = 0;
  for (int i = 0; i < SIZE; i++) {
    in >> a >> b;
    if (commonEndingLen(a, b) > maxLen) maxLen = commonEndingLen(a, b);
  }
  in.close();
  cout << maxLen << endl;
  in.open("napisy.txt");
  for (int i = 0; i < SIZE; i++) {
    in >> a >> b;
    if (commonEndingLen(a, b) == maxLen) cout << a << " " << b << endl;
  }
  cout << endl;
}

int main() {
  z1();
  z2();
  z3();
}
