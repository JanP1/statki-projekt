#include <iostream>
#include <string>
#include <conio.h>
#include <ctime>
#include <random>
#include <set>
#include <cstdlib>

using namespace std;


void wypelnij0(int tab[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			tab[i][j] = 0;
		}
	}
}

void wypiszInt(int tab[10][10]) {
	cout << "      " << "0 1 2 3 4 5 6 7 8 9\n";
	for (int i = 0; i < 10; i++) {
		cout << "    " << i << " ";
		for (int j = 0; j < 10; j++) {
			cout << tab[i][j] << " ";
		}
		cout << endl;
	}
}

void wypiszChar(char tab[10][10]) {
	cout << "      " << "0 1 2 3 4 5 6 7 8 9\n";
	for (int i = 0; i < 10; i++) {
		cout << "    " << i << " ";
		for (int j = 0; j < 10; j++) {
			cout << tab[i][j] << " ";
		}
		cout << endl;
	}
}

void zamianaNaChar(int tab1[10][10], char tab2[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (tab1[i][j] == 0 || tab1[i][j] == 7) {
				tab2[i][j] = '-';
			}
			else
			{
				tab2[i][j] = 'x';
			}
		}
	}
}

//------Ustawianie statkow przez gracza------------------------

void rozmiescGracz(int tab[10][10], char tab2[10][10], int maszty)
{

	int zwrot;
	int kolumna;
	int wiersz;
	bool czyBlad = 0;
	int warunek = 0;
	while (warunek != maszty)
	{
		system("cls");

		zamianaNaChar(tab, tab2);
		cout << "\n\n";
		cout << "     ROZMIESC SWOJE STATKI\n\n";
		/*wypiszInt(tab);*/
		cout << endl;
		wypiszChar(tab2);
		cout << endl;

		if (czyBlad) {
			cout << "    ";
			cout << "---Sprobuj jeszcze raz---\n\n";
		}
		cout << "    ";
		if (maszty == 4) {
			cout << "Czteromasztowiec\n\n";
		}
		else if (maszty == 3)
		{
			cout << "Trojmasztowiec\n\n";
		}
		else if (maszty == 2)
		{
			cout << "Dwumasztowiec\n\n";
		}
		else if (maszty == 1) {
			cout << "Jednomasztowiec\n\n";
		}
		cout << "Podaj zwrot 0(gora) 1(prawo) 2(dol) 3(lewo): ";
		cin >> zwrot;

		cout << "Podaj wiersz: ";
		cin >> wiersz;
		cout << "Podaj kolumne: ";
		cin >> kolumna;

		if (zwrot < 0 || zwrot > 3 || wiersz < 0 || wiersz > 9 || kolumna < 0 || kolumna > 9) {
			czyBlad = 1;
			continue;

		}


		if (zwrot == 0 && wiersz - (maszty - 1) >= 0)
		{
			if (tab[wiersz + 1][kolumna] == 0 || tab[wiersz + 1][kolumna] == 7 || wiersz == 9) {
				for (int z0 = wiersz; z0 >= wiersz - (maszty - 1); z0--)
				{
					if (tab[z0][kolumna] == 0)
					{
						warunek++;

					}
				}
			}

		}
		else if (zwrot == 1 && kolumna + (maszty - 1) <= 9)
		{
			if (tab[wiersz][kolumna - 1] == 0 || tab[wiersz][kolumna - 1] == 7 || kolumna == 0) {
				for (int z1 = kolumna; z1 <= kolumna + (maszty - 1); z1++)
				{
					if (tab[wiersz][z1] == 0)
					{
						warunek++;
					}
				}
			}

		}
		else if (zwrot == 2 && wiersz + (maszty - 1) <= 9)
		{
			if (tab[wiersz - 1][kolumna] == 0 || tab[wiersz - 1][kolumna] == 7 || wiersz == 0) {
				for (int z2 = wiersz; z2 <= wiersz + (maszty - 1); z2++)
				{
					if (tab[z2][kolumna] == 0)
					{
						warunek++;
					}
				}
			}
		}
		else if (zwrot == 3 && kolumna - (maszty - 1) >= 0)
		{
			if (tab[wiersz][kolumna + 1] == 0 || tab[wiersz][kolumna + 1] == 7 || kolumna == 9) {
				for (int z3 = kolumna; z3 >= kolumna - (maszty - 1); z3--)
				{
					if (tab[wiersz][z3] == 0)
					{
						warunek++;
					}
				}
			}

		}
		else
		{
			warunek = 0;
		}
		czyBlad = 1;
	}



	//wypelnienie numerami dla zwrot 0
	if (zwrot == 0) {
		if (wiersz - maszty >= 0) { tab[wiersz - maszty][kolumna] = 7; }
		if (kolumna != 9) {
			if (wiersz - maszty >= 0) { tab[wiersz - maszty][kolumna + 1] = 7; }
			if (wiersz + 1 <= 9) { tab[wiersz + 1][kolumna + 1] = 7; }
		}
		if (kolumna != 0) {
			if (wiersz - maszty >= 0) { tab[wiersz - maszty][kolumna - 1] = 7; }
			if (wiersz + 1 <= 9) { tab[wiersz + 1][kolumna - 1] = 7; }
		}
		if ((wiersz + 1) <= 9) { tab[wiersz + 1][kolumna] = 7; }


		// jezeli stoi na 0 lub 9 to nie wypelnia prawej lub lewej strony
		for (int n0 = wiersz; n0 >= wiersz - (maszty - 1); n0--) {
			tab[n0][kolumna] = maszty;
			if (kolumna != 9) { tab[n0][kolumna + 1] = 7; }
			if (kolumna != 0) { tab[n0][kolumna - 1] = 7; }
		}
	}
	// zwrot 1
	else if (zwrot == 1) {
		if ((kolumna + maszty) <= 9) {

			tab[wiersz][kolumna + maszty] = 7;

			if (wiersz != 9) { tab[wiersz + 1][kolumna + maszty] = 7; }
			if (wiersz != 0) { tab[wiersz - 1][kolumna + maszty] = 7; }
		}
		if ((kolumna - 1) >= 0) {
			tab[wiersz][kolumna - 1] = 7;
			if (wiersz != 9) { tab[wiersz + 1][kolumna - 1] = 7; }
			if (wiersz != 0) { tab[wiersz - 1][kolumna - 1] = 7; }
		}
		for (int n1 = kolumna; n1 <= kolumna + (maszty - 1); n1++) {
			tab[wiersz][n1] = maszty;
			if ((wiersz + 1) <= 9) { tab[wiersz + 1][n1] = 7; }
			if ((wiersz - 1) >= 0) { tab[wiersz - 1][n1] = 7; }
		}
	}
	//zwrot 2
	else if (zwrot == 2) {
		if ((wiersz + maszty) <= 9) { tab[wiersz + maszty][kolumna] = 7; }
		if ((wiersz - 1) >= 0) { tab[wiersz - 1][kolumna] = 7; }

		if (kolumna != 9) {
			if (wiersz + maszty <= 9) { tab[wiersz + maszty][kolumna + 1] = 7; }
			if (wiersz - 1 >= 0) { tab[wiersz - 1][kolumna + 1] = 7; }
		}
		if (kolumna != 0) {
			if (wiersz + maszty <= 9) { tab[wiersz + maszty][kolumna - 1] = 7; }
			if (wiersz - 1 >= 0) { tab[wiersz - 1][kolumna - 1] = 7; }
		}
		if ((wiersz - 1) >= 0) { tab[wiersz - 1][kolumna] = 7; }


		for (int n2 = wiersz; n2 <= wiersz + (maszty - 1); n2++) {
			tab[n2][kolumna] = maszty;
			if (kolumna != 9) { tab[n2][kolumna + 1] = 7; }
			if (kolumna != 0) { tab[n2][kolumna - 1] = 7; }
		}
	}
	//zwrot 3
	else if (zwrot == 3) {
		if ((kolumna + 1) <= 9) {
			tab[wiersz][kolumna + 1] = 7;
			if (wiersz + 1 <= 9) { tab[wiersz + 1][kolumna + 1] = 7; }
			if (wiersz - 1 >= 0) { tab[wiersz - 1][kolumna + 1] = 7; }
		}
		if ((kolumna - maszty) >= 0) {
			tab[wiersz][kolumna - maszty] = 7;
			if (wiersz + 1 <= 9) { tab[wiersz + 1][kolumna - maszty] = 7; }
			if (wiersz - 1 >= 0) { tab[wiersz - 1][kolumna - maszty] = 7; }
		}
		for (int n3 = kolumna; n3 >= kolumna - (maszty - 1); n3--) {
			tab[wiersz][n3] = maszty;
			tab[wiersz - 1][n3] = 7;
			tab[wiersz + 1][n3] = 7;
		}
	}


}

