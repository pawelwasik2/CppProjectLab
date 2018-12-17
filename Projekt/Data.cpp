#include "Data.h"
#include <iostream>

using namespace std;

Data::Data(int d, int m, int r)	
{
	m_nDzien = d;
	m_nMiesiac = m;
	m_nRok = r;
}

Data::~Data()
{
}

void Data::Ustaw(int d, int m, int r)
{
	m_nDzien = d;
	m_nMiesiac = m;
	m_nRok = r;
	Koryguj();
}

int Data::Dzien() const 
{
	return m_nDzien;
}
int Data::Miesiac() const
{
	return m_nMiesiac;
}
int Data::Rok() const
{
	return m_nRok;
}

void Data::Wpisz()
{
	int d, m, r;
	cout << "Podaj dzien, miesiac a nastepnie rok.\n";
	cin >> d;
	cin >> m;
	cin >> r;
	Ustaw(d, m, r);
}

void Data::Wypisz() const
{
	cout << m_nDzien << "-" << m_nMiesiac << "-" <<  m_nRok;
}

void Data::Koryguj()
{
	if (m_nDzien < 1)
	{
		m_nDzien = 1;
	}
	if (m_nDzien > 31)
	{
		if ((m_nMiesiac == 4) || (m_nMiesiac == 6) || (m_nMiesiac == 6) || (m_nMiesiac == 9) || (m_nMiesiac == 11))
		{
			m_nDzien = 30;
		}
		else if ((m_nDzien != 31) || (m_nMiesiac == 1) || (m_nMiesiac == 3) || (m_nMiesiac == 5) || (m_nMiesiac == 7) || (m_nMiesiac == 8) || (m_nMiesiac == 10) || (m_nMiesiac == 12))
		{
			m_nDzien = 31;
		}
	}
	if (m_nMiesiac == 2)
	{
		if (m_nDzien > 28)
		{
			if (((m_nRok % 4 == 0) && (m_nRok % 100 != 0)) || (m_nRok % 400 == 0))
			{
				if (m_nDzien != 29)
				{
					m_nDzien = 29;
				}
			}
			else
			{
				m_nDzien = 28;
			}
		}
	}
	if (m_nMiesiac > 12)
	{
		m_nMiesiac = 12;
	}
	if (m_nMiesiac < 1)
	{
		m_nMiesiac = 1;
	}
}
int Data::Porownaj(const Data & wzor) const 
{
	if (Rok() > wzor.m_nRok)
		return -1;
	else if (Rok() < wzor.m_nRok)
		return 1;
	else
	{
		if (Miesiac() > wzor.m_nMiesiac)
			return -1;
		else if (Miesiac() < wzor.m_nMiesiac)
			return 1;
		else
		{
			if (Dzien() > wzor.m_nDzien)
				return -1;
			else if (Dzien() < wzor.m_nDzien)
				return 1;
			else return 0;
		}
	}
	return 0;
}
ostream & operator<<(ostream & wy, const Data & d)
{
	wy << d.m_nDzien << " " << d.m_nMiesiac << " " << d.m_nRok << std::endl;
	return wy;
}
istream & operator >> (istream & we, Data & d)
{
	std::cout << "Podaj dzien: ";
	we >> d.m_nDzien;
	std::cout << "Podaj miesiac: ";
	we >> d.m_nMiesiac;
	std::cout << "Podaj rok: ";
	we >> d.m_nRok;
	d.Koryguj();
	return we;
}