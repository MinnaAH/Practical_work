#pragma once
#include <string>
using std::string;
class Henkilo
{
public:
	Henkilo();
	Henkilo(string etunimi, string sukunimi, string osoite,
		string puhelinnumero);
	Henkilo(const Henkilo& alkup);
	~Henkilo();
	string annaEtunimi() const;
	string annaSukunimi() const;
	string annaOsoite() const;
	string annaPuhelinnumero() const;
	void asetaEtunimi(string etunimi);
	void asetaSukunimi(string sukunimi);
	void asetaOsoite(string osoite);
	void asetaPuhelinnumero(string puhelinnumero);

	void kysyTiedot();
	void tulosta() const;
private:
	string etunimi_;
	string sukunimi_;
	string osoite_;
	string puhelinnumero_;
};