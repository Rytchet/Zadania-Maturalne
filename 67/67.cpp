#include <iostream>
#include <fstream>
using namespace std;

/* Tre��
Binarny fraktal Fibonacciego to dwuwymiarowa tablica zawieraj�ca w kolejnych wierszach
binarne zapisy kolejnych liczb Fibonacciego, gdzie ka�de zero w zapisie zast�piono bia�ym
kwadratem, a ka�d� jedynk� czarnym kwadratem (p. rysunek). Wszystkie binarne zapisy powinny
sk�ada� si� z jednakowej liczby cyfr, czyli do zapis�w kr�tszych ni� najd�u�szy nale�y
doda� zera wiod�ce. 
Napisz program komputerowy, za pomoc� kt�rego uzyskasz odpowiedzi do poni�szych zada�.
Rysunek fraktala (zadanie nr 3) wykonaj, wykorzystuj�c dost�pne narz�dzia informatyczne.
Odpowiedzi do poszczeg�lnych zada� zapisz w pliku tekstowym o nazwie wyniki.txt,
natomiast rysunek fraktala w pliku fraktal.xxx, gdzie xxx oznacza rozszerzenie
pliku, w kt�rym zapisany jest obraz fraktala. 
*/

/* Wyniki

*/

const int SIZE = 40;
int tab[SIZE];
ofstream out("wyniki.txt", ios::app);

void startTask(int n) {
  cout << "Zadanie " << n << ":" << endl;
  out << "Zadanie " << n << ":" << endl;
}

/* Zadanie 1
Podaj warto�ci F10, F20, F30, F40. Zapisz ka�d� z liczb w osobnym wierszu
*/

void z1() {
  startTask(1);
  cout << tab[9] << endl << tab[19] << endl << tab[29] << endl;
  cout << tab[39] << endl << endl;
  
  out << tab[9] << endl << tab[19] << endl << tab[29] << endl;
  out << tab[39] << endl << endl;
}

/* Zadanie 2
Znajd� wszystkie liczby pierwsze w�r�d liczb F1, F2, � , F40. Zapisz ka�d� z liczb w osobnym
wierszu. 
*/

bool isPrime(int n) {
  if (n <= 1) return false;
  else if (n % 2 == 0 && n != 2) return false;
  for (int i = 3; i * i <=n; i += 2) {
    if (n % i == 0) return false;
  }
  return true;
}

void z2() {
  startTask(2);
  for (int i = 0; i < SIZE; i++) {
    if (isPrime(tab[i])) {
      cout << tab[i] << endl;
      out << tab[i] << endl;
    }
  }
  cout << endl;
  out << endl;
}

/* Zadanie 3
Dla pierwszych 40 liczb Fibonacciego utw�rz binarny fraktal Fibonacciego:
� Wypisz reprezentacj� binarn� wszystkich liczb Fibonacciego od F1 do F40.
� Wyr�wnaj d�ugo�ci reprezentacji binarnych wszystkich liczb Fibonacciego od F1 do
  F40 i na ich podstawie sporz�d� obraz binarnego fraktala Fibonacciego.    
*/

string toBinary(int n) {
  string result = "";
  while (n > 0) {
    if (n % 2 == 1) result = "1" + result;
    else result = "0" + result;
    n /= 2;
  }
  return result;
}

void z3() {
  startTask(3);
  string bin;
  int length = toBinary(tab[39]).length();
  for (int i = 0; i < SIZE; i++) {
    bin = toBinary(tab[i]);
    cout << bin << endl;
    out << bin << endl;
    while (bin.length() < length) {
      bin = "0" + bin;
    }
  }
  cout << endl;
  ofstream fraktal("import.txt", ios::app);
  for (int i = 0; i < SIZE; i++) {
    bin = toBinary(tab[i]);
    while (bin.length() < length) {
      bin = "0" + bin;
    }
    cout << bin << endl;
    fraktal << bin << endl;
  }
  fraktal.close();
  cout << endl;
  out << endl;
}

/* Zadanie 4
Podaj w zapisie binarnym wyrazy ci�gu Fibonacciego z zakresu od F1 do F40, kt�re w tym
zapisie maj� dok�adnie 6 jedynek. 
*/

void z4() {
  startTask(4);
  string bin;
  int counter;
  for (int i = 0; i < SIZE; i++) {
    bin = toBinary(tab[i]);
    counter = 0;
    for (int j = 0; j < bin.length(); j++) {
      if (bin[j] == '1') counter++;
    }
    if (counter == 6) {
      cout << bin << endl;
      out << bin << endl;
    }
  }
}

int main() {
  tab[0] = 1;
  tab[1] = 1;
  for (int i = 2; i < SIZE; i++) {
    tab[i] = tab[i - 1] + tab[i - 2]; 
  }
  
  z1();
  z2();
  z3();
  z4();
  
  out.close();
}
