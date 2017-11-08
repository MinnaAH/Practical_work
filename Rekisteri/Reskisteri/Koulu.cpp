#include "Koulu.h"
#include<iostream>
#include <vector>
using std::cout; using std::cin; using std::endl;



Koulu::Koulu() : nimi_(), koulutusohjelmat_()
{
}

Koulu::Koulu(string nimi) : nimi_(nimi), koulutusohjelmat_()
{
}


Koulu::~Koulu()
{
}

string Koulu::annaNimi() const
{
	return nimi_;
}

void Koulu::asetaNimi(string nimi)
{
	nimi_ = nimi;
}

void Koulu::tulostaKoulutusohjelmat()
{
	cout << "Koulutusohjelmat" << endl;
	cout << "----------------" << endl;
	for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++)
		cout << koulutusohjelmat_[i].annaNimi() << endl;
}

void Koulu::lisaaKoulutusohjelma()
{
	string nimi;
	cout << "Anna koulutusohjelman nimi: ";
	getline(cin, nimi);
	Koulutusohjelma tmp(nimi);
	koulutusohjelmat_.push_back(tmp);
}

void Koulu::tulostaKoulutusohjelmienMaara() const
{
	cout << "Koulutusohjelmien lukumaara: " << koulutusohjelmat_.size() << endl;
}

void Koulu::lisaaKoulutusohjelmaanOpettaja()
{
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0) //Tarkistetaan onko kouluutusohjelma olemassa, jotta opettaja voidaan lisata koulutusohjelmaan
	{
		koulutusohjelmat_[indeksi].lisaaOpettaja();
	}
}

void Koulu::tulostaKoulutusohjelmanOpettajat() const
{
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0)
	{
		koulutusohjelmat_[indeksi].tulostaOpettajat();
	}
}

void Koulu::lisaaKoulutusohjelmaanOpiskelija()
{
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0)
	{
		koulutusohjelmat_[indeksi].lisaaOpiskelija();
	}
}

void Koulu::tulostaKoulutusohjelmanOpiskelijat() const
{
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0)
	{
		koulutusohjelmat_[indeksi].tulostaOpiskelijat();
	}
}

void Koulu::poistaKoulutusohjelma()
{
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0)
		koulutusohjelmat_.erase(koulutusohjelmat_.begin() + indeksi);
}

void Koulu::poistaOpettaja()
{
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0)
		koulutusohjelmat_[indeksi].poistaOpettaja();
}

void Koulu::poistaOpiskelija()
{
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0)
		koulutusohjelmat_[indeksi].poistaOpiskelija();
}


int Koulu::etsiKoulutusohjelma() const
{
	string nimi;
	cout << "Anna etsittavan koulutusohjelman nimi: ";
	getline(cin, nimi);
	for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++) {
		if (nimi == koulutusohjelmat_[i].annaNimi())
			return i; //Palauttaa etsityn koulutusohjelman
	}
	cout << "Koulutusohjelmaa ei loytynyt!" << endl; //Jos koulutusohjelmaa ei loytynyt, ohjelma ilmoittaa siitä ja palauttaa arvon -1
	return -1;
}