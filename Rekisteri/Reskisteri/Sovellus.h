#pragma once
#include <string>
using std::string;

class Sovellus
{
public:
	Sovellus();
	~Sovellus();
	
	void aja() const;

private:
	string tulostaValikko() const;
	string valinta;
};

