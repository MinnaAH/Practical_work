#include "Henkilo.h"
#include <iostream>
using std::endl; using std::cout; using std::cin; using std::getline;

Henkilo::Henkilo() :etunimi_(), sukunimi_(), osoite_(), puhelinnumero_()
{
}

Henkilo::Henkilo(string etunimi, string sukunimi, string osoite,
	string puhelinnumero) : etunimi_(etunimi), sukunimi_(sukunimi),
	osoite_(osoite), puhelinnumero_(puhelinnumero)
{
}

Henkilo::Henkilo(const Henkilo & alkup) : etunimi_(alkup.etunimi_),
sukunimi_(alkup.sukunimi_), osoite_(alkup.osoite_),
puhelinnumero_(alkup.puhelinnumero_)
{
}


Henkilo::~Henkilo()
{
}

string Henkilo::annaEtunimi() const
{
	return etunimi_;
}

string Henkilo::annaSukunimi() const
{
	return sukunimi_;
}

string Henkilo::annaOsoite() const
{
	return osoite_;
}

string Henkilo::annaPuhelinnumero() const
{
	return puhelinnumero_;
}

void Henkilo::asetaEtunimi(string etunimi)
{
	etunimi_ = etunimi;
}

void Henkilo::asetaSukunimi(string sukunimi)
{
	sukunimi_ = sukunimi;
}

void Henkilo::asetaOsoite(string osoite)
{
	osoite_ = osoite;
}

void Henkilo::asetaPuhelinnumero(string puhelinnumero)
{
	puhelinnumero_ = puhelinnumero;
}

void Henkilo::kysyTiedot()
{
	cout << "Anna etunimi: ";
	getline(cin, etunimi_);
	cout << "Anna sukunimi: ";
	getline(cin, sukunimi_);
	cout << "Anna osoite: ";
	getline(cin, osoite_);
	cout << "Anna puhelinnumero: ";
	getline(cin, puhelinnumero_);
}

void Henkilo::tulosta() const
{
	cout << etunimi_ << " " << sukunimi_ << " " << osoite_ << " " <<
		puhelinnumero_ << " ";
}