#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include "entitate.h"

Produs::Produs()
{
	this->cod = 0;
	this->nume = "";
	this->pret = 0;
}

Produs::Produs(int cod, std::string nume, int pret)
{
	this->cod = cod;
	this->nume = nume;
	this->pret = pret;
}

Produs::~Produs()
{
	
}

void Produs::setCod(int cod)
{
	this->cod = cod;
}

void Produs::setNume(std::string nume)
{
	this->nume = nume;
}

void Produs::setPret(int pret)
{
	this->pret = pret;
}

int Produs::getCod()
{
	return this->cod;
}

std::string Produs::getNume()
{
	return this->nume;
}

int Produs::getPret()
{
	return this->pret;
}

bool Produs::operator==(Produs& p)
{
	return this->cod == p.getCod() and this->pret == p.getPret() and this->nume == p.getNume();
}

void Produs::operator=(const Produs& p)
{
	setCod(p.cod);
	setPret(p.pret);
	setNume(p.nume);
}

std::string Produs::tostring()
{
	std::stringstream s1;
	s1 << this->cod;
	std::string str1 = s1.str();

	std::stringstream s2;
	s2 << this->nume;
	std::string str2 = s2.str();

	std::stringstream s3;
	s3 << this->pret;
	std::string str3 = s3.str();

	return "Cod: " + str1 + "\nNume: " + str2 + "\nPret: " + str3 + "\n";
}
