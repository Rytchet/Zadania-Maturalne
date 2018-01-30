#include <iostream>
#include <fstream>
using namespace std;

/* Tre��
Dany jest tekst z�o�ony ze s��w zbudowanych z ma�ych liter alfabetu angielskiego. Metoda
szyfrowania afinicznego � dla kt�rej kluczem szyfruj�cym s� dwie liczby ca�kowite A i B �
polega na wykonaniu kolejno nast�puj�cych operacji:
� zast�pienia kolejnych liter alfabetu liczbami od 0 do 25: 'a' przez 0, 'b' przez 1, 'c'
  przez 2 itd. wed�ug przyporz�dkowania przedstawionego w poni�szej tabeli:
  a b c d e f g h i j k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
  0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
� pomno�enia liczby odpowiadaj�cej ka�dej literze przez A i dodania otrzymanego wyniku
  do B, 
� zamiany otrzymanych liczb z powrotem na litery; je�li liczba jest wi�ksza ni� 25, bierze
  si� jej reszt� z dzielenia przez 26. 
Parametry klucza, czyli liczby A i B, powinny by� liczbami ca�kowitymi z przedzia�u [0, 25].
Dla przyk�adu, je�li kluczem szyfruj�cym jest (3, 7), czyli A = 3, za� B = 7, to litera 'n' jest
najpierw zast�powana liczb� 13. Po pomno�eniu jej przez A i dodaniu B otrzymujemy wynik
r�wny 46. W nast�pnym kroku otrzymujemy liter� o numerze 46 � 26 = 20, czyli 'u'.
Okazuje si�, �e do odszyfrowania szyfru afinicznego mo�na zastosowa� t� sam� metod�, by�
mo�e z innym kluczem. Na przyk�ad, je�li napis zaszyfrujemy kluczem (3, 7), to aby go odszyfrowa�,
stosujemy ten sam algorytm z kluczem (9, 15). Dla przyk�adu, deszyfruj�c liter�
'u' z kluczem (9, 15), otrzymamy liczb� 20 * 9 + 15 = 195, czyli liter� 'n', jako �e 195 mod 26
= 13. Klucz (9,15) jest w�wczas kluczem deszyfruj�cym dla klucza (3,7). 
*/

/* Wyniki
Zadanie 1:
did
desired
destroyed
devised

Zadanie 2:
wkqoocjqwo
iujolqzzwr
udwjtljuip
tlcpgujurjqk
yplcjdwotwr
kqrrfwwcjtl
mupmwjpqpg
kqrrfwwcjtl
wotchfqolwr
*/

/* Zadanie 1
W pliku tekst.txt dany jest, w pojedynczym wierszu, tekst z�o�ony z dok�adnie 805 s��w
zapisanych ma�ymi literami alfabetu angielskiego, oddzielonych znakami odst�pu. �adne
s�owo nie jest d�u�sze ni� 15 znak�w.
Znajd� i wypisz te s�owa, kt�rych zar�wno pierwsz�, jak i ostatnia liter� jest 'd'. 
*/

void z1() {
  cout << "Zadanie 1:" << endl;
  ifstream in("tekst.txt");
  string s;
  while (in >> s) {
    if (s[0] == 'd' && s[s.length() - 1] == 'd') cout << s << endl;
  }
  in.close();
  cout << endl;
}

/* Zadanie 2
Zaszyfruj szyfrem afinicznym o kluczu (5, 2) te s�owa z pliku tekst.txt, kt�re sk�adaj� si�
z co najmniej 10 liter. Wypisz je w postaci zaszyfrowanej, po jednym w wierszu. 
(int) 'a' = 97
*/

string cipher(string s, int a, int b) {
  int n;
  for (int i = 0; i < s.length(); i++) {
    n = (int) s[i] - 97;
    n *= a;
    n += b;
    while (n > 25) n -= 26;
    s[i] = (char) n + 97;
  }
  return s;
}

void z2() {
  cout << "Zadanie 2:" << endl;
  ifstream in("tekst.txt");
  string s;
  while (in >> s) {
    if (s.length() < 10) continue;
    cout << cipher(s, 5, 2) << endl;
  }
  in.close();
  cout << endl;
}

/*
Plik probka.txt sk�ada si� z 5 wierszy, ka�dego zawieraj�cego dwa napisy. Pierwszy
z nich to pewne s�owo zapisane tekstem jawnym, drugi za� to to samo s�owo zaszyfrowane za
pomoc� szyfru afinicznego (ka�de s�owo innym kluczem).
Dla ka�dego z tych s��w znajd� i wypisz klucz szyfruj�cy oraz klucz deszyfruj�cy. 

A i B s� z przedzia�u [0, 26]
*/

void z3() {
  ifstream in("probka.txt");
  string normal, ciphered;
  bool flag;
  while (in >> normal >> ciphered) {
    flag = false;
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < 26; j++) {
        if (cipher(normal, i, j) == ciphered) {
          cout << "Szyfrujacy: (" << i <<  ", " << j << ") ";
          flag = true;
          break;
        }
      }
      if (flag) break;
    }
    flag = false;
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < 26; j++) {
        if (cipher(ciphered, i, j) == normal) {
          cout << "Deszyfrujacy: (" << i <<  ", " << j << ")" << endl;
          flag = true;
          break;
        }
      }
      if (flag) break;
    }
  }
  in.close();
  cout << endl;
}

int main() {
  z1();
  z2();
  z3();
}
