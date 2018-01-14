#pragma once
#include <string>
using std::string;

class Henkilo
{
public:
	Henkilo(); //default constructor
	Henkilo(string etunimi, string sukunimi, string osoite, string puhelinnumero); //parameter constructor
	Henkilo(const Henkilo& alkup); //copy constructor
	~Henkilo(); //destructor
				//getter
	string annaEtunimi() const;
	string annaSukunimi() const;
	string annaOsoite() const;
	string annaPuhelinnumero() const;
	//setter
	void asetaEtunimi(string etunimi);
	void asetaSukunimi(string sukunimi);
	void asetaOsoite(string osoite);
	void asetaPuhelinnumero(string puhelinnumero);

	void kysyTiedot();
	void tulosta() const;
	void tallennaTiedotTyontekija() const;
	void tallennaTiedotOpiskelija() const;
private:
	string etunimi_;
	string sukunimi_;
	string osoite_;
	string puhelinnumero_;
};
