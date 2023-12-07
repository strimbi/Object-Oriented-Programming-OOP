#include "Repo.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

Repo::Repo()
{
}

Repo::~Repo()
{
}

int Repo::getSize()
{
	return this->bacterii.size();
}

Bacterie Repo::getBacterie(int poz)
{
	return this->bacterii[poz];
}

std::vector<Bacterie> Repo::getAll()
{
	return this->bacterii;
}

void Repo::updateBacterie(int poz, const Bacterie& c)
{
	this->bacterii[poz] = c;
}

void Repo::addBacterie(const Bacterie& c)
{
	this->bacterii.push_back(c);
}