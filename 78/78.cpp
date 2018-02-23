#include <iostream>
#include <fstream>
using namespace std;

/* Tre��
https://cke.gov.pl/images/_EGZAMIN_MATURALNY_OD_2015/Materialy/Zbiory_zadan/Matura_Zbi%C3%B3r_zada%C5%84_Informatyka.pdf
Za d�uga do wklejenia

W pliku wiadomosci.txt znajduje si� 11 wiadomo�ci, ka�da w osobnym wierszu. Liczba
znak�w ka�dej wiadomo�ci nie przekracza 255. Wiadomo�ci zawieraj� znaki pojedynczego
odst�pu, kt�re s� integraln� cz�ci� informacji.

W pliku podpisy.txt znajduje si� 11 wierszy, ka�dy z nich zawiera 8 liczb ca�kowitych,
stanowi�cych elementy podpisu elektronicznego jednej wiadomo�ci. Liczby w wierszu oddzielone
s� pojedynczymi znakami odst�pu. Kolejno�� wierszy podpis�w jest zgodna z kolejno�ci�
wierszy wiadomo�ci (pierwszy wiersz podpis�w odpowiada pierwszej wiadomo�ci,
drugi � drugiej itd.) 
*/

/* Wyniki

*/

string skrot(string wiadomosc) {
	int S[8] = {'A','L','G','O','R','Y','T','M'};
	while (wiadomosc.length() % 8 != 0) {
		wiadomosc += '.';
	}
	
	// Do pierwszego zadania
	cout << wiadomosc.length() << endl; 
	
	int j = 0;
	for (int i = 0; i < wiadomosc.length(); i++) {
		S[j] = (S[j] + wiadomosc[i]) % 128;
		j++;
		if (j == 8) j = 0;
	}
	string wynik = "";
	
	// Do pierwszego zadania
	for (int i = 0; i < 8; i++) {
		cout << S[i] << " ";
	}
	cout << endl;
	
	for (int j = 0; j < 8; j++) {
		wynik = wynik + (char) (65 + S[j] % 26);
	}
	return wynik;
}

/* Zadanie 1
Wyznacz skr�t pierwszej wiadomo�ci z pliku wiadomosci.txt i udokumentuj wyniki
kolejnych etap�w obliczania tego skr�tu. Zapisz w kolejnych wierszach pliku wynikowego:
	a) liczb� znak�w wiadomo�ci po jej uzupe�nieniu do najmniejszej d�ugo�ci
o wielokrotno�ci 8 znak�w,
	b) warto�ci liczbowe 8 kolejnych bajt�w skr�tu (elementy tablicy S) po przetworzeniu
ca�ej wiadomo�ci � wszystkie warto�ci w jednym wierszu, oddzielone pojedynczymi
znakami odst�pu,
	c) skr�t wiadomo�ci w postaci napisu o d�ugo�ci 8, z�o�onego z wielkich liter alfabetu
angielskiego. 
*/

void z1() {
	cout << "Zadanie 1: " << endl;
	string s = "W sieci mozna udawac wszystko z wyjatkiem tego co sie naprawde liczy. Nie mozesz udawac inteligencji, poczucia humoru ani blyskotliwosci, zlosliwosci, przewrotnosci, ani calej reszty twojej paskudnej, fascynujacej osobowosci.";
	cout << skrot(s) << endl;
}

int main() {
	z1();
}
