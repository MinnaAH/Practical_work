#pragma once
#include <string>
using std::string;

class Opiskelija
{
public:
	Opiskelija();
	Opiskelija(string num, string enimi, string snimi, string email);
	~Opiskelija();
	//getters
	string annaNum() const;
	string annaEnimi();
	string annaSnimi();
	string annaEmail();
	//setters
	void asetaNum(string num);
	void asetaEnimi(string enimi);
	void asetaSnimi(string snimi);
	void asetaEmail(string email);
	void kysyTiedot();

	void tulosta() const;

private:
	string num_;
	string enimi_;
	string snimi_;
	string email_;
};

