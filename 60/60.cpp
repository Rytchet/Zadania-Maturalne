#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

/* Tre��
Input: "liczby.txt"
200 r�nych liczb ca�kowitych z przedzia�u [2, 1 000 000]
*/

/* Wyniki
Zadanie 1:
Liczb mniejszych od 1000: 12
Ostatnie dwie: 540, 633
Zadanie 2:
Liczba: 989532
1 2 3 4 6 9 12 18 36 27487 54974 82461 109948 164922 247383 329844 494766 989532
Liczba: 131072
1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 16384 32768 65536 131072
Liczba: 702027
1 3 9 27 81 107 243 321 729 963 2187 2889 6561 8667 26001 78003 234009 702027
Liczba: 461817
1 3 9 23 69 97 207 291 529 873 1587 2231 4761 6693 20079 51313 153939 461817
Liczba: 17298
1 2 3 6 9 18 31 62 93 186 279 558 961 1922 2883 5766 8649 17298
Zadanie 3:
Max: 988027
*/

const int SIZE = 200;
int tab[SIZE];

/* Zadanie 1
Policz, ile jest w pliku wej�ciowym liczb mniejszych ni� 1000, oraz podaj dwie 
takie liczby, kt�re pojawiaj� si� w pliku jako ostatnie (mo�esz za�o�y�, �e 
b�d� co najmniej dwie). 
*/

void z1() {
  cout << "Zadanie 1: " << endl;
  int counter = 0;
  int lastNumber, lastNumber2;
  for (int i = 0; i < SIZE; i++) {
    if (tab[i] < 1000) {
      counter++;
      lastNumber = lastNumber2;
      lastNumber2 = tab[i];
    }
  }
  cout << "Liczb mniejszych od 1000: " << counter << endl;
  cout << "Ostatnie dwie: " << lastNumber << ", " << lastNumber2 << endl;
}

/* Zadanie 2
W�r�d liczb wyst�puj�cych w pliku wej�ciowym znajd� te, kt�re maj� dok�adnie 18 
dzielnik�w naturalnych (wliczaj�c w nie 1 i sam� liczb�). Dla ka�dej znalezionej 
liczby wypisz, opr�cz jej warto�ci, list� wszystkich jej dzielnik�w, posortowan� 
rosn�co
*/

void z2() {
  cout << "Zadanie 2:" << endl;
  int counter;
  int dividers[18];
  for (int i = 0; i < SIZE; i++) {
    counter = 0;
    for (int j = 1; j <= tab[i]; j++) {
      if (tab[i] % j == 0) {
        dividers[counter] = j;
        counter++;
      }
      if (counter > 18) break;
    }
    if (counter == 18) {
      sort(dividers, dividers + 18);
      cout << "Liczba: " << tab[i] << endl;
      for (int j = 0; j < 18; j++) cout << dividers[j] << " ";
      cout << endl;
    }
  }
}


/* Zadanie 3
Znajd� najwi�ksz� liczb� w pliku, kt�ra jest wzgl�dnie pierwsza ze wszystkimi 
pozosta�ymi, czyli tak�, kt�ra z �adn� z pozosta�ych liczb nie ma wsp�lnego 
dzielnika innego ni� 1. 
*/

// Algorytm Euklidesa / Euclidean Algorithm
int nwd(int x, int y) {
  if (x < y) return nwd(y, x);
  if (y == 0) return x;
  return nwd(y, x % y);
}

void z3() {
  cout << "Zadanie 3:" << endl;
  bool flag;
  int max = 0;
  for (int i = 0; i < SIZE; i++) {
    if (tab[i] < max) continue;
    flag = true;
    for (int j = 0; j < SIZE; j++) {
      if (i != j && nwd(tab[i], tab[j]) > 1) {
        flag = false;
        break;
      }
    }
    if (flag && tab[i] > max) max = tab[i];
  }
  cout << "Max: " << max << endl;
}

int main() {
  ifstream in;
  in.open("liczby.txt");
  for (int i = 0; i < SIZE; i++) {
    in >> tab[i];
  }
  in.close();
  
  z1();
  z2();
  z3();
}
