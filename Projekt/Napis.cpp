#include "Napis.h"

#pragma warning(disable : 4996)

using std::cout;
using std::cin;

Napis::Napis(const char * nap)
{
	m_nDl = strlen(nap);
	m_pszNapis = new char[m_nDl];
	Ustaw(nap);
}

Napis::~Napis()
{
	m_pszNapis = 0;
}

Napis::Napis(const Napis & wzor)
{
	m_pszNapis = new char[strlen(wzor.m_pszNapis) + 1];
	strcpy(m_pszNapis, wzor.m_pszNapis + 1);
}

Napis & Napis::operator=(const Napis & wzor)
{
	if (this != &wzor)
	{
		m_pszNapis = new char(strlen(wzor.m_pszNapis) + 1);
		strcpy(m_pszNapis, wzor.m_pszNapis);

	}
	return *this;
}

bool Napis::operator==(const Napis & wzor) const
{
	if (SprawdzNapis(wzor.m_pszNapis) == 0)
	{
		return true;
	}
	else
		return false;
}

const char* Napis::Zwroc() const
{
	return m_pszNapis;
}

void Napis::Ustaw(const char* nowy_Napis) 
{
	strcpy(m_pszNapis, nowy_Napis);
}
void Napis::Wypisz() const
{
	cout << m_pszNapis;
}
void Napis::Wpisz()
{
	cin >> m_pszNapis;
}
int Napis::SprawdzNapis(const char* por_napis) const
{
	return strcmp(m_pszNapis, por_napis);
}

ostream & operator<<(ostream & wy, const Napis & p)
{
	wy << p.m_pszNapis << "\t";
	return wy;
}
istream & operator >> (istream & we, Napis & p)
{
	p.m_nDl = 0;
	we >> p.m_pszNapis;
	while (p.m_pszNapis[p.m_nDl] != 0)
	{
		p.m_nDl++;
	}
	return we;
}