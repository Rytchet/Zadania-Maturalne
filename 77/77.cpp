#include <iostream>
#include <fstream>
using namespace std;

/* Tre��
W zadaniu rozwa�amy teksty zbudowane tylko z wielkich liter alfabetu angielskiego, znak�w
odst�pu i znak�w przestankowych (przecinek, kropka). Oto litery alfabetu i numery ich pozycji
w alfabecie:
A B C D E F G H I J K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
Szyfrowanie Vigenere�a polega na zast�pieniu ka�dej litery tekstu �r�d�owego liter� odleg��
od niej cyklicznie w alfabecie o k pozycji.
Warto�� k nie jest z g�ry ustalona dla ca�ego tekstu �r�d�owego, lecz dla ka�dej litery
w tek�cie jest okre�lana osobno, w oparciu o s�owo przyj�te jako klucz szyfrowania.
Przyst�puj�c do szyfrowania, nale�y przyporz�dkowa� kolejnym literom tekstu �r�d�owego
kolejne litery klucza, chodz�c po nim cyklicznie, je�li jest kr�tszy od szyfrowanego tekstu.
Znaki inne ni� litery nie s� szyfrowane, pomijamy je podczas przypisywania liter klucza. Pozycja
litery klucza w alfabecie jest t� warto�ci� k, o jak� nale�y wykona� przesuni�cie
wzgl�dem litery tekstu �r�d�owego w celu znalezienia odpowiadaj�cej jej litery szyfru. 
Przyk�ad
tekst �r�d�owy: �JEST OK�, klucz: �EWA�
Tekst �r�d�owy  J        E       S        T        spacja  O       K
Klucz           E        W       A        E                W       A
Pozycja klucza  4        22      0        4                22      0
Szyfr           J�4 = N  E�22=A  S�0 = S  T�4 = X  spacja  O�22=K  K�0 = K
wynik szyfrowania: �NASX KK�. 
*/

/* Wyniki
Zadanie 1:
a) 19
b) EI XILLG AWLMA HCFLLGGKG LKCO JSHKAJNBSIOJ, JPVUCYZX CEUWC OQQ UKDKR SMLX 
QZLWEGMWZKXS, UW ZGG VGXMA RXAQQ HGRRXSOJ. U KMEJK MGX WKPGZ OPXKD HXSVPMNG, 
FM PHC PIGXS EWWYF YKBETKUNG. M HGRJB KVZM OQQ UKD BHKCO TNQQPBZ, RH 
PTLQEWBMFNZGIG KGJMDXC V XEYO VCFZGLMT. RXRTJ JSIFAJDRM.

Zadanie 2:
W RZECZYWISTOSCI PRZESZLOSC NIE ISTNIEJE, JEDYNIE WSPOMNIENIE PRZESZLOSCI. 
MRUGNIJCIE OCZAMI, A SWIAT KTORY ZOBACZYCIE NIE ISTNIAL KIEDY ZAMYKALISCIE 
POWIEKI. JEDYNYM WLASCIWYM STANEM UMYSLU JEST ZASKOCZENIE. JEDYNYM WLASCIWYM 
STANEM SERCA JEST RADOSC. NIEBO KTORE WIDZICIE NIE BYLO JESZCZE NIGDY PRZEZ WAS 
OGLADANE. MOMENT ABSOLUTNEJ PERFEKCJI JEST TERAZ. CIESZCIE SIE NIM. 
TERRY PRATCHETT.

Zadanie 3:
a) A: 8 B: 19 C: 13 D: 21 E: 19 F: 4 G: 8 H: 21 I: 12 J: 13 K: 6 L: 14 M: 16 
N: 15 O: 10 P: 10 Q: 8 R: 11 S: 12 T: 17 U: 13 V: 11 W: 21 X: 12 Y: 10 Z: 7
*/

/* Zadanie 1
W pliku dokad.txt znajduje si� jeden wiersz z tekstem. D�ugo�� tekstu nie przekracza
1024 znak�w. Nale�y zaszyfrowa� ten tekst metod� Vigenere�a, u�ywaj�c jako klucza s�owa:
�LUBIMYCZYTAC�.
a) Podaj liczb� powt�rze� klucza niezb�dn� do zaszyfrowania ca�ego tekstu �r�d�owego
(uwzgl�dniaj�c w nich ostatnie rozpocz�te powt�rzenie).
b) Podaj zaszyfrowany tekst i zapisz go w pliku z odpowiedziami. 
'A' = 65 'Z' = 90
*/

string szyfruj(string s, string key) {
  string result;
  int keyIndex = 0;
  int move;
  int index;
  int counter = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] < 'A' || s[i] > 'Z') {
      result += s[i];
      continue;
    }
    move = (int) key[keyIndex] - 65;
    index = (int) s[i] - 65;
    index += move;
    if (index > 25) index = (index - 1) % 25;
    index += 65;
    result += (char) index;
    
    keyIndex++;
    if (keyIndex == key.length()) keyIndex = 0;
  }
  return result;
}

void z1() {
  cout << "Zadanie 1:" << endl;
  ifstream in("dokad.txt");
  string s = "";
  string temp;
  while (in >> temp) s += temp + " ";
  string key = "LUBIMYCZYTAC";
  
  
  cout << "a) " << 19 << endl; // Policzone dodaj�c licznik do funkcji szyfruj
  cout << "b) " << szyfruj(s, key) << endl << endl;
}

/* Zadanie 2
W pliku szyfr.txt zapisano dwa wiersze. W pierwszym wierszu znajduje si� tekst zaszyfrowany
metod� Vigenere�a. W drugim wierszu znajduje si� klucz u�yty do tego szyfrowania.
Szyfr zawiera wiele s��w. Jego ��czna d�ugo�� nie przekracza 1024 znak�w. Szyfrowaniu
podlega�y tylko wielkie litery tekstu, za� odst�py i znaki przestankowe pozosta�y bez zmiany. 
Odszyfruj tekst i umie�� jego posta� �r�d�ow� w pliku z odpowiedziami. 
*/

void z2() {
  cout << "Zadanie 2:" << endl;
  string key = "ZLODZIEJCZASU"; // wyci�te z pliku
  string s = "";
  string temp;
  ifstream in("szyfr.txt");
  while (in >> temp) s += temp + " ";
  
  int keyIndex = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == ' ' || s[i] == ',' || s[i] == '.') continue;
    s[i] -= key[keyIndex];
    s[i] += 65;
    if (s[i] < 'A') s[i] += 26;
    keyIndex++;
    if (keyIndex == key.length()) keyIndex = 0;
  }
  cout << s << endl << endl;
}

/* Zadanie 3
a) Podaj liczby wyst�pie� poszczeg�lnych liter A, B, ..., Z w tre�ci szyfru zawartego
  w pierwszym wierszu pliku szyfr.txt. 
*/

void z3() {
  cout << "Zadanie 3:" << endl;
  // a)
  int tab[26];
  for (int i = 0; i < 26; i++) {
    tab[i] = 0;
  }
  ifstream in("szyfr.txt");
  string s;
  while (in >> s) {
    for (int i = 0; i < s.length(); i++) {
      if (s[i] >= 'A' && s[i] <= 'Z') {
        tab[s[i] - 65]++;
      }
    }
  }
  for (int i = 0; i < 26; i++) {
    cout << (char) (i + 65) << ": " << tab[i] << " ";
  }
  
  
}

int main() {
  z1();
  z2();
  z3();
}
