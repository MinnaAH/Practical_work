#include "Opiskelija.h"
#include<iostream>
#include<string>
using std::cout; using std::endl; using std::cin;

Opiskelija::Opiskelija()
{
}

Opiskelija::Opiskelija(string num, string enimi, string snimi, string email):
	num_(num), enimi_(enimi), snimi_(snimi), email_(email)
{
}

Opiskelija::~Opiskelija()
{
}

string Opiskelija::annaNum() const
{
	return num_;
}

string Opiskelija::annaEnimi()
{
	return enimi_;
}

string Opiskelija::annaSnimi()
{
	return snimi_;
}

string Opiskelija::annaEmail()
{
	return email_;
}

void Opiskelija::asetaNum(string num)
{
	num_ = num; //sijoitusoperaattori on toteutettu string-luokkaan
}

void Opiskelija::asetaEnimi(string enimi)
{
	enimi_ = enimi;
}

void Opiskelija::asetaSnimi(string snimi)
{
	snimi_ = snimi;
}

void Opiskelija::asetaEmail(string email)
{
	email_ = email;
}

void Opiskelija::kysyTiedot()
{
	cout << "Anna opiskelijanumero: ";
	getline(cin, num_);
	cout << "Anna opiskelijan etunimi: ";
	getline(cin, enimi_);
	cout << "Anna opiskelijan sukunimi: ";
	getline(cin, snimi_);
	cout << "Anna opiskelijan email: ";
	getline(cin, email_);
}

void Opiskelija::tulosta() const
{
	cout << "Opiskelija: " << num_ << " " << enimi_ << " " << snimi_ << " " << email_ << endl;
}
