#include "ListaPracownikow.h"
#include <fstream>

using namespace std;

ListaPracownikow::ListaPracownikow()
{
	m_pPoczatek = nullptr;
	m_nLiczbaPracownikow = 0;
}

ListaPracownikow::~ListaPracownikow()
{
	m_pPoczatek = nullptr;
	m_nLiczbaPracownikow = 0;
}

void ListaPracownikow::Dodaj(const Pracownik & p)
{
	Pracownik * pom = new Pracownik(p);
	if (m_nLiczbaPracownikow == 0)
	{
		m_pPoczatek = pom;
		m_nLiczbaPracownikow++;
	}
	else if (pom->Porownaj(*m_pPoczatek) == 1)
	{
		pom->m_pNastepny = m_pPoczatek;
		m_pPoczatek = pom;
		m_nLiczbaPracownikow++;
	}
	else
	{
		Pracownik * wsk1 = m_pPoczatek;
		Pracownik * wsk2 = m_pPoczatek->m_pNastepny;
		for (int i = 1; i < m_nLiczbaPracownikow && wsk2 != nullptr; i++, wsk1 = wsk2, wsk2 = wsk2->m_pNastepny)
		{
			int x = pom->Porownaj(*wsk2);
			if (x == 1)
			{
				wsk1->m_pNastepny = pom;
				pom->m_pNastepny = wsk2;
				m_nLiczbaPracownikow++;
				wsk2 = wsk1;
			}
			else if (x == 0)
				break;
		}
		if ((wsk2 == nullptr))
		{
			wsk1->m_pNastepny = pom;
			m_nLiczbaPracownikow++;
		}
		wsk1 = nullptr;
		wsk2 = nullptr;
	}

}
void ListaPracownikow::Usun(const Pracownik & wzorzec)
{
	Pracownik pom = wzorzec;
	Pracownik * wsk1 = m_pPoczatek;
	if (pom.Porownaj(*wsk1) == 0)
	{
		m_pPoczatek = wsk1->m_pNastepny;
		delete wsk1;
		m_nLiczbaPracownikow--;
	}
	else
	{
		Pracownik * wsk2 = m_pPoczatek->m_pNastepny;
		for (int i = 1; i < m_nLiczbaPracownikow; i++, wsk1 = wsk2, wsk2 = wsk2->m_pNastepny)
		{
			if (wsk2->Porownaj(pom) == 0)
			{
				wsk1->m_pNastepny = wsk2->m_pNastepny;
				wsk2->m_pNastepny = nullptr;
				delete wsk2;
				m_nLiczbaPracownikow--;
				break;
			}
		}
		wsk2 = nullptr;
		wsk1 = nullptr;
	}

}
void ListaPracownikow::WypiszPracownikow() const
{
	Pracownik *temp = m_pPoczatek;
	while (temp != NULL)
	{
		temp->Wypisz();
		temp = temp->m_pNastepny;
	}
}
const Pracownik * ListaPracownikow::Szukaj(const char * nazwisko, const char * imie) const
{
	Pracownik *wsk = m_pPoczatek;
	while (wsk != nullptr)
	{
		if ((wsk->SprawdzNazwisko(nazwisko) == 0) && (wsk->SprawdzImie(imie) == 0))
		{
			return wsk;
		}
		wsk = wsk->m_pNastepny;
	}
	wsk = nullptr;
	return nullptr;
}

void ListaPracownikow::ZapiszDoPliku(std::fstream &file)
{
	file.open("file", std::ios::app); //app - dopisuje na koncu pliku
	if (file.good() == true)
	{
		cout << "Uzyskano dostep do pliku!" << endl;
		Pracownik *temp = m_pPoczatek;
		while (temp != NULL)
		{
			file << *temp;
			temp = temp->m_pNastepny;
		}
		file.close();
	}
	else cout << "Brak dostepu do pliku." << endl;
}
void ListaPracownikow::WczytajZPliku(std::fstream &file)
{
	file.open("file", std::ios::in); //in - odczyt
	if (file.good() == true)
	{
		//cout << "Uzyskano dostep do pliku!\n" << endl;
		file.seekg(0, std::ios::beg); //przesuniecie wskaznika na poczatek pliku
		if (file.good() == true)
		{
			//string txt;
			//cout << "Wskaznik przesuniety na poczatek pliku.\n" << endl;
			while (!file.eof())
			{
				Pracownik x;
				file >> x;
				if (Szukaj(x.Imie(), x.Nazwisko()) == NULL)
				{
					Dodaj(x);
				}
			}
			file.close();
			//Pracownik x("", "", 1, 1, 2000);
			//Usun(x);
		}
		else cout << "Nie udalo sie przesunac wskaznika na poczatek pliku.\n" << endl;
	}
	else cout << "Brak dostepu do pliku.\n" << endl;
}