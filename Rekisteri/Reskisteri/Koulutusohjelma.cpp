#include "Koulutusohjelma.h"
#include<iostream>
#include <vector>
using std::cout; using std::cin; using std::endl;

Koulutusohjelma::Koulutusohjelma() :nimi_(), opettajat_(), opiskelijat_()
{
}

Koulutusohjelma::Koulutusohjelma(string nimi) : nimi_(nimi), opettajat_(), opiskelijat_()
{
}


Koulutusohjelma::~Koulutusohjelma()
{
}

string Koulutusohjelma::annaNimi() const
{
	return nimi_;
}

void Koulutusohjelma::asetaNimi(string nimi)
{
	nimi_ = nimi;
}

void Koulutusohjelma::lisaaOpettaja()
{

	Opettaja tmp;
	tmp.kysyTiedot();
	opettajat_.push_back(tmp);
}

void Koulutusohjelma::lisaaOpiskelija()
{
	Opiskelija tmp;
	tmp.kysyTiedot();
	opiskelijat_.push_back(tmp);
}

void Koulutusohjelma::tulostaOpettajat() const
{
	for (unsigned int i = 0; i < opettajat_.size(); i++)
		opettajat_[i].tulosta();
}

void Koulutusohjelma::tulostaOpiskelijat() const
{
	for (unsigned int i = 0; i < opiskelijat_.size(); i++)
		opiskelijat_[i].tulosta();
}

int Koulutusohjelma::etsiOpettaja() const
{
	string tunnus;
	cout << "Anna etsittavan opettajan tunnus: ";
	getline(cin, tunnus);
	for (unsigned int i = 0; i < opettajat_.size(); i++) {
		if (tunnus == opettajat_[i].annaTunnus())
			return i; //Palauttaa etsityn koulutusohjelman
	}
	cout << "Opettajaa ei loytynyt!" << endl;  //Jos opettajaa ei loytynyt, ohjelma ilmoittaa siitä ja palauttaa arvon -1
	return -1;
}

int Koulutusohjelma::etsiOpiskelija() const
{
	string numero;
	cout << "Anna etsittavan opiskelijan tunnus: ";
	getline(cin, numero);
	for (unsigned int i = 0; i < opiskelijat_.size(); i++) {
		if (numero == opiskelijat_[i].annaNum())
			return i; //Palauttaa etsityn opiskelijan
	}
	cout << "Opiskelijaa ei loytynyt!" << endl; //Jos opiskelijaa ei löytynyt, ohjelma ilmoittaa siitä ja palauttaa arvon -1
	return -1;
}

void Koulutusohjelma::poistaOpettaja()
{
	int indeksi = etsiOpettaja();
	if (indeksi >= 0)
		opettajat_.erase(opettajat_.begin() + indeksi);
}

void Koulutusohjelma::poistaOpiskelija()
{
	int indeksi = etsiOpiskelija();
	if (indeksi >= 0)
		opiskelijat_.erase(opiskelijat_.begin() + indeksi);
}
