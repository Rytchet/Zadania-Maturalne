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
Min: 1002
Max: 777044
62.2:
Pierwszy element: 639
Liczba: 6
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
    if (tab8[i] > max) max = tab8[i];
    if (tab8[i] < min) min = tab8[i];
  }
  cout << "Najmniejsza: " << min << endl;
  cout << "Najwieksza: " << max << endl;
}

/*
Znajd� najd�u�szy niemalej�cy ci�g liczb wyst�puj�cych w kolejnych wierszach pliku liczby2.txt.
Podaj pierwszy element tego ci�gu oraz liczb� jego element�w. Mo�esz za�o�y�,
�e jest jeden taki ci�g. 
*/

void z2() {
  cout << "Zadanie 2:" << endl;
  int counter = 0, maxCounter = 0, firstNumber = 0;
  int maxFirst;
  for (int i = 1; i < SIZE; i++) {
    if (tab8[i] >= tab8[i - 1]) {
      counter++;
      if (firstNumber == 0) {
        firstNumber = tab8[i - 1];
        counter++;
      }
    }
    else {
      if (counter > maxCounter) {
        maxCounter = counter;
        maxFirst = firstNumber;
      }
      firstNumber = 0;
      counter = 0;
    }
  }
  cout << "Pierwszy element: " << maxFirst << endl;
  cout << "Liczba elementow: " << maxCounter << endl;
}

int main() {
  ifstream in("liczby1.txt");
  for (int i = 0; i < SIZE; i++) in >> tab8[i];
  in.close();
  in.open("liczby2.txt");
  for (int i = 0; i < SIZE; i++) in >> tab10[i];
  in.close();
  
  z1();
  z2();
}
