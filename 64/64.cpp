#include <iostream>
#include <fstream>
using namespace std;

/* Tre��
Bit parzysto�ci ci�gu z�o�onego z zer i jedynek jest r�wny 0, gdy w ci�gu tym wyst�puje parzysta
liczba jedynek, w przeciwnym razie bit parzysto�ci jest r�wny 1.
Czarno-bia�y obrazek rozmiaru n � n sk�ada si� z n wierszy po n pikseli. Ka�dy wiersz pikseli
reprezentujemy jako ci�g zer i jedynek, ka�dy bia�y piksel reprezentujemy przez 0, czarny �
przez 1. Na ko�cu ka�dego wiersza dodany jest bit parzysto�ci, podobnie pod ostatnim wierszem
obrazka do��czony jest wiersz bit�w parzysto�ci ka�dej z n kolumn. Bit�w parzysto�ci
nie traktujemy jako cz�ci obrazka.
Plik dane_obrazki.txt sk�ada si� z opisu 200 czarno-bia�ych obrazk�w o rozmiarze
20 � 20 pikseli. S�siednie obrazki oddzielone s� w pliku pustym wierszem.
*/

/* Wyniki
64.1:
Rewersow: 13
Najwieksza ilosc czarnych: 381

64.2:
Liczba obrazkow rekurencyjnych: 60
11111111111111111111
00000000000000000000
11111111111111111111
00000000000000000000
11111111111111111111
00000000000000000000
11111111111111111111
00000000000000000000
11111111111111111111
00000000000000000000
11111111111111111111
00000000000000000000
11111111111111111111
00000000000000000000
11111111111111111111
00000000000000000000
11111111111111111111
00000000000000000000
11111111111111111111
00000000000000000000

64.3:
Liczba poprawnych:171
Liczba naprawialnych: 14
Liczba nienaprawialnych: 15
Najwiecej zlej parzystosci: 7

64.4:
(index, wiersz, kolumna)
(14, 1, 15)
(19, 4, 20)
(26, 21, 13)
(29, 2, 8)
(33, 15, 21)
(115, 21, 14)
(116, 21, 13)
(129, 21, 14)
(131, 10, 7)
(143, 7, 15)
(154, 7, 7)
(161, 21, 17)
(162, 21, 16)
(187, 21, 18)
*/

const int SIZE = 200;
ifstream in("dane_obrazki.txt");
char tab[21][21];

void readPicture() {
  for (int i = 0; i < 21; i++) {
    for (int j = 0; j < 21; j++) {
      if (i == 20 && j == 20) return;
      in >> tab[i][j];
    }
  }
}

void displayPicture() {
  for (int i = 0; i < 21; i++) {
    for (int j = 0; j < 21; j++) {
      cout << tab[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

/* Zadanie 1
Obrazek nazywamy rewersem, je�li liczba wyst�puj�cych w nim pikseli czarnych jest wi�ksza
od liczby pikseli bia�ych.
Przyk�ad: W obrazku z powy�szego przyk�adu wyst�puje 18 pikseli czarnych i 7 pikseli
bia�ych. Zatem jest on rewersem.
Podaj, ile jest w pliku obrazk�w, kt�re s� rewersami. Podaj te� najwi�ksz� liczb� pikseli czarnych
wyst�puj�cych w jednym obrazku. 
*/

bool isRewers() {
  int black = 0, white = 0;
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      if (tab[i][j] == '0') white++;
      if (tab[i][j] == '1') black++;
    }
  }
  return black > white;
}

int countBlacks() {
  int counter = 0;
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      if (tab[i][j] == '1') counter++;
    }
  }
  return counter;
}

/* Zadanie 2
Obrazek rozmiaru n � n b�dziemy nazywa� rekurencyjnym, je�li n jest parzyste oraz obrazek
sk�ada si� z 4 kopii tego samego obrazka rozmiaru n/2 * n/2.
Podaj liczb� obrazk�w rekurencyjnych w pliku wej�ciowym. Ponadto podaj opis pierwszego
obrazka rekurencyjnego wyst�puj�cego w pliku. W opisie obrazka pomi� bity parzysto�ci.
*/

bool isRecurent() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (tab[i][j] != tab[i][j + 10] || tab[i][j] != tab[i + 10][j] || 
          tab[i][j] != tab[i+10][j+10]) {
        return false;
      }
    }
  }
  return true;
}

void displayTaskTwo() {
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      cout << tab[i][j];
    }
    cout << endl;
  }
  cout << endl;
}

/* Zadanie 3
Obrazek nazywamy poprawnym, je�li wszystkie bity parzysto�ci s� w nim poprawne (zar�wno
w wierszach, jak i kolumnach). Obrazek nazywamy naprawialnym, je�li nie jest poprawny,
a jednocze�nie co najwy�ej jeden bit parzysto�ci wiersza i co najwy�ej jeden bit parzysto�ci
kolumny jest w nim niepoprawny.
Natomiast nienaprawialnym nazywamy obrazek, kt�ry nie jest poprawny i nie jest naprawialny. 
Podaj liczb� obrazk�w poprawnych, liczb� obrazk�w naprawialnych oraz liczb� obrazk�w
nienaprawialnych. Ponadto podaj najwi�ksz� liczb� b��dnych bit�w parzysto�ci wyst�puj�-
cych w jednym obrazku.
Bit parzysto�ci ci�gu z�o�onego z zer i jedynek jest r�wny 0, gdy w ci�gu tym wyst�puje parzysta
liczba jedynek, w przeciwnym razie bit parzysto�ci jest r�wny 1.
*/

