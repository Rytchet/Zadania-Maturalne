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
62.3:
a) 160
b) 357
62.4: (prawdopodobnie b��d w odpowiedziach, wyniki s� zamienione miejscami)
411
625
*/

const int SIZE = 1000;

/*
Wyszukaj w pliku liczby1.txt dwie liczby, najmniejsz� i najwi�ksz�. Podaj warto�ci
tych liczb w zapisie �semkowym.
*/

void z1() {
  cout << "Zadanie 1:" << endl;
  ifstream in("liczby1.txt");
  int tab[SIZE];
  for (int i = 0; i < SIZE; i++) in >> tab[i];
  in.close();
  int min = 9999999;
  int max = 0;
  for (int i = 0; i < SIZE; i++) {
    if (tab[i] < min) min = tab[i];
    if (tab[i] > max) max = tab[i];
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
  int tab[SIZE];
  ifstream in("liczby2.txt");
  for (int i = 0; i < 1000; i++) in >> tab[i];
  in.close();
  int counter = 0, maxCounter = 0, firstNumber = 0;
  int maxFirst;
  for (int i = 1; i < SIZE; i++) {
    if (tab[i] >= tab[i - 1]) {
      counter++;
      if (firstNumber == 0) {
        firstNumber = tab[i - 1];
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

/*
Por�wnaj warto�ci liczb zapisanych w wierszach o tych samych numerach w plikach liczby1.txt
i liczby2.txt. Podaj liczb� wierszy, w kt�rych:
a) liczby maj� w obu plikach tak� sam� warto��;
b) warto�� liczby z pliku liczby1.txt jest wi�ksza od warto�ci liczby z pliku liczby2.txt.

Dla przyk�adowych danych:
liczby1.txt liczby2.txt
11456       1302
22666       9654
546         499
odp. a) 1 wiersz, bo tylko w drugim wierszu liczby maj� tak� sam� warto��: 22666(8) = 9654(10)
odp. b) 1 wiersz, bo tylko w pierwszym wierszu warto�� liczby w pierwszym pliku jest wi�ksza
ni� odpowiadaj�ca jej warto�� w drugim pliku: 11456(8)>1302(10). 
*/

void z3() {
  cout << "Zadanie 3:" << endl;
  int tab1[SIZE], tab2[SIZE];
  ifstream in1("liczby1.txt");
  ifstream in2("liczby2.txt");
  for (int i = 0; i < SIZE; i++) in1 >> oct >> tab1[i];
  for (int i = 0; i < SIZE; i++) in2 >> tab2[i];
  in1.close();
  in2.close();
  int aCounter = 0, bCounter = 0;
  for (int i = 0; i < SIZE; i++) {
    if (tab1[i] == tab2[i]) aCounter++;
    if (tab1[i] > tab2[i]) bCounter++;
  }
  cout << "a) " <<  aCounter << endl << "b) " << bCounter << endl;
}

/*
Podaj, ile razy w zapisie dziesi�tnym wszystkich liczb z pliku liczby2.txt wyst�puje
cyfra 6 oraz ile razy wyst�pi�aby ta cyfra, gdyby te same liczby by�y zapisane w systemie
�semkowym.
*/

void z4() {
  cout << "Zadanie 4:" << endl;
  ifstream in("liczby2.txt");
  int tab[SIZE];
  for (int i = 0; i < SIZE; i++) in >> tab[i];
  int firstCounter = 0, secondCounter = 0;
  int number;
  for (int i = 0; i < SIZE; i++) {
    number = tab[i];
    while (number) {
      if (number % 10 == 6) firstCounter++;
      number = number / 10;
    }
    number = tab[i];
    while (number) {
      if (number % 8 == 6) secondCounter++;
      number = number / 8;
    }
  }
  cout << firstCounter << " " << secondCounter << endl;
}

int main() {
  z1();
  z2();
  z3();
  z4();
}