void ustawStatkiG(int tab1[10][10], char tab2[10][10])
{
	wypelnij0(tab1);
	rozmiescGracz(tab1, tab2, 4);
	rozmiescGracz(tab1, tab2, 3);
	rozmiescGracz(tab1, tab2, 3);
	rozmiescGracz(tab1, tab2, 2);
	rozmiescGracz(tab1, tab2, 2);
	rozmiescGracz(tab1, tab2, 2);
	rozmiescGracz(tab1, tab2, 1);
	rozmiescGracz(tab1, tab2, 1);
	rozmiescGracz(tab1, tab2, 1);
	rozmiescGracz(tab1, tab2, 1);

	system("cls");
	zamianaNaChar(tab1, tab2);
	//wypiszInt(tab1);
	cout << "\n\n\n     Rozmieszczono statki\n\n\n" << endl;
	wypiszChar(tab2);
	system("pause");
	system("cls");




}

//-------------------------------------------------------------

//---------Rozmieszczenie statkow (komputer)-------------------

void ustawStatki(int tab[10][10], int maszty)
{
	mt19937 komorki(time(nullptr));
	uniform_int_distribution <int> rKomorki(0, 9);
	mt19937 kierunek(time(nullptr));
	uniform_int_distribution <int> rKierunek(0, 3);

	int zwrot = rKierunek(kierunek);
	int kolumna = rKomorki(komorki);
	int wiersz = rKomorki(komorki);

	int warunek = 0;
	while (warunek != maszty)
	{
		zwrot = rKierunek(kierunek);
		kolumna = rKomorki(komorki);
		wiersz = rKomorki(komorki);

		/*cout << "zwrot  "<< zwrot << endl;
		cout << "wiersz  " << wiersz << endl;
		cout << "kolumna  " << kolumna << endl;
		cout << endl;*/

		if (zwrot == 0 && wiersz - (maszty - 1) >= 0)
		{
			if (tab[wiersz + 1][kolumna] == 0 || tab[wiersz + 1][kolumna] == 7 || wiersz == 9) {
				for (int z0 = wiersz; z0 >= wiersz - (maszty - 1); z0--)
				{
					if (tab[z0][kolumna] == 0)
					{
						warunek++;

					}
				}
			}

		}
		else if (zwrot == 1 && kolumna + (maszty - 1) <= 9)
		{
			if (tab[wiersz][kolumna - 1] == 0 || tab[wiersz][kolumna - 1] == 7 || kolumna == 0) {
				for (int z1 = kolumna; z1 <= kolumna + (maszty - 1); z1++)
				{
					if (tab[wiersz][z1] == 0)
					{
						warunek++;
					}
				}
			}

		}
		else if (zwrot == 2 && wiersz + (maszty - 1) <= 9)
		{
			if (tab[wiersz - 1][kolumna] == 0 || tab[wiersz - 1][kolumna] == 7 || wiersz == 0) {
				for (int z2 = wiersz; z2 <= wiersz + (maszty - 1); z2++)
				{
					if (tab[z2][kolumna] == 0)
					{
						warunek++;
					}
				}
			}
		}
		else if (zwrot == 3 && kolumna - (maszty - 1) >= 0)
		{
			if (tab[wiersz][kolumna + 1] == 0 || tab[wiersz][kolumna + 1] == 7 || kolumna == 9) {
				for (int z3 = kolumna; z3 >= kolumna - (maszty - 1); z3--)
				{
					if (tab[wiersz][z3] == 0)
					{
						warunek++;
					}
				}
			}

		}
		else
		{
			warunek = 0;
		}

	}



	//wypelnienie numerami dla zwrot 0
	if (zwrot == 0) {
		if (wiersz - maszty >= 0) { tab[wiersz - maszty][kolumna] = 7; }
		if (kolumna != 9) {
			if (wiersz - maszty >= 0) { tab[wiersz - maszty][kolumna + 1] = 7; }
			if (wiersz + 1 <= 9) { tab[wiersz + 1][kolumna + 1] = 7; }
		}
		if (kolumna != 0) {
			if (wiersz - maszty >= 0) { tab[wiersz - maszty][kolumna - 1] = 7; }
			if (wiersz + 1 <= 9) { tab[wiersz + 1][kolumna - 1] = 7; }
		}
		if ((wiersz + 1) <= 9) { tab[wiersz + 1][kolumna] = 7; }


		// jezeli stoi na 0 lub 9 to nie wypelnia prawej lub lewej strony
		for (int n0 = wiersz; n0 >= wiersz - (maszty - 1); n0--) {
			tab[n0][kolumna] = maszty;
			if (kolumna != 9) { tab[n0][kolumna + 1] = 7; }
			if (kolumna != 0) { tab[n0][kolumna - 1] = 7; }
		}
	}
	// zwrot 1
	else if (zwrot == 1) {
		if ((kolumna + maszty) <= 9) {

			tab[wiersz][kolumna + maszty] = 7;

			if (wiersz != 9) { tab[wiersz + 1][kolumna + maszty] = 7; }
			if (wiersz != 0) { tab[wiersz - 1][kolumna + maszty] = 7; }
		}
		if ((kolumna - 1) >= 0) {
			tab[wiersz][kolumna - 1] = 7;
			if (wiersz != 9) { tab[wiersz + 1][kolumna - 1] = 7; }
			if (wiersz != 0) { tab[wiersz - 1][kolumna - 1] = 7; }
		}
		for (int n1 = kolumna; n1 <= kolumna + (maszty - 1); n1++) {
			tab[wiersz][n1] = maszty;
			if ((wiersz + 1) <= 9) { tab[wiersz + 1][n1] = 7; }
			if ((wiersz - 1) >= 0) { tab[wiersz - 1][n1] = 7; }
		}
	}
	//zwrot 2
	else if (zwrot == 2) {
		if ((wiersz + maszty) <= 9) { tab[wiersz + maszty][kolumna] = 7; }
		if ((wiersz - 1) >= 0) { tab[wiersz - 1][kolumna] = 7; }

		if (kolumna != 9) {
			if (wiersz + maszty <= 9) { tab[wiersz + maszty][kolumna + 1] = 7; }
			if (wiersz - 1 >= 0) { tab[wiersz - 1][kolumna + 1] = 7; }
		}
		if (kolumna != 0) {
			if (wiersz + maszty <= 9) { tab[wiersz + maszty][kolumna - 1] = 7; }
			if (wiersz - 1 >= 0) { tab[wiersz - 1][kolumna - 1] = 7; }
		}
		if ((wiersz - 1) >= 0) { tab[wiersz - 1][kolumna] = 7; }


		for (int n2 = wiersz; n2 <= wiersz + (maszty - 1); n2++) {
			tab[n2][kolumna] = maszty;
			if (kolumna != 9) { tab[n2][kolumna + 1] = 7; }
			if (kolumna != 0) { tab[n2][kolumna - 1] = 7; }
		}
	}
	//zwrot 3
	else if (zwrot == 3) {
		if ((kolumna + 1) <= 9) {
			tab[wiersz][kolumna + 1] = 7;
			if (wiersz + 1 <= 9) { tab[wiersz + 1][kolumna + 1] = 7; }
			if (wiersz - 1 >= 0) { tab[wiersz - 1][kolumna + 1] = 7; }
		}
		if ((kolumna - maszty) >= 0) {
			tab[wiersz][kolumna - maszty] = 7;
			if (wiersz + 1 <= 9) { tab[wiersz + 1][kolumna - maszty] = 7; }
			if (wiersz - 1 >= 0) { tab[wiersz - 1][kolumna - maszty] = 7; }
		}
		for (int n3 = kolumna; n3 >= kolumna - (maszty - 1); n3--) {
			tab[wiersz][n3] = maszty;
			tab[wiersz - 1][n3] = 7;
			tab[wiersz + 1][n3] = 7;
		}
	}

	/*cout << "maszty " << maszty << endl;
	cout << "zwrot  " << zwrot << endl;
	cout << "wiersz  " << wiersz << endl;
	cout << "kolumna  " << kolumna << endl;
	cout << endl;*/
}

