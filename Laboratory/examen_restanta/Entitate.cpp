#include "Entitate.h"
#include <string.h>
#include <iostream>
#include <sstream>

using namespace std;

Bacterie::Bacterie()
{
	this->denumire = "";
	this->varsta = 0;
	this->tip = 0;
}

Bacterie::~Bacterie()
{
}

Bacterie::Bacterie(string denumire, int varsta, int tip)
{
	this->denumire = denumire;
	this->varsta = varsta;
	this->tip = tip;
}

void Bacterie::setDenumire(string denumire)
{
	this->denumire = denumire;
}

void Bacterie::setVarsta(int varsta)
{
	this->varsta = varsta;
}

void Bacterie::setTip(int tip)
{
	this->tip = tip;
}

string Bacterie::getDenumire()
{
	return this->denumire;
}

int Bacterie::getVarsta()
{
	return this->varsta;
}

int Bacterie::getTip()
{
	return this->tip;
}

bool Bacterie::operator==(const Bacterie& c)
{
	return this->denumire == c.denumire and this->varsta == c.varsta and this->tip == c.tip;
}

void Bacterie::operator=(const Bacterie& c)
{
	this->denumire = c.denumire;
	this->varsta = c.varsta;
	this->tip = c.tip;
}

std::string Bacterie::tostring()
{
	return "name: " + this->denumire + " | " + "age: " + to_string(this->varsta) + " | " + "type: " + to_string(this->tip);
}
