#include <iostream>
#include <fstream>
using namespace std;
// Cze�� Dominisia
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
64.1: 13, 381

64.2: 60,
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
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

/*
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

/*
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

void displayPictureWithoutParity() {
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      cout << tab[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

/*
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
  for (int i = 0; i < 21; i++) {
    for (int j = 0; j < 21; j++) {
      if (i == 21 && j == 21) continue;
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
  for (int i = 0; i < 21; i++) {
    for (int j = 0; j < 21; j++) {
      if (i == 21 && j == 21) continue;
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
  if (countWrongParityVertical() < 2 && countWrongParityHorizontal() < 2)
    return true;
}

int main() {
  // Zadanie 1
  int rewersCounter = 0, maxBlacks = 0;
  // Zadanie 2
  int recurentCounter = 0;
  bool recurentFlag = true;
  // Zadanie 3
  int correctCounter = 0, repairableCounter = 0, unrepairableCounter = 0, 
      maxWrongParity = 0, wrongParity;
  
  for (int i = 0; i < SIZE; i++) {
    readPicture();
    // Zadanie 1
    if (isRewers()) rewersCounter++;
    if (countBlacks() > maxBlacks) maxBlacks = countBlacks();
    
    // Zadanie 2
    if (isRecurent() && recurentFlag) {
      cout << "Obrazek do zadania 2: " << endl;
      displayPictureWithoutParity();
      recurentFlag = false;
    }
    if (isRecurent()) recurentCounter++;
    
    // Zadanie 3
    if (isCorrect()) correctCounter++;
    else if (isRepairable()) repairableCounter++;
    else unrepairableCounter++;
    wrongParity = countWrongParity();
    if (wrongParity > maxWrongParity) maxWrongParity = wrongParity;
  }
  
  cout << "Zadanie 1:" << endl;
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
