#pragma once

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

using std::ostream;
using std::istream;

class Data
{
	friend ostream & operator << (ostream & wy, const Data & d);
	friend istream & operator >> (istream & we, Data & d);
public:
	Data(int d, int m, int r);
	~Data();
private:
	int m_nDzien;
	int m_nMiesiac;
	int m_nRok;

public:
	void Ustaw(int d, int m, int r);
	int Dzien() const;
	int Miesiac() const;
	int Rok() const;
	void Wypisz() const;
	void Wpisz();
	void Koryguj();
	int Porownaj(const Data & wzor) const;
};