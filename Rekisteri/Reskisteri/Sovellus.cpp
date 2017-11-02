#include "Sovellus.h"
#include "Koulu.h"
#include<iostream>
#include<string>
using std::cout; using std::endl; using std::cin;

Sovellus::Sovellus()
{
}
Sovellus::~Sovellus()
{
}

void Sovellus::aja() const
{
	Koulu tamk("TAMK");
	do{
	string valinta = tulostaValikko(); 
	
	if (valinta == "1")
		tamk.lis‰‰Koulutusohjelma();
	else if (valinta == "2")
		tamk.tulostaKoulutusohjelmat();
	else if (valinta == "3")
		tamk.tulostaKoulutusohjelmienMaara();
	else if (valinta == "4")
		tamk.lisaaKoulutusohjelmaanOpettaja();
	else if (valinta == "5")
		tamk.tulostaKoulutusohjelmanOpettajat();
	else if (valinta == "6")
		tamk.lisaaKoulutusohjelmaanOpiskelija();
	else if (valinta == "7")
		tamk.tulostaKoulutusohjelmanOpiskelijat();
	else if (valinta == "8")
		tamk.poistaKoulutusohjelma();
	else if (valinta == "0")
		break;
	else
		cout << "Valinta vaarin, valitse uudestaan" << endl;
	} while (valinta != "0");
}

string Sovellus::tulostaValikko() const
{
	string valinta;
	cout << "1) Lisaa koulutusohjelma" << endl;
	cout << "2) Tulosta koulutusohjelmien nimet" << endl;
	cout << "3) Tulosta koulutusohjelmien maara" << endl;
	cout << "4) Lisaa koulutusohjelmaan opettaja" << endl;
	cout << "5) Tulosta koulutusohjelman opettajat" << endl;
	cout << "6) Lisaa koulutusohjelmaan opiskelija" << endl;
	cout << "7) Tulosta koulutusohjelman opiskelijat" << endl;
	cout << "8) Poista koulutusohjelma" << endl;
	cout << "0) Lopeta" << endl;
	cout << "Syota valinta: ";
	getline(cin, valinta);

	return valinta;
}
