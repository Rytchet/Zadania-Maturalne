#include <iostream>
#include <fstream>
using namespace std;

/* Tre��
Dwa napisy a i b s� swoimi anagramami, je�eli napis a (napis b) mo�na zapisa� za pomoc�
liter wyst�puj�cych w napisie b (napisie a), wykorzystuj�c wszystkie jego litery.
W pliku dane_napisy.txt znajduje si� 1000 par napis�w, z kt�rych ka�dy jest d�ugo�ci
od 2 do 20 znak�w, sk�adaj�cych si� z wielkich liter: A, B, C, D, E, F, G, H, I, J. Ka�da para
napis�w jest zapisana w osobnym wierszu, a napisy oddzielone s� pojedynczym znakiem odst�pu.
*/

/* Wyniki

*/

const int SIZE = 1000;

/* Zadanie 1
Napis nazywamy jednolitym, je�eli wszystkie jego litery s� takie same. Przyk�adem takiego
napisu jest AAAA. Podaj liczb� wierszy zawieraj�cych par� napis�w jednolitych, kt�re s�
wzajemnie swoimi anagramami.
*/

bool isJednolity(string s) {
  char c = s[0];
  for (int i = 0; i < s.length(); i++)
    if (s[i] != c) return false;
  return true;
}



int main() {
  ifstream in("dane_napisy.txt");
  string a, b;
  int jednolityCounter = 0;
  for (int i = 0; i < SIZE; i++) {
    in >> a >> b;
    if (isJednolity(a) && isJednolity(b) && a.length() == b.length())
      jednolityCounter++;
  }
  
  cout << "Zadanie 1:" << endl;
  cout << jednolityCounter << endl << endl;
}
