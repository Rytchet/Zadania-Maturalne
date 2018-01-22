#include <iostream>
#include <fstream>
using namespace std;

/* Tre��
Input: "ciagi.txt"
Ci�g liczb ca�kowitych nazywamy ci�giem arytmetycznym, je�li r�nica mi�dzy 
ka�dymi dwoma kolejnymi jego wyrazami jest identyczna. Ci�giem arytmetycznym 
jest na przyk�ad ci�g (1, 3, 5, 7, 9). Jest to ci�g o r�nicy 2, poniewa� ka�dy 
wyraz tego ci�gu, poza pierwszym, r�ni si� od poprzedniego wyrazu o 2. 
Ci�g (17, 22, 27, 32, 37) jest ci�giem arytmetycznym o r�nicy 5. W tym zadaniu 
rozpatrujemy tylko takie ci�gi arytmetyczne, kt�re maj� dodatni� r�nic� oraz co
najmniej pi�� wyraz�w.
W pliku ciagi.txt danych jest 100 ci�g�w sk�adaj�cych si� z liczb ca�kowitych 
dodatnich, nieprzekraczaj�cych 1 000 000. Ka�dy ci�g opisany jest w dw�ch 
wierszach: pierwszy zawiera liczb� wyraz�w ci�gu (co najmniej 5 i co 
najwy�ej 1000), za� drugi � kolejne wyrazy ci�gu, oddzielone pojedynczymi 
odst�pami. Dla przyk�adu pierwsze cztery wiersze pliku maj� nast�puj�c� posta�:
5
1 3 6 7 9
5
17 22 27 32 37 
*/

/* Wyniki
61.1:
Liczba ci�g�w: 44
Najwi�ksza r�nica: 246849
61.2:
1
27
551368
1000000
250047
1000
35937
531441
*/

const int SIZE = 100;

/*
Podaj, ile spo�r�d podanych w pliku ciagi.txt ci�g�w jest ci�gami 
arytmetycznymi. Znajd� w�r�d nich ci�g o najwi�kszej r�nicy i oblicz jego 
r�nic�. Liczb� ci�g�w arytmetycznych oraz najwi�ksz� r�nic� zapisz w pliku 
wynik1.txt. 
*/

void z1() {
  cout << "Zadanie 1:" << endl;
  ifstream in("ciagi.txt");
  int tab[1000];
  int length, difference;
  int counter = 0, max = 0;
  bool flag;
  for (int i = 0; i < SIZE; i++) {
    flag = true;
    in >> length;
    for (int j = 0; j < length; j++) in >> tab[j];
    difference = tab[1] - tab[0];
    for (int j = 1; j < length; j++) {
      if (tab[j] - tab[j - 1] != difference) flag = false;
    }
    if (flag) {
      counter++;
      if (difference > max) max = difference;
    }
  }
  in.close();
  ofstream out("wynik1.txt");
  out << "Liczba ciagow: " << counter << "\n";
  cout << "Liczba ciagow: " << counter << "\n";
  out << "Najwieksza roznica: " << max << "\n";
  cout << "Najwieksza roznica: " << max << "\n";
  out.close();
}

/*
Dla ka�dego podanego ci�gu znajd� � je�li istnieje � najwi�ksz� wyst�puj�c� w 
nim liczb�, kt�ra jest pe�nym sze�cianem jakiej� liczby naturalnej (w pierwszym 
z przyk�adowych ci�g�w jest to 1 = 1^3 , w drugim � 27 = 3^3).
Znalezione liczby (po jednej dla ka�dego ci�gu, w kt�rym taka liczba wyst�puje) 
zapisz w pliku wynik2.txt, w kolejno�ci zgodnej z kolejno�ci� ci�g�w, z kt�rych 
pochodz�
*/

void z2() {
  cout << "Zadanie 2:" << endl;
  ifstream in("ciagi.txt");
  ofstream out("wynik2.txt", ios::app);
  int tab[1000];
  int length, max;
  bool flag;
  for (int i = 0; i < SIZE; i++) {
    in >> length;
    for (int j = 0; j < length; j++) in >> tab[j];
    max = 0;
    flag = false;
    for (int j = 0; j < length; j++) {
      for (int k = 1; k <= tab[j]; k++) {
        if (k * k * k == tab[j]) {
          if (tab[j] > max) max = tab[j];
          break;
        }
      }
    }
    if (max > 0) {
      cout << max << endl;
      out << max << endl;
    }
  }
  in.close();
  out.close();
}

int main() {
  z1();
  z2();
}
