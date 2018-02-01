#include <iostream>
#include <fstream>
using namespace std;

/* Tre��
Rozwa�amy szyfrowanie przestawieniowe, w kt�rym kluczem jest n-elementowa tablica zawieraj�ca
r�ne liczby ca�kowite z przedzia�u [1, n]. Na przyk�ad kluczem 5-elementowym
mo�e by� tablica [3, 2, 5, 4, 1].
Szyfrowanie napisu A (o d�ugo�ci co najmniej n) kluczem n-elementowym P[1..n] odbywa si�
w nast�puj�cy spos�b:
� pierwsza litera s�owa A zamieniana jest miejscami z liter� na pozycji P[1],
� nast�pnie druga litera s�owa A zamieniana jest z liter� na pozycji P[2]
� itd.
Uzyskane na ko�cu s�owo jest szyfrem napisu A z kluczem P. 
138 Egzamin maturalny. Informatyka. Poziom rozszerzony. Zbi�r zada�
Je�li napis A ma wi�cej ni� n liter, to po n-tym kroku powy�szego algorytmu kolejn� liter�
zamieniamy zn�w z liter� na pozycji P[1] itd. Oznacza to, �e w i-tym kroku zamieniamy litery
na pozycjach i oraz P[1+(i-1) mod n]. 
// Polecam spojrze� do zbioru, jest obrazek z lepszym wyja�nieniem
Napis �KAAYTRNFOIM� jest zatem szyfrem napisu �INFORMATYKA� z kluczem [3, 2, 5, 4, 1]. 
*/

/* Wyniki

*/

/* Zadanie 1
W pliku szyfr1.txt dane s�:
� w wierszach o numerach od 1 do 6 � napisy z�o�one z 50 liter alfabetu �aci�skiego;
� w wierszu nr 7 � klucz 50-elementowy; liczby oddzielone s� pojedynczym odst�-
pem.
Zaszyfruj wszystkie sze�� napis�w zgodnie z opisan� metod�. Wynik, czyli zaszyfrowane
napisy, zapisz w osobnych wierszach w pliku wyniki_szyfr1.txt. 
*/

string szyfruj(string s, int key[], int keyLen) {
  char temp;
  int keyIndex = 0;
  for (int i = 0; i < s.length(); i++) {
    temp = s[i];
    s[i] = s[key[keyIndex] - 1];
    s[key[keyIndex] - 1] = temp;
    keyIndex++;
    if (keyIndex == keyLen) keyIndex = 0;
  }
  return s;
}

void z1() {
  cout << "Zadanie 1:" << endl;
  ifstream in("szyfr1.txt");
  string tab[6];
  int key[50];
  for (int i = 0; i < 6; i++) in >> tab[i];
  for (int i = 0; i < 50; i++) in >> key[i];
  
  for (int i = 0; i < 6; i++) cout << szyfruj(tab[i], key, 50) << endl;
  cout << endl;
}

/* Zadanie 2
W pliku szyfr2.txt dane s�:
� w pierwszym wierszu � napis z�o�ony z 50 liter alfabetu �aci�skiego;
� w drugim wierszu � klucz 15-elementowy; liczby oddzielone s� pojedynczym odst�-
pem.
Zaszyfruj dany napis zgodnie z opisan� metod�. Wynik, czyli zaszyfrowany napis, zapisz
w pliku wyniki_szyfr2.txt. 
*/

void z2() {
  cout << "Zadanie 2:" << endl;
  ifstream in ("szyfr2.txt");
  string s;
  in >> s;
  int key[15];
  for (int i = 0; i < 15; i++) in >> key[i];
  cout << szyfruj(s, key, 15) << endl;
}

int main() {
  z1();
  z2();
}
