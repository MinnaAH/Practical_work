#pragma once
#include<string>
using std::string;
class Opettaja
{
public:
	Opettaja();
	Opettaja(string tunnus, string enimi, string snimi, string palkka);
	~Opettaja();

	string annaTunnus() const;
	string annaEnimi();
	string annaSnimi();
	string annaPalkka();

	void asetaTunnus(string tunnus);
	void asetaEnimi(string enimi);
	void asetaSnimi(string snimi);
	void asetaPalkka(string palkka);
	void kysyTiedot();

	void tulosta() const;
private:
	string tunnus_;
	string enimi_;
	string snimi_;
	string palkka_;
};

