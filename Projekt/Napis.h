#pragma once
#include <string.h>
#include <iostream>

using std::ostream;
using std::istream;

class Napis
{
	friend ostream & operator <<(ostream & wy, const Napis & p);
	friend istream & operator >> (istream & we, Napis & p);
public:
	Napis(const char* nap = "");
	~Napis();
	Napis(const Napis & wzor);
	Napis & operator=(const Napis & wzor);
	bool operator==(const Napis & wzor) const;
private:
	char * m_pszNapis;
	int m_nDl;
public:
	const char* Zwroc() const;
	void Ustaw(const char* nowy_Napis);
	void Wypisz() const;
	void Wpisz();
	int SprawdzNapis(const char* por_napis) const;

};

