#include "Henkilo.h"
#include <iostream>
#include <fstream>
using std::endl; using std::cout; using std::cin; using std::getline; using std::ofstream;

/*------------------------------------------------
*name: Henkilo()
*action: defaul constructor
-------------------------------------------------*/
Henkilo::Henkilo() :etunimi_(), sukunimi_(), osoite_(), puhelinnumero_()
{
}
/*----------------------------------------------------------------------------------
*name: Henkilo(string etunimi, string sukunimi, string osoite, string puhelinnumero)
*action: Parameter constructor
-----------------------------------------------------------------------------------*/
Henkilo::Henkilo(string etunimi, string sukunimi, string osoite,
	string puhelinnumero) : etunimi_(etunimi), sukunimi_(sukunimi),
	osoite_(osoite), puhelinnumero_(puhelinnumero)
{
}
/*------------------------------------------------
*name: Henkilo(const Henkilo &alkup)
*action: copy constructor
-------------------------------------------------*/
Henkilo::Henkilo(const Henkilo & alkup) : etunimi_(alkup.etunimi_),
sukunimi_(alkup.sukunimi_), osoite_(alkup.osoite_),
puhelinnumero_(alkup.puhelinnumero_)
{
}
/*------------------------------------------------
*name: ~Henkilo()
*action: destructor
-------------------------------------------------*/
Henkilo::~Henkilo()
{
}
/*----------------------------------------------------------------
*name: annaEtunimi() const
*action: Get firstname
-----------------------------------------------------------------*/
string Henkilo::annaEtunimi() const
{
	return etunimi_;
}
/*-----------------------------------------------------------------
*name: annaSukunimi() const
*action: Get lastname
-------------------------------------------------------------------*/
string Henkilo::annaSukunimi() const
{
	return sukunimi_;
}
/*----------------------------------------------------------------
*name: annaOsoite() const
*action: Get address
-----------------------------------------------------------------*/
string Henkilo::annaOsoite() const
{
	return osoite_;
}
/*----------------------------------------------------------------------
*name: annaPuhelinnumero() const
*action: Get phone number
-----------------------------------------------------------------------*/
string Henkilo::annaPuhelinnumero() const
{
	return puhelinnumero_;
}
/*-----------------------------------------------------------------------
*name: asetaEtunimi(string etunimi)
*action: Set firstname
-------------------------------------------------------------------------*/
void Henkilo::asetaEtunimi(string etunimi)
{
	etunimi_ = etunimi;
}
/*------------------------------------------------------------------------
*name: asetaSukunimi(strgin sukunimi)
*action: set lastname
-------------------------------------------------------------------------*/
void Henkilo::asetaSukunimi(string sukunimi)
{
	sukunimi_ = sukunimi;
}
/*------------------------------------------------------------------------
*name: asetaOsoite(string osoite)
*action: Set address
-------------------------------------------------------------------------*/
void Henkilo::asetaOsoite(string osoite)
{
	osoite_ = osoite;
}
/*------------------------------------------------------------------------
*name: asetaPuhelinnumero(string puhelinnumero)
*action: Set phone number
--------------------------------------------------------------------------*/
void Henkilo::asetaPuhelinnumero(string puhelinnumero)
{
	puhelinnumero_ = puhelinnumero;
}
/*------------------------------------------------
*name: kysyTiedot()
*action: Ask person information from user
-------------------------------------------------*/
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
/*------------------------------------------------
*name: tulosta() const
*action: print person information
-------------------------------------------------*/
void Henkilo::tulosta() const
{
	cout << etunimi_ << " " << sukunimi_ << " " << osoite_ << " " << puhelinnumero_ << " ";
}
/*--------------------------------------------------
*name: tallennaTiedotTyontekija() const
*action: save workers information
----------------------------------------------------*/
void Henkilo::tallennaTiedotTyontekija() const {

	ofstream Opettaja;
	Opettaja.open("Opettaja.csv", ofstream::app);
	Opettaja << etunimi_ << ";" << sukunimi_ << ";" << osoite_ << ";" << puhelinnumero_ << ";";
}
/*------------------------------------------------
*name: tallennaTiedotOppilas() const
*action: save student information
-------------------------------------------------*/
void Henkilo::tallennaTiedotOpiskelija() const
{
	ofstream Opiskelija;
	Opiskelija.open("Opiskelija.csv", ofstream::app);
	Opiskelija << etunimi_ << ";" << sukunimi_ << ";" << osoite_ << ";" << puhelinnumero_ << ";";
}
