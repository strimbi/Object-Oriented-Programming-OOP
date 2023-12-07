#include "Rochii.h"
#include <iostream>
#include <string>

using namespace std;

Rochie::Rochie()
{
	this->id = 0;
	this->denumire = "";
	this->marime = "";
	this->culoare = "";
	this->nr = 0;
	this->pret = 0;
	this->personabilizare = false;
}

Rochie::Rochie(int id, string denumire, string marime, string culoare, int nr, int pret, bool personabilizare)
{
	this->id = id;
	this->denumire = denumire;
	this->marime = marime;
	this->culoare = culoare;
	this->nr = nr;
	this->pret = pret;
	this->personabilizare = personabilizare;
}

Rochie::~Rochie()
{
}

void Rochie::setId(int id)
{
	this->id = id;
}

void Rochie::setDenumire(string denumire)
{
	this->denumire = denumire;
}

void Rochie::setMarime(string marime)
{
	this->marime = marime;
}

void Rochie::setCuloare(string culoare)
{
	this->culoare = culoare;
}

void Rochie::setNr(int nr)
{
	this->nr = nr;
}

void Rochie::setPret(int pret)
{
	this->pret = pret;
}

void Rochie::setPersonalizare(bool person)
{
	this->personabilizare = personabilizare;
}

int Rochie::getId()
{
	return this->id;
}

string Rochie::getDenumire()
{
	return this->denumire;
}

string Rochie::getMarime()
{
	return this->marime;
}

string Rochie::getCuloare()
{
	return this->culoare;
}

int Rochie::getNr()
{
	return this->nr;
}

int Rochie::getPret()
{
	return this->pret;
}

bool Rochie::gsetPersonalizare()
{
	return this->personabilizare;
}

void Rochie::operator=(const Rochie& c)
{
	this->id = c.id;
	this->denumire = c.denumire;
	this->marime = c.marime;
	this->culoare = c.culoare;
	this->nr = c.nr;
	this->pret = c.pret;
	this->personabilizare = c.personabilizare;
}

bool Rochie::operator==(const Rochie& c)
{
	return this->id == c.id and this->denumire == c.denumire and this->marime == c.marime and this->culoare == c.culoare and this->nr == c.nr and
		this->pret == c.pret and this->personabilizare == c.personabilizare;
}

string Rochie::tostring()
{
	string person;
	if (this->personabilizare == true) person = "True";
	else person = "False";
	return to_string(this->id) + " | " + this->denumire + " | " + "size: " + this->marime + " | " + this->culoare + " | " + 
		"numbers: " + to_string(this->nr) + " | " + "price: " + to_string(this->pret) + " | " + "custom: " + person;
}
