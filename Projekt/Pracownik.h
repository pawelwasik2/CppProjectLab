#pragma once
#include "Data.h"
#include "Napis.h"
#include <iostream>

class Pracownik
{
	friend ostream & operator << (ostream & wy, const Pracownik & p);
	friend istream & operator >> (istream & we, Pracownik & p);
public:
	Pracownik(const Pracownik & wzor);
	Pracownik(const char* im = "", const char * naz = "", int dzien = 1, int miesiac = 1, int rok = 2000);
	~Pracownik();
private:
	Napis m_Imie;
	Napis m_Nazwisko;
	Data m_DataUrodzenia;
	int m_nIDZatrudnienia;
public:
	Pracownik & operator=(const Pracownik & wzor);
	bool operator==(const Pracownik & wzor) const;
	const char* Imie() const;
	const char* Nazwisko() const;
	void Imie(const char* nowe_imie);
	void Nazwisko(const char* nowe_nazwisko);
	void DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok);
	void Wypisz() const;
	void Wpisz();
	int SprawdzImie(const char* por_imie) const;
	int SprawdzNazwisko(const char* por_nazwisko) const;
	Pracownik* m_pNastepny;
	int Porownaj(const Pracownik &wzorzec) const;
};

