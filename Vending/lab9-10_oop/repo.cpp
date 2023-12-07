#include <iostream>
#include <vector>
#include "repo.h"

Repo::Repo()
{
}

Repo::~Repo()
{
}

bool Repo::findPoz(int poz)
{
	int nr = produse.size();
	for (int i = 0; i < nr; i++)
	{
		if (i == poz) return true;
	}
	return false;
}

void Repo::addElem(const Produs& p)
{
	this->produse.push_back(p);
}

void Repo::delElem(int poz)
{
	std::vector<Produs>::iterator it;
	it = produse.begin() + poz;
	this->produse.erase(it);
}

Produs Repo::getElem(int poz)
{
	return produse[poz];
}

int Repo::getSize()
{
	return produse.size();
}

std::vector<Produs> Repo::getAll()
{
	return this->produse;
}

void Repo::update(int poz, const Produs& p)
{
	this->produse[poz] = p;
}
