#include <iostream>
#include <fstream>
using namespace std;

/*
W pliku liczby.txt znajduje si� 1000 tr�jek liczb ca�kowitych dodatnich rozdzielonych
pojedynczymi odst�pami, ka�da tr�jka � w osobnym wierszu. Liczby zapisane w pliku nale��
do przedzia�u [1, 32 767]. 
*/


/* Zadanie 1
Podaj, w ilu wierszach pliku z danymi liczby w tr�jkach s� uporz�dkowane rosn�co. 
*/

void z1() {
	cout << "Zadanie 1:" << endl;
	ifstream in("liczby.txt");
	int a, b, c;
	int counter = 0;
	while (in >> a >> b >> c) {
		if (a < b && b < c) counter++;
	}
	cout << counter << endl << endl;
}

/* Zadanie 2
Dla ka�dego wiersza wyznacz najwi�kszy wsp�lny dzielnik (NWD) tr�jki liczb w nim
zapisanych i podaj sum� tych dzielnik�w. 
*/

int nwd(int x, int y) {
	if (x < y) return nwd(y, x);
	if (y == 0) return x;
	return nwd(y, x % y);
}

void z2() {
	cout << "Zadanie 2:" << endl;
	ifstream in("liczby.txt");
	int a, b, c;
	int sum = 0;
	while (in >> a >> b >> c) {
		sum += nwd(nwd(a, b), nwd(b, c));
	}
	cout << sum << endl << endl;
}

/* Zadanie 3
Dla ka�dego wiersza oblicz sum� cyfr wszystkich liczb znajduj�cych si� w tym wierszu.
Podaj:
	� liczb� wierszy, dla kt�rych suma cyfr ze wszystkich trzech zapisanych liczb jest r�wna
	  35;
	  
	� najwi�ksz� sum� cyfr w wierszu oraz liczb� wierszy, w kt�rych suma cyfr r�wna jest
	  tej najwi�kszej warto�ci. 
*/

int sumOfNumbers(int a) {
	int sum = 0;
	while (a > 0) {
		sum += a % 10;
		a /= 10;
	}
	return sum;
}

void z3() {
	cout << "Zadanie 3:" << endl;
	ifstream in("liczby.txt");
	int a, b, c;
	int counter35 = 0;
	int sum, maxSum = 0, maxSumCounter = 0;
	while (in >> a >> b >> c) {
		sum = sumOfNumbers(a) + sumOfNumbers(b) + sumOfNumbers(c);
		if (sum == 35) counter35++;
		if (sum > maxSum) {
			maxSum = sum;
			maxSumCounter = 0;
		}
		if (sum == maxSum) maxSumCounter++;
	}
	cout << "Liczba wierszy z suma 35: " << counter35 << endl;
	cout << "Najwieksza suma cyfr: " << maxSum << endl;
	cout << "Ilosc wierszy z najwieksza suma: " << maxSumCounter << endl << endl;
}

int main() {
	z1();
	z2();
	z3();
}