void rozmiescStatki(int tab[10][10])
{
	char tab2[10][10] = {};

	//wypelnia zerami
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			tab[i][j] = 0;
		}
	}
	//wypelnia '-'
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			tab2[i][j] = '-';
		}
	}


	ustawStatki(tab, 4);
	ustawStatki(tab, 3);ustawStatki(tab, 3);
	ustawStatki(tab, 2);ustawStatki(tab, 2);ustawStatki(tab, 2);
	ustawStatki(tab, 1);ustawStatki(tab, 1);ustawStatki(tab, 1);ustawStatki(tab, 1);

	// zmienia - na x 
	for (int a = 0; a < 10; a++) {
		for (int b = 0; b < 10; b++) {
			if (tab[a][b] > 0 && tab[a][b] != 7) {
				tab2[a][b] = 'x';
			}
		}
	}

	//wypisanie tablicy numerowo
	/*for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << tab[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;*/

	//wypisanie tablicy graficznie
	/*cout << " \n\n";
	for (int i = 0; i < 10; i++) {
		cout << "        ";
		for (int j = 0; j < 10; j++) {
			cout << tab2[i][j] << " ";
		}
		cout << endl;
	}*/
}

//-------------------------------------------------------------

void rysujChar(char tab[10][10]) {
	cout << " \n\n";
	cout << "         0 1 2 3 4 5 6 7 8 9\n\n";
	for (int i = 0; i < 10; i++) {
		cout << "     " << i << "   ";
		for (int j = 0; j < 10; j++) {
			cout << tab[i][j] << " ";
		}
		cout << endl;
	}
}

