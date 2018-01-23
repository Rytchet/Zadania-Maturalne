#include <iostream>
#include <fstream>
using namespace std;

/* Tres�
W pliku ciagi.txt w oddzielnych wierszach znajduje si� 1000 r�nych ci�g�w zerojedynkowych,
ka�dy o d�ugo�ci od 2 do 18. Napisz program(-y), kt�ry pozwoli rozwi�za�
poni�sze zadania. Nast�pnie je rozwi��, a odpowiedzi do poszczeg�lnych zada� zapisz w pliku
tekstowym wyniki_ciagi.txt. Wyniki do ka�dego zadania poprzed� numerem oznaczaj�cym
to zadanie. 
*/

/* Wyniki

*/

const int SIZE = 1000;
string tab[SIZE];

/*
Ci�giem dwucyklicznym b�dziemy nazywa� taki ci�g zerojedynkowy w o d�ugo�ci parzystej,
kt�ry sk�ada si� z dw�ch fragment�w w1 oraz w2, w = w1 + w2, takich �e w1 = w2. Podaj
wszystkie ci�gi dwucykliczne zapisane w pliku ciagi.txt.
Przyk�ad
Dla zestawu ci�g�w:
10010101010011001010101001 <-
11001101001
1001000
11001100 <-
101010011100
110011110011 <-
3 zaznaczone ci�gi s� dwucykliczne
*/

void z1() {
  cout << "Zadanie 1:" << endl;
  int length;
  string w1, w2;
  for (int i = 0; i < SIZE; i++) {
    length = tab[i].length();
    if (length % 2 != 0) continue;
    w1 = tab[i].substr(0, length / 2);
    w2 = tab[i].substr(length / 2, length / 2);
    if (w1 == w2) {
      cout << tab[i] << endl;
    }
  }
}

int main() {
  ifstream in("ciagi.txt");
  for (int i = 0; i < SIZE; i++) in >> tab[i];
  in.close();
  
  z1();
}
