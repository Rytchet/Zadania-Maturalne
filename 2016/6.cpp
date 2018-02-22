#include <iostream>
#include <fstream>
using namespace std;

/* Tre��
https://cke.gov.pl/images/_EGZAMIN_MATURALNY_OD_2015/Arkusze_egzaminacyjne/2016/formula_od_2015/MIN-R2_1P-162.pdf
Podstawieniowy szyfr Cezara z przesuni�ciem (kluczem) k polega na zast�pieniu ka�dego
znaku jawnego znakiem le��cym w alfabecie o k pozycji w prawo od zast�powanego znaku.
Przyk�ad: znak �B� po zakodowaniu kluczem k=3 zast�piony zostanie znakiem �E�. 
Przy szyfrowaniu znaku nale�y post�powa� w spos�b cykliczny, to znaczy, je�eli znak nie
posiada w alfabecie nast�pnika przesuni�tego o k pozycji, to alfabet �zawija si�" i za liter� Z
nast�puje zn�w litera A.
Przyk�ad: jawny znak �X� po zakodowaniu kluczem k=3 zast�piony zostanie znakiem �A�,
znak �Y� � znakiem �B�, natomiast �Z� � znakiem �C�. 
W tym zadaniu rozpatrujemy tylko s�owa zbudowane z wielkich liter alfabetu angielskiego
(o kodach ASCII odpowiednio od 65 do 90), o d�ugo�ciach nie wi�kszych ni� 30 znak�w. 
*/

/* Zadanie 1
W pliku dane_6_1.txt znajduje si� 100 s��w. S�owa umieszczono w osobnych wierszach.
Fragment pliku dane_6_1.txt:
INTERPRETOWANIE
ROZWESELANIE
KONSERWOWANIE
Napisz program, kt�ry zaszyfruje s�owa z pliku dane_6_1.txt z u�yciem klucza
k = 107. Wynik zapisz do pliku wyniki_6_1.txt, ka�de s�owo w osobnym wierszu,
w porz�dku odpowiadaj�cym kolejno�ci s��w z pliku z danymi.
Uwaga:
Dla pierwszego s�owa z pliku dane_6_1.txt (INTERPRETOWANIE) wynikiem jest
s�owo LQWHUSUHWRZDQLH. 
*/

string cipher(string s, int k) {
	int n;
	for (int i = 0; i < s.length(); i++) {
		n = (int) s[i]; // Zmiana typu bo char ma tylko 8 bit�w
		n -= 65;
		n += k;
		n %= 26;
		n += 65;
		s[i] = (char) n;
	}
	return s;
}

void z1() {
	ifstream in("dane_6_1.txt");
	// ofstream out("wyniki_6_1.txt", ios::app);
	string s, result;
	while (in >> s) {
		result = cipher(s, 107);
		// cout << result << endl;
		// out << result << endl;
	}
}

/* Zadanie 2
W pliku dane_6_2.txt zapisano 3 000 szyfrogram�w i odpowiadaj�ce im klucze
szyfruj�ce. W ka�dym wierszu znajduje si� jeden szyfrogram (zaszyfrowane s�owo)
i po pojedynczym znaku odst�pu odpowiadaj�cy mu klucz (maksymalnie czterocyfrowa
liczba). 
Fragment pliku dane_6_2.txt:
BCYKUNCM 1718
YFOGNSKGYW 7580
WARDA 9334 
Napisz program, kt�ry odszyfruje s�owa zaszyfrowane podanymi kluczami. Wynik zapisz
w pliku wyniki_6_2.txt: ka�de odszyfrowane s�owo w osobnym wierszu, w porz�dku
odpowiadaj�cym kolejno�ci szyfrogram�w z pliku z danymi. 
Dla pierwszego szyfrogramu z pliku dane_6_2.txt (BCYKUNCM) wynikiem jest s�owo
ZAWISLAK. 
*/

string decipher(string s, int k) {
	k = k % 26;
	k = 26 - k;
	return cipher(s, k);
}

void z2() {
	ifstream in("dane_6_2.txt");
	// ofstream out("wyniki_6_2.txt", ios::app);
	string s, result;
	int k;
	while (in >> s >> k) {
		result = decipher(s, k);
		// cout << result << endl;
		// out << result << endl;
	}
}

/* Zadanie 3
W pliku dane_6_3.txt zapisano 3 000 par s��w, po jednej parze w wierszu, oddzielonych
pojedynczym znakiem odst�pu. Drugie s�owo w ka�dej parze jest szyfrogramem pierwszego
z nieznanym kluczem.
Niekt�re szyfrogramy s� b��dne, co oznacza, �e niekt�re litery w s�owie zakodowano
z r�nymi przesuni�ciami. S�owo ma zawsze t� sam� d�ugo�� co odpowiadaj�cy
mu szyfrogram.
Fragment pliku dane_6_3.txt:
ZAWISLAK EFBNXQFP
KRASZEWSKI XENFMRJFXV
Napisz program, kt�ry wyszuka i wypisze te s�owa z pliku dane_6_3.txt, kt�re b��dnie
zaszyfrowano. Wynik zapisz w pliku wyniki_6_3.txt: ka�de s�owo w osobnym wierszu,
w porz�dku odpowiadaj�cym kolejno�ci tych s��w z pliku z danymi.
Uwaga:
Pierwsze s�owo w pliku wynikowym to SMIGIELSKI. 
*/

char cipher(char c, int k) {
	int n;
	n = (int) c;
	n -= 65;
	n += k;
	n %= 26;
	n += 65;
	c = (char) n;
	return c;
}

void z3() {
	ifstream in("dane_6_3.txt");
	// ofstream out("wyniki_6_3.txt");
	string s, c;
	int key;
	bool flag;
	while (in >> s >> c) {
		flag = false;
		if (s.length() != c.length()) flag = true;
		for (int i = 0; i < 26; i++) {
			if (cipher(s[0], i) == c[0]) key = i;
		}
		for (int i = 0; i < s.length(); i++) {
			if (cipher(s[i], key) != c[i]) flag = true;
		}
		if (flag) {
			// cout << s << endl;
			// out << s << endl;
		}
	}
}

int main() {
	z1();
	z2();
	z3();
}
