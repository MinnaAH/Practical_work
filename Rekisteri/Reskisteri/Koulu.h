#pragma once
#include "Koulutusohjelma.h"
#include"Opettaja.h"
#include"Opiskelija.h"
#include <string>
#include<vector>
using std::string; using std::vector;

class Koulu
{
public:
	Koulu();
	Koulu(string nimi);
	~Koulu();
	string annaNimi() const;
	void asetaNimi(string nimi);
	//Kayttoliittyman valikon toiminnat
	void lisaaKoulutusohjelma();
	void tulostaKoulutusohjelmat();
	void tulostaKoulutusohjelmienMaara() const;
	void lisaaKoulutusohjelmaanOpettaja();
	void tulostaKoulutusohjelmanOpettajat() const;
	void lisaaKoulutusohjelmaanOpiskelija();
	void tulostaKoulutusohjelmanOpiskelijat() const;
	void poistaKoulutusohjelma();
	void poistaOpettaja();
	void poistaOpiskelija();
private:
	string nimi_;
	vector<Koulutusohjelma> koulutusohjelmat_;
	vector<Opettaja> opettajat_;
	vector<Opiskelija> opiskelijat_;
	int etsiKoulutusohjelma() const;
};

