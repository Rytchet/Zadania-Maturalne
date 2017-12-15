#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/* Tre��
Input: "wyniki_liczby.txt"
1000 r�nych liczb od 2 do 9 cyfr
*/

/* Wyniki
59.1: 122
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
  cout << endl << "Zadanie 1: " << endl;
  int n, primeCount, numberCount = 0;
  bool flag;
  for (int i = 0; i < SIZE; i++) {
    primeCount = 0;
    n = tab[i];
    flag = true;
    while (n != 1) {
      if (n % 2 == 0) {
        flag = false;
        break;
      }
      for (int i = 3; i <= n; i = i + 2) {
        if (n % i == 0) {
          primeCount++;
          while (n % i == 0 ) {
            n = n / i;
          }
          break;
        }
      }
      if (primeCount > 3) break;
    }
    if (primeCount != 3) flag = false;
    if (flag) numberCount++;
  }
  cout << "Ilosc liczb: " << numberCount << endl;
}

int main() {
  ifstream in;
  in.open("liczby.txt");
  for (int i = 0; i < SIZE; i ++) {
    in >> tab[i];
  }
  in.close();
  
  z1();
}
