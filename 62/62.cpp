#include <iostream>
#include <fstream>
using namespace std;

/* Tre��
W pliku liczby1.txt znajduje si� 1000 liczb ca�kowitych dodatnich, zapisanych �semkowo,
maksymalnie sze�ciocyfrowych. Ka�da liczba umieszczona jest w osobnym wierszu.
W pliku liczby2.txt znajduje si� 1000 liczb ca�kowitych dodatnich, zapisanych dziesi�tnie,
maksymalnie sze�ciocyfrowych. Ka�da liczba umieszczona jest w osobnym wierszu.
Napisz program(-y), za pomoc� kt�rego(-ych) rozwi��esz poni�sze zadania. Do oceny oddaj
dokument wyniki.txt z rozwi�zaniami poszczeg�lnych zada� oraz pliki �r�d�owe program�w
wykorzystanych do uzyskania rozwi�zania. 
*/

/* Wyniki
61.2:
Min: 1752 (dec 1002)
Max: 2755524 (dec 777044)
*/

const int SIZE = 1000;
int tab10[SIZE], tab8[SIZE];

int octToDec(int x) {
  int answer, counter = 1;
  while (x > 0) {
    answer += (x % 10 * counter);
    counter *= 8;
    x = x / 10;
  }
  return answer;
}

int decToOct(int x) {
  int answer, counter = 1;
  while (x > 0) {
    answer += (x % 8 * counter);
    counter *= 10;
    x = x / 8;
  }
  return answer;
}

/*
Wyszukaj w pliku liczby1.txt dwie liczby, najmniejsz� i najwi�ksz�. Podaj warto�ci
tych liczb w zapisie �semkowym.
*/

void z1() {
  cout << "Zadanie 1:" << endl;
  int min = 9999999;
  int max = 0;
  for (int i = 0; i < SIZE; i++) {
    if (tab10[i] > max) max = tab10[i];
    if (tab10[i] < min) min = tab10[i];
  }
  cout << "Najmniejsza: " << decToOct(min) << endl;
  cout << "Najwieksza: " << decToOct(max) << endl;
}

int main() {
  ifstream in("liczby1.txt");
  for (int i = 0; i < SIZE; i++) in >> tab10[i];
  in.close();
  in.open("liczby2.txt");
  for (int i = 0; i < SIZE; i++) in >> tab8[i];
  in.close();
  
  z1();
}
