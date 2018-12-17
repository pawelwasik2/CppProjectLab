#pragma once
#include "Pracownik.h"
#include <fstream>
#include <conio.h>
#include <string>

class ListaPracownikow
{
public:
	ListaPracownikow();
	~ListaPracownikow();
private:
	Pracownik* m_pPoczatek;
	int m_nLiczbaPracownikow;
	//fstream file; //utworzenie pliku
public:
	void Dodaj(const Pracownik &p);
	void Usun(const Pracownik &wzorzec);
	void WypiszPracownikow() const;
	const Pracownik* Szukaj(const char* nazwisko, const char* imie) const;
	void ZapiszDoPliku(std::fstream &file);
	void WczytajZPliku(std::fstream &file);
};