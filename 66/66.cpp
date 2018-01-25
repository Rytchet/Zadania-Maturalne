#include <iostream>
#include <fstream>
using namespace std;

/* Tre��
W pliku trojki.txt w oddzielnych wierszach znajduje si� 1000 tr�jek liczb naturalnych
z przedzia�u od 1 do 550000000. W ka�dym wierszu s� umieszczone trzy liczby rozdzielone
pojedynczymi odst�pami. 
Przyk�ad
3 4 5
12 5 13
12 491 17
11 13 143
15 28 91 
*/

/* Wyniki
66.1:
25320 29269 40
24810 10353 27
15276 20113 28
13867 24491 45
19677 6037 46
19688 2020 36

66.2:
6131 20807 127567717
26297 6329 166433713
24767 809 20036503
28477 19289 549292853
24799 6359 157696841
691 11003 7603073
9631 28351 273048481
6661 26393 175803773
5881 28429 167190949
18587 21739 404062793

66.3:
58140 58141 341
343 58824 58825
681 231880 231881
683 233244 233245
1021 521220 521221
1023 523264 523265
926160 1361 926161
928885 1363 928884
1701 1446700 1446701
1703 1450104 1450105

66.4:
604 wierszy
Najdluzszy ciag: 11
*/

const int SIZE = 1000;

void display(int a, int b, int c) {
  cout << a << " " << b << " " << c << endl;
}

/* Zadanie 1
Wypisz wszystkie tr�jki liczb z pliku trojki.txt, w kt�rych suma cyfr dw�ch pierwszych
liczb jest r�wna ostatniej (trzeciej) liczbie. 
*/

int sumOfDigits(int n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

void z1() {
  cout << "Zadanie 1:" << endl;
  ifstream in("trojki.txt");
  int a, b, c;
  for (int i = 0; i < SIZE; i++) {
    in >> a >> b >> c;
    if (sumOfDigits(a) + sumOfDigits(b) == c) display(a, b, c);
  }
  in.close();
  cout << endl;
}

/*
Wypisz wszystkie wiersze z pliku trojki.txt zawieraj�ce takie trzy liczby a, b, c, w kt�-
rych a i b s� liczbami pierwszymi oraz c = a � b. 
*/

bool isPrime(int n) {
  if (n <= 1) return false;
  if (n % 2 == 0 && n!= 2) return false;
  for (int i = 3; i * i <= n; i += 2) {
    if (n % i == 0) return false;
  }
  return true;
}

void z2() {
  cout << "Zadanie 2:" << endl;
  ifstream in("trojki.txt");
  int a, b, c;
  for (int i = 0; i < SIZE; i++) {
    in >> a >> b >> c;
    if (isPrime(a) && isPrime(b) && a * b == c) display(a, b, c);
  }
  in.close();
  cout << endl;
}

/*
Wypisz z pliku trojki.txt wszystkie pary s�siaduj�cych ze sob� wierszy, takie �e liczby
w tych wierszach s� d�ugo�ciami bok�w tr�jk�t�w prostok�tnych. 
*/

bool isRightTriangle(int a, int b, int c) {
  return ((a * a) + (b * b) == (c * c) || 
          (a * a) + (c * c) == (b * b) || 
          (c * c) + (b * b) == (a * a));
}

void z3() {
  cout << "Zadanie 3:" << endl;
  ifstream in("trojki.txt");
  int tab[SIZE][3];
  for (int i = 0; i < SIZE; i++) {
    in >> tab[i][0] >> tab[i][1] >> tab[i][2];
  }
  for (int i = 1; i < SIZE; i++) {
    if (isRightTriangle(tab[i - 1][0], tab[i - 1][1], tab[i - 1][2]) &&
        isRightTriangle(tab[i][0], tab[i][1], tab[i][2])) {
          
      display(tab[i - 1][0], tab[i - 1][1], tab[i - 1][2]);
      display(tab[i][0], tab[i][1], tab[i][2]);
    }
  }
  in.close();
  cout << endl;
}

/*
Podaj, ile jest w pliku trojki.txt wierszy, w kt�rych znajduj� si� liczby reprezentuj�ce
d�ugo�ci bok�w tr�jk�ta. Ci�g wierszy nazywamy tr�jk�tnym, je�li liczby w ka�dym wierszu
reprezentuj� d�ugo�ci bok�w tr�jk�ta. Podaj d�ugo�� najd�u�szego ci�gu tr�jk�tnego w pliku. 
*/

bool isTriangle(int a, int b, int c) {
  return (a + b > c && a + c > b && b + c > a);
}

void z4() {
  cout << "Zadanie 4:" << endl;
  ifstream in("trojki.txt");
  int counter = 0, maxChain = 0, chain = 0;
  int a, b, c;
  for (int i = 0; i < SIZE; i++) {
    in >> a >> b >> c;
    if (isTriangle(a, b, c)) {
      counter++;
      chain++;
    }
    else {
      if (chain > maxChain) maxChain = chain;
      chain = 0;
    }
  }
  cout << counter << " wierszy" << endl;
  cout << "Najdluzszy ciag: " << maxChain << endl;
}

int main() {
  z1();
  z2();
  z3();
  z4();
}
