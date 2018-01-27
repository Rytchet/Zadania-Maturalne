#include <iostream>
#include <fstream>
using namespace std;

/* Tre��
W pliku tekst.txt dany jest tekst z�o�ony ze s��w pisanych wielkimi literami alfabetu
angielskiego. S��w jest 1876, oddzielone s� one pojedynczymi odst�pami, a inne znaki poza
literami i spacjami w tek�cie nie wyst�puj�. Napisz program(-y), kt�ry poda odpowiedzi do
poni�szych zada�. Odpowiedzi zapisz w pliku wyniki.txt. 
*/

/* Wyniki

*/

const int SIZE = 1876;
string tab[SIZE];

/* Zadanie 1
Oblicz, ile jest w tek�cie s��w, w kt�rych wyst�puj� dwie kolejne takie same litery. 
*/

bool hasTwoLetters (string s) {
  for (int i = 1; i < s.length(); i++) {
    if (s[i] == s[i - 1]) return true;
  }
  return false;
}

void z1() {
  cout << "Zadanie 1:" << endl;
  int counter = 0;
  for (int i = 0; i < SIZE; i++) {
    if (hasTwoLetters(tab[i])) counter++;
  }
  cout << counter << endl << endl;
}

int main() {
  ifstream in("tekst.txt");
  for (int i = 0; i < SIZE; i++) in >> tab[i];
  in.close();
  
  z1();
}
