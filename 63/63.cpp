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
63.1:
11
101000101000
10110001011000
1010
110110110110
100100
11001100
111111
10111011
101101
100100100100
110110
1100110011001100
1111
10011001
1001110011
1100111001
110110110110110110

63.2: 93

63.3:
259 ciagow.
Max: 248667 Min: 6
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

/*
Podaj liczb� ci�g�w z pliku ciagi.txt, w kt�rych nie wyst�puj� obok siebie dwie jedynki. 
*/

void z2() {
  cout << "Zadanie 2:" << endl;
  int length, counter = 0;
  for (int i = 0; i < SIZE; i++) {
    length = tab[i].length();
    counter++;
    for (int j = 1; j < length; j++) {
      if (tab[i][j] == '1' && tab[i][j - 1] == '1') {
        counter--;
        break;
      }
    }
  }
  cout << counter << endl;
}

/*
Liczb� p�pierwsz� nazywamy tak� liczb�, kt�ra jest iloczynem dw�ch liczb pierwszych.
Podaj, ile ci�g�w z pliku ciagi.txt jest reprezentacj� binarn� liczb p�pierwszych. Dodatkowo
podaj najwi�ksz� i najmniejsz� liczb� p�pierwsz� w zapisie dziesi�tnym. 
*/

bool isPrime(int x) {
  if (x <= 1) return false;
  if (x % 2 == 0 && x != 2) return false;
  for (int i = 3; i * i <= x; i += 2) {
    if (x % i == 0) return false;
  }
  return true;
}

bool isHalfPrime(int x) {
  if (isPrime(x)) return false;
  if (x % 2 == 0) return isPrime(x / 2);
  for (int i = 3; i * i <= x; i++) {
    if (x % i == 0) return isPrime(x / i);
  }
}

int binToDec(string bin) {
  int n = 0;
  int base = 1;
  for (int i = bin.length() - 1; i >= 0; i--) {
    n += (bin[i] - '0') * base;
    base *= 2;
  }
  return n;
}

void z3() {
  cout << "Zadanie 3:" << endl;
  int counter = 0, max = 0, min = 999999999;
  int number;
  for (int i = 0; i < SIZE; i++) {
    number = binToDec(tab[i]);

    if (isHalfPrime(number)) {
      counter++;
      if (number > max) max = number;
      if (number < min) min = number;
    }
  }
  cout << counter << " ciagow." << endl;
  cout << "Max: " << max << " Min: " << min << endl;
}

int main() {
  ifstream in("ciagi.txt");
  for (int i = 0; i < SIZE; i++) in >> tab[i];
  in.close();

  z1();
  z2();
  z3();
}
