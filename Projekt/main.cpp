#include <iostream>
#include "Napis.h"
#include "Pracownik.h"
#include "Data.h"
#include "ListaPracownikow.h"
#include <cstdlib>
#include <fstream>

using namespace std;


fstream file; //utworzenie pliku
Pracownik pr;
ListaPracownikow Lista;
Napis imie, nazwisko; // do szukania

int main()
{

	while (1)
	{
		cout << "************************\n";
		cout << "**********MENU**********\n";
		cout << "************************\n";
		cout << "*****WYBIERZ OPCJE******\n";
		cout << "0 Wyjscie z programu\n";
		cout << "1 Dodaj pracownika\n";
		cout << "2 Usun Pracownika\n";
		cout << "3 Wyswietl Pracownikow\n";
		cout << "4 Szukaj pracownika\n";
		cout << "5 Zapisz do pliku\n";
		cout << "6 Odczytaj z pliku\n";
		int a;
		cin >> a;
		switch (a) {
		case 0:
			break;
		case 1:
			system("cls");
			cin >> pr;
			Lista.Dodaj(pr);
			system("pause");
			break;
		case 2:
			system("cls");
			cout << "Podaj dane pracownika: " << endl;
			cin >> pr;
			Lista.Usun(pr);
			system("pause");
			break;
		case 3:
			system("cls");
			Lista.WypiszPracownikow();
			system("pause");
			break;
		case 4:
			{
			system("cls");
			cout << "Podaj imie i nazwisko pracownika ktorego szukasz: ";
			cin >> imie >> nazwisko;
			const Pracownik* x = Lista.Szukaj(nazwisko.Zwroc(), imie.Zwroc());
			if (x != NULL) {
				cout << *x;
			}
			else {
				cout << "Brak pracownika na liscie";
			}
			system("pause");
			}
			break;
		case 5:
			system("cls");
			Lista.ZapiszDoPliku(file);
			system("pause");
			break;
		case 6:
			system("cls");
			Lista.WczytajZPliku(file);
			system("pause");
			break;
		}
	}
}