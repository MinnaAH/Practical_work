#include "Opettaja.h"
#include <iostream>
#include<string>
using std::cout; using std::endl; using std::cin;


Opettaja::Opettaja():palkka_()
{
}

Opettaja::Opettaja(string tunnus, string enimi, string snimi, string palkka) :
	tunnus_(tunnus), enimi_(enimi), snimi_(snimi), palkka_(palkka)
{
}

Opettaja::~Opettaja()
{
}

string Opettaja::annaTunnus() const
{
	return tunnus_;
}

string Opettaja::annaEnimi()
{
	return enimi_;
}

string Opettaja::annaSnimi()
{
	return snimi_;
}

string Opettaja::annaPalkka()
{
	return palkka_;
}

void Opettaja::asetaTunnus(string tunnus)
{
	tunnus_ = tunnus;
}

void Opettaja::asetaEnimi(string enimi)
{
	enimi_ = enimi;
}

void Opettaja::asetaSnimi(string snimi)
{
	snimi_ = snimi;
}

void Opettaja::asetaPalkka(string palkka)
{
	palkka_ = palkka;
}

void Opettaja::kysyTiedot()
{
	cout << "Anna opettajan tunnus: ";
	getline(cin, tunnus_);
	cout << "Anna opettajan etunimi: ";
	getline(cin, enimi_);
	cout << "Anna opettajan sukunimi: ";
	getline(cin, snimi_);
	cout << "Anna opettajan palkka: ";
	getline(cin, palkka_);
}

void Opettaja::tulosta() const
{
	cout <<"Opettaja: " << tunnus_ << ", " << enimi_ << ", " << snimi_ << ", " << palkka_ << endl;
}
