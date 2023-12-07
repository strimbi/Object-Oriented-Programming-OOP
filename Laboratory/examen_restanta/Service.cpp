#include "Service.h"
#include "Exception.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Service::Service()
{
}

Service::~Service()
{
}

/// <summary>
/// Returnare lista de tipuri
/// </summary>
/// <param name="tip"></param>
/// <returns></returns>
std::vector<Bacterie> Service::returnare_bacterii_tip(int tip)
{
	std::vector<Bacterie> bacterii_trimise;

	if (tip != 1 and tip != 2) throw MyException("Type given is not correct");
	
	for (int i = 0; i < this->getSize(); i++)
	{
		if (this->getBacterie(i).getTip() == tip) bacterii_trimise.push_back(this->getBacterie(i));
	}

	return bacterii_trimise;
}

int Service::getSize()
{
	return this->repo.getSize();
}

Bacterie Service::getBacterie(int poz)
{
	return this->repo.getBacterie(poz);
}

std::vector<Bacterie> Service::getAll()
{
	return  this->repo.getAll();
}

/// <param name="denumire"></param>
/// <param name="varsta"></param>
/// <param name="tip"></param>
void Service::updateBacterie(int poz, string denumire, int varsta, int tip)
{
	this->repo.updateBacterie(poz, Bacterie(denumire, varsta, tip));
}

std::vector<Bacterie> Service::inmultire(int nr_unitati)
{
	std::vector<Bacterie> bacterii_mari = this->getAll();			///lista princiapala pe baza careia facem divizunea
	int unitate = 1;

	while (unitate <= nr_unitati)				///trecem prin n mutari
	{
		std::vector<Bacterie> bacteriute;

		for (int i = 0; i < bacterii_mari.size(); i++)
		{
			if (bacterii_mari[i].getTip() == 1)
			{
				Bacterie c = bacterii_mari[i];
				Bacterie noua = Bacterie(c.getDenumire(), c.getVarsta() + 1, 1);
				bacteriute.push_back(noua);
				bacteriute.push_back(bacterii_mari[i]);
			}
			else
			{
				if (unitate % 3 == 0)					///facem diviziunea pt bacteriile de tip 2
				{
					Bacterie b = bacterii_mari[i];
					bacteriute.push_back(Bacterie(b.getDenumire(), unitate, b.getTip()));
					bacteriute.push_back(Bacterie(b.getDenumire(), 0, 1));
				}
				else
				{
					Bacterie b = bacterii_mari[i];
					bacteriute.push_back(Bacterie(b.getDenumire(), unitate, b.getTip()));
				}
			}
		}
		unitate++;
		bacterii_mari = bacteriute;			///schimbam lista principala
		bacteriute.clear();
	}

	return bacterii_mari;
}

int Service::medie(std::vector<Bacterie> bacteriute)
{
	int suma = 0;
	for (int i = 0; i <bacteriute.size(); i++)
	{
		suma = bacteriute[i].getVarsta() + suma;
	}
	return (suma / bacteriute.size());
}

void Service::addBacterie(string denumire, int varsta, int tip)
{
	this->repo.addBacterie(Bacterie(denumire, varsta, tip));
}