void pustyRys(char tab[10][10]) {
	//wypelnia '-'
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			tab[i][j] = '-';
		}
	}
}

void menu() {
	system("cls");
	cout << " \n\n\n\n\n\n";
	cout.width(60);
	cout << "STATKI";
	cout << "\n\n\n";
	cout.width(60);
	cout << "Aby rozpoczac nowa gre nacisnij [S] \n\n";
	cout.width(60);
	cout << "Powrot do menu nacisnij [M] \n\n";
	cout.width(58);
	cout << "Aby zakonczyc nacisnij [E] ";
	cout << "\n\n\n\n";
}

//-----------------Strzal------------------------------------


string strzalyNaString(int wiersz, int kolumna, string strzal) {
	if (wiersz == 0 && kolumna == 0) {
		strzal = "00";
	}
	if (wiersz == 0 && kolumna != 0) {
		strzal = "";
		strzal = "0";
		strzal += to_string(kolumna);
	}
	if (wiersz != 0 && kolumna == 0) {
		strzal = "";
		strzal = to_string(wiersz);
		strzal += "0";
	}
	if (wiersz != 0 && kolumna != 0) {
		strzal = "";
		strzal += to_string(wiersz);
		strzal += to_string(kolumna);

	}
	return strzal;

}

void strzalGracz(set<string> strzalyGracz, char mojeStrzaly[10][10], int tablica[10][10], int *ileZatopionych) {
	
	int wiersz, kolumna;
	int warunek1;
	int a = 0;
	while (a == 0) {
		rysujChar(mojeStrzaly);
		//wypiszInt(tablica);
		warunek1 = 0;
		while (warunek1 == 0) {

			cout << "\nPodaj wiersz => ";
			cin >> wiersz;

			while (wiersz > 9 || wiersz < 0)
			{
				cout << "Sprobuj ponownie => ";
				cin >> wiersz;
			}
			cout << "Podaj kolumne => ";
			cin >> kolumna;
			while (kolumna > 9 || kolumna < 0)
			{
				cout << "Sprobuj ponownie => ";
				cin >> kolumna;
			}

			string strzal;
			

			string gdzieStrzelil = strzalyNaString(wiersz, kolumna, strzal);

			int czyPonownie = 0;

			for (auto i = strzalyGracz.begin(); i != strzalyGracz.end(); ++i) {
				if (*i == gdzieStrzelil) {
					czyPonownie = 1;
				}

			}
			if (czyPonownie == 1)
			{
				warunek1 = 0;
				system("cls");
				rysujChar(mojeStrzaly);
				cout << "\nJuz tu strzelales. Sprobuj ponownie. \n\n";
			}
			else
			{
				strzalyGracz.insert(gdzieStrzelil);
				warunek1 = 1;
			}


		}
		bool czyTr = 0;
		bool czyZatopiony = 0;
		if (tablica[wiersz][kolumna] == 0 || tablica[wiersz][kolumna] == 7)
		{
			mojeStrzaly[wiersz][kolumna] = 'o';
			czyTr = 0;
			a = 1;
		}
		else
		{
			mojeStrzaly[wiersz][kolumna] = 'x';

			//tutaj sprawdza czy zatopiony

			int numer = tablica[wiersz][kolumna];

			int licznikTrafien = 0;
			int wierszP = wiersz;//wiersz poczatkowy
			int kolP = kolumna; // kolumnaPoczatek

			if (wiersz != 9 && wiersz != 0) {
				if (tablica[wiersz + 1][kolumna] == 7 && tablica[wiersz - 1][kolumna] == 7) {

					while (tablica[wiersz][kolP] == numer)
					{
						if (kolP == 9) {
							break;
						}
						kolP++;
					}
					if (tablica[wiersz][kolP] == 7) {
						kolP--;

					}

					while (tablica[wiersz][kolP] == numer)
					{
						if (mojeStrzaly[wiersz][kolP] == 'x') {
							licznikTrafien++;
						}
						kolP--;
					}
					if (licznikTrafien == numer) {
						czyZatopiony = 1;

					}
				}
			}

			if (kolumna != 9 && kolumna != 0) {
				if (tablica[wiersz][kolumna + 1] == 7 && tablica[wiersz][kolumna - 1] == 7)
				{


					while (tablica[wierszP][kolumna] == numer)
					{
						if (wierszP == 9) {
							break;
						}
						wierszP++;
					}
					if (tablica[wierszP][kolumna] == 7) {
						wierszP--;
					}


					while (tablica[wierszP][kolumna] == numer)
					{
						if (mojeStrzaly[wierszP][kolumna] == 'x') {
							licznikTrafien++;
						}
						wierszP--;
					}
					if (licznikTrafien == numer) {
						czyZatopiony = 1;

					}
				}
			}

			if ((kolumna == 0 && tablica[wiersz][kolumna + 1] == 7) || (kolumna == 9 && tablica[wiersz][kolumna - 1] == 7)) {
				while (tablica[wierszP][kolumna] == numer) {
					while (tablica[wierszP][kolumna] == numer)
					{
						if (wierszP == 9) {
							break;
						}
						wierszP++;
					}
					if (tablica[wierszP][kolumna] == 7) {
						wierszP--;
					}


					while (tablica[wierszP][kolumna] == numer)
					{
						if (mojeStrzaly[wierszP][kolumna] == 'x') {
							licznikTrafien++;
						}
						wierszP--;
					}
					if (licznikTrafien == numer) {
						czyZatopiony = 1;

					}
				}
			}

			if ((wiersz == 0 && tablica[wiersz + 1][kolumna] == 7) || (wiersz == 9 && tablica[wiersz - 1][kolumna] == 7)) {
				while (tablica[wiersz][kolP] == numer)
				{
					if (kolP == 9) {
						break;
					}
					kolP++;
				}
				if (tablica[wiersz][kolP] == 7) {
					kolP--;

				}

				while (tablica[wiersz][kolP] == numer)
				{
					if (mojeStrzaly[wiersz][kolP] == 'x') {
						licznikTrafien++;
					}
					kolP--;
				}
				if (licznikTrafien == numer) {
					czyZatopiony = 1;

				}
			}

			czyTr = 1;




		}



		system("cls");
		rysujChar(mojeStrzaly);
		if (czyTr) {
			if (czyZatopiony == 0) {
				cout << "\n\n\n  ------------Trafiony----------\n\n";

			}
			else
			{
				*ileZatopionych += 1;
				if (*ileZatopionych < 10) {
					cout << "\n\n\n  ------------Zatopiony----------\n\n";
					czyZatopiony = 0;
				}
				else
				{
					system("cls");
					cout << "\n\n\n             Zwyciestwo     \n\n\n  Powrot do menu [M]";
				}
			}
		}
		else
		{
			cout << "\n\n\n  -------------Pudlo-----------\n\n";
		}


		system("pause");
		system("cls");
	}
}


