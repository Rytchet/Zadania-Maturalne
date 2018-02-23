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
Zadanie 1:
232
12 94 94 57 96 115 51 90
MQQFSLZM

Zadanie 2:
MQQFSLZM
WWXRFKEC
UAQFAKQN
WVTFWMLI
WMXQBVTU
IRCEIIDN
DLGULFST
UIZVEUSE
DMWHUXTH
UFHRHSXM
TFUKGFXW

Zadanie 3:
1
3
4
8
9
11
*/

bool zadaniePierwsze = true;

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

string skrot(string wiadomosc) {
	int S[8] = {'A','L','G','O','R','Y','T','M'};
	while (wiadomosc.length() % 8 != 0) {
		wiadomosc += '.';
	}
	
	if (zadaniePierwsze) cout << wiadomosc.length() << endl; 
	
	int j = 0;
	for (int i = 0; i < wiadomosc.length(); i++) {
		S[j] = (S[j] + wiadomosc[i]) % 128;
		j++;
		if (j == 8) j = 0;
	}
	string wynik = "";
	
	if (zadaniePierwsze) {
		for (int i = 0; i < 8; i++) {
			cout << S[i] << " ";
		}
		cout << endl;
	}
	
	for (int j = 0; j < 8; j++) {
		wynik = wynik + (char) (65 + S[j] % 26);
	}
	return wynik;
}



void z1() {
	cout << "Zadanie 1: " << endl;
	ifstream in("wiadomosci.txt");
	string s;
	getline(in, s);
	cout << skrot(s) << endl << endl;
	zadaniePierwsze = false;
}

/* Zadanie 2
Odszyfruj skr�ty wiadomo�ci ze wszystkich podpis�w elektronicznych umieszczonych
w pliku podpisy.txt, stosuj�c algorytm A z kluczem publicznym (d,n) = (3,200). Zapisz
uzyskane skr�ty w kolejnych, osobnych wierszach pliku z odpowiedziami. 
*/

string odszyfrujSkrot(int tab[], int d, int n) {
	string ans = "";
	for (int i = 0; i < 8; i++) {
		tab[i] = (tab[i] * 3 % 200);
		ans += (char) tab[i];
	}
	return ans;
}

void z2() {
	cout << "Zadanie 2:" << endl;
	ifstream in("podpisy.txt");
	int tab[8];
	string ans;
	for (int q = 0; q < 11; q++) { // 11 kluczy w pliku
		for (int i = 0; i < 8; i++) {
			in >> tab[i];
		}
		ans = odszyfrujSkrot(tab, 3, 200);
		cout << ans << endl;
	}
	cout << endl;
}

/* Zadanie 3
Zweryfikuj wiarygodno�� wszystkich wiadomo�ci i podaj numery wiadomo�ci wiarygodnych.
Zapisz w jednym wierszu pliku z odpowiedziami, jako liczby z zakresu 1..11, zgodnie z kolejno�ci�
umieszczenia ich w pliku danych, oddzielone pojedynczym znakiem odst�pu. 
*/

void z3() {
	cout << "Zadanie 3:" << endl;
	ifstream inWiadomosc("wiadomosci.txt");
	ifstream inPodpis("podpisy.txt");
	string wiadomosc;
	int tab[8];
	for (int i = 0; i < 11; i++) {
		getline(inWiadomosc, wiadomosc);
		for (int j = 0; j < 8; j++) inPodpis >> tab[j];
		if (skrot(wiadomosc) == odszyfrujSkrot(tab, 3, 200)) cout << i + 1 << endl;
	}
	cout << endl;
}

int main() {
	z1();
	z2();
	z3();
}