int countWrongParityHorizontal() {
  int sum = 0, counter = 0;
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 21; j++) {
      if (tab[i][j] == '1' && j != 20) sum++;
      if (j == 20) {
        if (sum % 2 == 0 && tab[i][j] == '1') counter++;
        if (sum % 2 == 1 && tab[i][j] == '0') counter++; 
      }
    }
    sum = 0;
  }
  return counter;
}

int countWrongParityVertical() {
  int sum = 0, counter = 0;
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 21; j++) {
      if (tab[j][i] == '1' && j != 20) sum++;
      if (j == 20) {
        if (sum % 2 == 0 && tab[j][i] == '1') counter++;
        if (sum % 2 == 1 && tab[j][i] == '0') counter++; 
      }
    }
    sum = 0;
  }
  return counter;
}

int countWrongParity() {
  return countWrongParityHorizontal() + countWrongParityVertical();
}

bool isCorrect () {
  if (countWrongParity() == 0) return true;
}

bool isRepairable() {
  if (isCorrect()) return false;
  if (countWrongParityVertical() < 2 && countWrongParityHorizontal() < 2)
    return true;
}

/* Zadanie 4
W obrazku naprawialnym wystarczy zmieni� jedn� warto��, aby uzyska� obrazek poprawny.
Dok�adniej, je�li niepoprawne s� bity parzysto�ci i-tego wiersza i j-tej kolumny, wystarczy
zmieni� j-ty piksel w i-tym wierszu. Je�li niepoprawny jest dok�adnie jeden bit parzysto�ci
(wiersza albo kolumny), wystarczy zmieni� ten bit parzysto�ci. 
Podaj numery obrazk�w naprawialnych, przyjmuj�c, �e numery kolejnych obrazk�w w pliku
to 1, 2, 3 itd. Przy numerze ka�dego obrazka naprawialnego podaj numer wiersza i kolumny
warto�ci, kt�r� wystarczy zmieni�, aby uzyska� obrazek poprawny. 
*/

int main() {
  // Zadanie 1
  int rewersCounter = 0, maxBlacks = 0;
  // Zadanie 2
  int recurentCounter = 0;
  bool recurentFlag = true;
  // Zadanie 3
  int correctCounter = 0, repairableCounter = 0, unrepairableCounter = 0, 
      maxWrongParity = 0, wrongParity;
  // Zadanie 4
  int pictureCounter = 0, controlSum, line, column;
  
  for (int n = 0; n < SIZE; n++) {
    readPicture();
    // Zadanie 1
    if (isRewers()) rewersCounter++;
    if (countBlacks() > maxBlacks) maxBlacks = countBlacks();
    
    // Zadanie 2
    if (isRecurent() && recurentFlag) {
      cout << "Obrazek do zadania 2: " << endl;
      displayTaskTwo();
      recurentFlag = false;
      // Pod koniec p�tli zadanie 4
      cout << endl << "Zadanie 4: (index, wiersz, kolumna)" << endl; 
    }
    if (isRecurent()) recurentCounter++;
    
    // Zadanie 3
    if (isCorrect()) correctCounter++;
    else if (isRepairable()) repairableCounter++;
    else unrepairableCounter++;
    wrongParity = countWrongParity();
    if (wrongParity > maxWrongParity) maxWrongParity = wrongParity;
    
    // Zadanie 4
    pictureCounter++;
    if (isRepairable()) {
      column = 0;
      line = 0;
      cout << "(" << pictureCounter << ", ";
      // Sprawdzenie bitu poziomo
      if (countWrongParityHorizontal() == 1) {
        controlSum = 0;
        for (int i = 0; i < 20; i++) {
          for (int j = 0; j < 21; j++) {
            if (tab[i][j] == '1' && j != 20) controlSum++;
            if (j == 20) {
              if ((controlSum % 2 == 0 && tab[i][j] == '1') ||
                  (controlSum % 2 == 1 && tab[i][j] == '0')) {
                line = i + 1; 
              }
            }
          }
          controlSum = 0;
        }
      }
      // Sprawdzenie bitu pionowo
      if (countWrongParityVertical() == 1) {
        controlSum = 0;
        for (int i = 0; i < 20; i++) {
          for (int j = 0; j < 21; j++) {
            if (tab[j][i] == '1' && j != 20) controlSum++;
            if (j == 20) {
              if ((controlSum % 2 == 0 && tab[j][i] == '1') ||
                  (controlSum % 2 == 1 && tab[j][i] == '0')) {
                column = i + 1; 
              }
            }
          }
          controlSum = 0;
        }
      }
      if (line == 0) line = 21;
      if (column == 0) column = 21;
      cout << line << ", " << column << ")" << endl;
    }
  }
  
  cout << endl << "Zadanie 1:" << endl;
  cout << "Rewersow: " << rewersCounter << endl;
  cout << "Najwieksza ilosc czarnych: " << maxBlacks << endl << endl;
  
  cout << "Zadanie 2:" << endl;
  cout << "Liczba obrazkow rekurencyjnych: " << recurentCounter << endl << endl;
  
  cout << "Zadanie 3:" << endl;
  cout << "Liczba poprawnych:" << correctCounter << endl;
  cout << "Liczba naprawialnych: " << repairableCounter << endl;
  cout << "Liczba nienaprawialnych: " << unrepairableCounter << endl;
  cout << "Najwiecej zlej parzystosci: " << maxWrongParity << endl << endl;
  
}
