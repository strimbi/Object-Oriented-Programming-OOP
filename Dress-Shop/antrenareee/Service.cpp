#include "Service.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Service::Service()
{
}

Service::~Service()
{
}

/// <summary>
/// Gasim rochiile care au o marime anume si si o personalizare anume in acelasi  timp, altfel aruncam exceptii
/// </summary>
/// <param name="marime"></param>
/// <param name="person"></param>
/// <returns></returns>
std::vector<Rochie> Service::criterii(string marime, string person)
{
	if (marime != "S" and marime != "M" and marime != "XS" and marime != "L" and marime != "XL")
	{
		throw MyException("Size is not correct!");
	}
	if (person != "yes" and person != "no" and person != "Yes" and person != "No")
	{
		throw MyException("customizable is not correct!");
	}
	
	bool personalizare;
	if (person == "True") personalizare = true;
	else personalizare = false;

	std::vector<Rochie> rochite;
	for (int i = 0; i < getSize(); i++)
	{
		if (getRochie(i).getMarime() == marime and getRochie(i).gsetPersonalizare() == personalizare)
		{
			rochite.push_back(getRochie(i));
		}
	}

	if (rochite.size() == 0)
	{
		throw MyException("There are no dresses with these specifications");
	}
	else return rochite;
}

/// <summary>
/// Gasim primele cele mai 3 ieftine rochii
/// </summary>
/// <returns></returns>
std::vector<Rochie> Service::top3()
{
	std::vector<Rochie> rochite;
	int minim1 = 10000;
	int minim2 = 10000;
	int minim3 = 10000;

	Rochie r1;
	Rochie r2;
	Rochie r3;

	for (int i = 0; i < getSize(); i++)
	{
		if (getRochie(i).getPret() < minim1)
		{
			minim3 = minim2;
			r3 = r2;
			minim2 = minim1;
			r2 = r1;
			minim1 = getRochie(i).getPret();
			r1 = getRochie(i);
		}
		else if (getRochie(i).getPret() < minim2)
		{
			minim3 = minim2;
			r3 = r2;
			minim2 = getRochie(i).getPret();
			r2 = getRochie(i);
		}
		else if (getRochie(i).getPret() < minim3)
		{
			minim3 = getRochie(i).getPret();
			r3 = getRochie(i);
		}
	}

	if (minim1 == 1000 || minim2 == 1000 || minim1 == 1000)
	{
		throw MyException("There are no top-3 dresses");		///aruncam exceptia daca macar unu din minimuri nu este modificat
	}
	else
	{
		rochite.push_back(r1);
		rochite.push_back(r2);
		rochite.push_back(r3);
		return rochite;
	}
}

/// <summary>
/// Functie in care cumparam o rochie cu un id specific, daca acesta este corect, modificand nr de rochii disponibile
/// </summary>
/// <param name="id"></param>
void Service::cumparare(int id)
{
	int poz = id - 1;

	if (poz < 0 || poz >= getSize())
	{
		throw MyException("Dress with " + to_string(id) + " id does not exist");
	}
	if (getRochie(poz).getNr() == 0)
	{
		throw MyException("There are no more dresses of this type");		///aruncam exceptie daca nu mai sunt rochii de cumparat
	}

	Rochie c = getRochie(poz);
	updateRochie(poz, c.getId(), c.getDenumire(), c.getMarime(), c.getCuloare(), c.getNr() - 1, c.getPret(), c.gsetPersonalizare());
}

int Service::getSize()
{
	return this->repo.getSize();
}

std::vector<Rochie> Service::getAll()
{
	return this->repo.getAll();
}

Rochie Service::getRochie(int poz)
{
	return this->repo.getRochie(poz);
}

void Service::updateRochie(int poz, int id, string denumire, string marime, string culoare, int nr, int pret, bool personabilizare)
{
	this->repo.updateRochie(poz, Rochie(id, denumire, marime, culoare, nr, pret, personabilizare));
}
