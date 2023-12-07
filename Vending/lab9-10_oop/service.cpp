#include "service.h"
#pragma warning(disable: 4996)
#include <iostream>

Service::Service()
{
	
}

Service::~Service()
{
}

int Service::colSize()
{
	if (collection.size() == 0)
	{
		throw MyException("There are no coins in the vending machine!");
	}
	return collection.size();
}

int Service::colgetElem(int poz)
{
	return collection.getAt(poz);
}

void Service::colAddElem(TElem element)
{
	collection.add(element);
}

void Service::coldDelElem(TElem element)
{
	collection.remove(element);
}

int Service::colNroc(TElem element)
{
	return collection.nroccurrences(element);
}

bool Service::searchcol(TElem element)
{
	if (collection.search(element) == false)
	{
		throw MyException("There is no change!");
	}
	return collection.search(element);
}

int Service::getSize()
{
	if (repo.getSize() == 0)
	{
		throw MyException("Vending machine is empty!");
	}
	return repo.getSize();
}

std::vector<Produs> Service::getAll()
{
	return repo.getAll();
}

Produs Service::getElem(int poz)
{
	
	return repo.getElem(poz);
}

void Service::addElem(int cod, std::string nume, int pret)
{
	try
	{
		this->vali.validatecod(cod);
		this->vali.validatenume(nume);
		this->vali.validatepret(pret);
		repo.addElem(Produs(cod, nume, pret));
	}
	catch (MyException& msg)
	{
		throw msg;
	}
}

void Service::delElem(int poz)
{
	if (repo.findPoz(poz) == false)
	{
		throw MyException("There is no object on this position!");
	}
	else repo.delElem(poz);
}

int Service::getPoz(Produs element)
{
	for (int i = 0; i < repo.getSize(); i++)
	{
		if (repo.getElem(i) == element) return i;
	}
	return 0;
}