void strzalBot(set<string> strzalyGracz, char mojeStrzaly[10][10], int tablica[10][10], int *ileZatopionych, char wizualnieBot[10][10]) {
	
	


	int kolumnaBot = 0;
	int wierszBot = 0;

	

	int wiersz, kolumna;
	int warunek1;
	int a = 0;
	
	while (a == 0) {
		
		warunek1 = 0;
		while (warunek1 == 0) {
			
			srand(time(0));

			wierszBot = rand() % 10;
			kolumnaBot = rand() % 10;

			string strBot = "";


			strBot += to_string(wierszBot);
			strBot += to_string(kolumnaBot);
			

			int czyPonownie = 0;

			for (auto i = strzalyGracz.begin(); i != strzalyGracz.end(); ++i) {
				if (*i == strBot) {
					czyPonownie = 1;
				}

			}
			if (czyPonownie == 1)
			{
				warunek1 = 0;
			}
			else
			{
				strzalyGracz.insert(strBot);
				warunek1 = 1;
				cout << "\n\n          Wspolrzedne: (" << wierszBot << ", " << kolumnaBot << " )";
				system("pause");
			}


		}
		kolumna = kolumnaBot;
		wiersz = wierszBot;

		bool czyTr = 0;
		bool czyZatopiony = 0;
		if (tablica[wiersz][kolumna] == 0 || tablica[wiersz][kolumna] == 7)
		{
			mojeStrzaly[wiersz][kolumna] = 'o';
			czyTr = 0;
			a = 1;
			wizualnieBot[wiersz][kolumna] = 'o';
		}
		else
		{
			mojeStrzaly[wiersz][kolumna] = 'x';
			wizualnieBot[wiersz][kolumna] = '#';

			//tutaj sprawdza czy zatopiony

			int numer = tablica[wiersz][kolumna];

			int licznikTrafien = 0;
			int wierszP = wiersz;//wiersz poczatkowy
			int kolP = kolumna; // kolumnaPoczatek

			if (wiersz != 9 && wiersz != 0) {
				if (tablica[wiersz + 1][kolumna] == 7 && tablica[wiersz - 1][kolumna] == 7) {

					while (tablica[wiersz][kolP] == numer)
					{
						if (kolP == 9) {
							break;
						}
						kolP++;
					}
					if (tablica[wiersz][kolP] == 7) {
						kolP--;

					}

					while (tablica[wiersz][kolP] == numer)
					{
						if (mojeStrzaly[wiersz][kolP] == 'x') {
							licznikTrafien++;
						}
						kolP--;
					}
					if (licznikTrafien == numer) {
						czyZatopiony = 1;

					}
				}
			}

			if (kolumna != 9 && kolumna != 0) {
				if (tablica[wiersz][kolumna + 1] == 7 && tablica[wiersz][kolumna - 1] == 7)
				{


					while (tablica[wierszP][kolumna] == numer)
					{
						if (wierszP == 9) {
							break;
						}
						wierszP++;
					}
					if (tablica[wierszP][kolumna] == 7) {
						wierszP--;
					}


					while (tablica[wierszP][kolumna] == numer)
					{
						if (mojeStrzaly[wierszP][kolumna] == 'x') {
							licznikTrafien++;
						}
						wierszP--;
					}
					if (licznikTrafien == numer) {
						czyZatopiony = 1;

					}
				}
			}

			if ((kolumna == 0 && tablica[wiersz][kolumna + 1] == 7) || (kolumna == 9 && tablica[wiersz][kolumna - 1] == 7)) {
				while (tablica[wierszP][kolumna] == numer) {
					while (tablica[wierszP][kolumna] == numer)
					{
						if (wierszP == 9) {
							break;
						}
						wierszP++;
					}
					if (tablica[wierszP][kolumna] == 7) {
						wierszP--;
					}


					while (tablica[wierszP][kolumna] == numer)
					{
						if (mojeStrzaly[wierszP][kolumna] == 'x') {
							licznikTrafien++;
						}
						wierszP--;
					}
					if (licznikTrafien == numer) {
						czyZatopiony = 1;

					}
				}
			}

			if ((wiersz == 0 && tablica[wiersz + 1][kolumna] == 7) || (wiersz == 9 && tablica[wiersz - 1][kolumna] == 7)) {
				while (tablica[wiersz][kolP] == numer)
				{
					if (kolP == 9) {
						break;
					}
					kolP++;
				}
				if (tablica[wiersz][kolP] == 7) {
					kolP--;

				}

				while (tablica[wiersz][kolP] == numer)
				{
					if (mojeStrzaly[wiersz][kolP] == 'x') {
						licznikTrafien++;
					}
					kolP--;
				}
				if (licznikTrafien == numer) {
					czyZatopiony = 1;

				}
			}

			czyTr = 1;




		}



		system("cls");
		rysujChar(wizualnieBot);
		if (czyTr) {
			if (czyZatopiony == 0) {
				cout << "\n\n\n  ------------Trafiony----------\n\n";

			}
			else
			{
				*ileZatopionych += 1;
				if (*ileZatopionych < 10) {
					cout << "\n\n\n  ------------Zatopiony----------\n\n";
					czyZatopiony = 0;
				}
				else
				{
					system("cls");
					cout << "\n\n\n             Przegrana     \n\n\n  Powrot do menu [M]";
				}
			}
		}
		else
		{
			cout << "\n\n\n  -------------Pudlo-----------\n\n";
		}


		system("pause");
		system("cls");
	}
}



