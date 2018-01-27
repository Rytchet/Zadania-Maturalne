#include <iostream> // std::fixed
#include <fstream>
#include <iomanip> // setprecision()
using namespace std;

/* Tre��
W pliku tekst.txt dany jest tekst z�o�ony ze s��w pisanych wielkimi literami alfabetu
angielskiego. S��w jest 1876, oddzielone s� one pojedynczymi odst�pami, a inne znaki poza
literami i spacjami w tek�cie nie wyst�puj�. Napisz program(-y), kt�ry poda odpowiedzi do
poni�szych zada�. Odpowiedzi zapisz w pliku wyniki.txt. 
*/

/* Wyniki

*/

const int SIZE = 1876;
string tab[SIZE];

/* Zadanie 1
Oblicz, ile jest w tek�cie s��w, w kt�rych wyst�puj� dwie kolejne takie same litery. 
*/

bool hasTwoLetters (string s) {
  for (int i = 1; i < s.length(); i++) {
    if (s[i] == s[i - 1]) return true;
  }
  return false;
}

void z1() {
  cout << "Zadanie 1:" << endl;
  int counter = 0;
  for (int i = 0; i < SIZE; i++) {
    if (hasTwoLetters(tab[i])) counter++;
  }
  cout << counter << endl << endl;
}

/* Zadanie 2
Sporz�d� statystyk� cz�stotliwo�ci wyst�powania liter w tek�cie: dla ka�dej litery podaj liczb�
jej wyst�pie� we wszystkich s�owach tekstu oraz jej procentowy udzia� w�r�d wyst�pie�
wszystkich liter w tek�cie(do statystyki nie wliczaj spacji). Odpowied� zapisz w nast�puj�cej
postaci:
A: 632 (7.56%) // 'A' = (char) 65
B: 196 (2.34%)
...
Warto�ci procentowe podaj w zaokr�gleniu do dw�ch miejsc po przecinku. 
*/

void z2() {
  cout << "Zadanie 2:" << endl;
  int counter[26];
  float allCounter = 0;
  for (int i = 0; i < 26; i++) counter[i] = 0;
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < tab[i].length(); j++) {
      counter[tab[i][j] - 65]++;
      allCounter++;
    }
  }

  for (int i = 0; i < 26; i++) {
    cout << (char) (i + 65) << ": " << counter[i] << " (";
    cout << fixed << setprecision(2) << counter[i] / allCounter * 100 << "%)";
    cout << endl;
  }
  cout << endl;
}

/* Zadanie 3
W�r�d s��w w tek�cie policz d�ugo�� najd�u�szego pods�owa (fragmentu z�o�onego z kolejnych
liter) z�o�onego z samych sp�g�osek. Pami�taj, �e samog�oski to: A, E, I, O, U oraz Y,
za� pozosta�e litery s� sp�g�oskami.
Podaj d�ugo�� najd�u�szego takiego pods�owa, liczb� s��w, kt�re zawieraj� pods�owo o takiej
d�ugo�ci, oraz pierwsze z nich, kt�re wyst�puje w pliku tekst.txt. 
*/

bool isVowel(char c) {
  return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y');
}

void z3() {
  cout << "Zadanie 3:" << endl;
  int maxLen = 0;
  string word;
  for (int i = 0; i < SIZE; i++) {
    word = "";
    for (int j = 0; j < tab[i].length(); j++) {
      if (!isVowel(tab[i][j])) word += tab[i][j];
      else {
        if (word.length() > maxLen) maxLen = word.length();
        word = "";
      }
    }
  }
  cout << "Najdluzsze slowo: " << maxLen << endl;
  int wordCount = 0;
  bool flag = true;
  for (int i = 0; i < SIZE; i++) {
    word = "";
    for (int j = 0; j < tab[i].length(); j++) {
      if (!isVowel(tab[i][j])) word += tab[i][j];
      if (isVowel(tab[i][j]) || j == tab[i].length() - 1) {
        if (word.length() == maxLen) {
          if (flag) {
            cout << "Pierwsze: " << tab[i] << endl;
            flag = false;
          }
          wordCount++;
          break;
        }
        word = "";
      }
    }
  }
  cout << "Liczba slow: " << wordCount << endl << endl;
}

int main() {
  ifstream in("tekst.txt");
  for (int i = 0; i < SIZE; i++) in >> tab[i];
  in.close();
  
  z1();
  z2();
  z3();
}
