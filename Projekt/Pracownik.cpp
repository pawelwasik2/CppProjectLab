#include "Pracownik.h"

using namespace std;

Pracownik::Pracownik(const char * im, const char * naz, int dzien, int miesiac, int rok) : m_DataUrodzenia(dzien, miesiac, rok)
{
	m_Imie.Ustaw(im);
	m_Nazwisko.Ustaw(naz);
	m_nIDZatrudnienia = 10000 * (rok % 100) + 100 * miesiac + dzien;
}

Pracownik::Pracownik(const Pracownik& wzor) : m_DataUrodzenia(wzor.m_DataUrodzenia), m_nIDZatrudnienia(wzor.m_nIDZatrudnienia)
{
	m_Nazwisko = wzor.m_Nazwisko;
	m_Imie = wzor.m_Imie;
}

Pracownik::~Pracownik()
{
}

Pracownik& Pracownik::operator=(const Pracownik& wzor)
{
	if (this != &wzor)
	{
		m_Imie = wzor.m_Imie;
		m_Nazwisko = wzor.m_Nazwisko;
		m_DataUrodzenia = wzor.m_DataUrodzenia;
	}
	return *this;
}


bool Pracownik::operator==(const Pracownik& wzor) const
{
	if (this->Porownaj(wzor) == 0)
		return true;
	else
		return false;
}


const char* Pracownik::Imie() const
{
	return m_Imie.Zwroc();
}
const char* Pracownik::Nazwisko() const
{
	return m_Nazwisko.Zwroc();
}
void Pracownik::Imie(const char * nowe_imie)
{
	m_Imie.Ustaw(nowe_imie);
}

void Pracownik::Nazwisko(const char * nowe_nazwisko)
{
	m_Nazwisko.Ustaw(nowe_nazwisko);
}

void Pracownik::DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok)
{
	m_DataUrodzenia.Ustaw(nowy_dzien, nowy_miesiac, nowy_rok);
}
void Pracownik::Wypisz() const
{
	//cout << m_Imie.Wypisz() << " " << m_Nazwisko.Wypisz() << " ";
	m_Imie.Wypisz();
	m_Nazwisko.Wypisz();
	m_DataUrodzenia.Wypisz();
}
void Pracownik::Wpisz()
{
	cout << "Podaj imie, naziwsko oraz date urodzenia\n";
	m_Imie.Wpisz();
	m_Nazwisko.Wpisz();
	m_DataUrodzenia.Wpisz();
}

int Pracownik::SprawdzImie(const char * por_imie) const
{
	return m_Imie.SprawdzNapis(por_imie);
}

int Pracownik::SprawdzNazwisko(const char * por_nazwisko) const
{
	return m_Nazwisko.SprawdzNapis(por_nazwisko);
}

int Pracownik::Porownaj(const Pracownik & wzorzec) const
{
	int czyNazw = SprawdzNazwisko(wzorzec.Nazwisko());
	int czyImie = SprawdzImie(wzorzec.Imie());
	int czyData = m_DataUrodzenia.Porownaj(wzorzec.m_DataUrodzenia);
	if (czyNazw == 0)
	{
		if (czyImie == 0)
		{
			if (czyData == 0)
			{
				return 0;
			}
			else if (czyData == 1)
			{
				return 1;
			}
			else
			{
				return -1;
			}
		}
		else if (czyImie == 1)
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
	else if (czyNazw == 1)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

ostream & operator<<(ostream & wy, const Pracownik & p)
{
	wy << p.m_Imie << p.m_Nazwisko << p.m_DataUrodzenia;
	return wy;
}

istream & operator >> (istream & we, Pracownik & p)
{
	std::cout << "Podaj imie: ";
	we >> p.m_Imie;
	std::cout << "Podaj nazwisko: ";
	we >> p.m_Nazwisko;
	we >> p.m_DataUrodzenia;
	return we;
}