#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

/* Tre��
Input: "wyniki_liczby.txt"
1000 r�nych liczb od 2 do 9 cyfr
*/

/* Wyniki

*/

const int SIZE = 1000;
int tab[SIZE];

/*
Czynnikiem pierwszym danej liczby naturalnej z�o�onej jest dowolna liczba 
pierwsza, kt�ra dzieli t� liczb� ca�kowicie. Podaj, ile jest w pliku liczby.txt 
liczb, w kt�rych rozk�adzie na czynniki pierwsze wyst�puj� dok�adnie trzy r�ne 
czynniki (mog� si� one powtarza�), z kt�rych ka�dy jest nieparzysty.
*/
void z1() {
  int n;
  for (int i = 0; i < SIZE; i++) {
    n = tab[i];
    while (n != 1) {
      n = tab[i]
      
    }
}

int main() {
  ifstream in;
  in.open("wyniki_liczby.txt");
  for (int i = 0; i < SIZE; i ++) {
    in >> tab[i];
  }
  in.close();
  
  z1();
}