//-----------------------------------------------------------

void kopia(char a[10][10], char b[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			b[i][j] = a[i][j];
		}
	}
}

void gra()
{
	int lZatGracz = 0;
	int lZatBot = 0;
	int* gW = &lZatGracz;
	int* bW = &lZatBot;

	int ileStatkow = 10;

	char strzalyBota[10][10];
	char wizualnieBot[10][10];
	int wierszBot, kolumnaBot;
	int tabBotInt[10][10];
	char tabStrzalyGraczaChar[10][10];
	int tabGraczInt[10][10];
	char tabGraczChar[10][10];

	set<string> strzalyBotSet;
	set<string> strzalyGraczSet;

	pustyRys(tabStrzalyGraczaChar);

	strzalyBotSet.clear();
	strzalyGraczSet.clear();

	system("cls");
	rozmiescStatki(tabBotInt);
	ustawStatkiG(tabGraczInt, tabGraczChar);

	kopia(tabGraczChar, wizualnieBot);

	int licznik = 2;
	while (lZatBot < 10 && lZatGracz < 10) {
		if (licznik % 2 == 0) {
			strzalGracz(strzalyGraczSet, tabStrzalyGraczaChar, tabBotInt, gW);
			licznik--;
		}
		else
		{
			strzalBot(strzalyBotSet, strzalyBota, tabGraczInt, bW, wizualnieBot);
			licznik++;
		}

	}

	


}

int main()
{



	bool czyGra = 0;

	menu();

	char c;


	int a = 1;
	while (a == 1) {
		c = _getch();
		if (c == 'e')
		{
			//----------------wyjscie z gry------------
			system("cls");
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\nNacisnij dowolny przycisk\n\n\n\n\n\n\n\n";
			break;
		}
		if (c == 's' && czyGra == 0) {
			//-----------------start-----------------
			czyGra = 1;
			gra();


		}
		if (c == 'm') {
			//----------------powrot do menu-----------
			menu();
			czyGra = 0;
		}
	}


}


