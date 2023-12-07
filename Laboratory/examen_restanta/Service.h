#include "Repo.h"
#include "Exception.h"
#ifndef SERVICE_HEADER
#define SERVICE_HEADER

class Service
{
private:
	Repo repo;
public:
	Service();
	~Service();

	std::vector<Bacterie> returnare_bacterii_tip(int tip);

	int getSize();
	Bacterie getBacterie(int poz);
	std::vector<Bacterie> getAll();
	void updateBacterie(int poz, string denumire, int varsta, int tip);

	std::vector<Bacterie> inmultire(int nr_unitati);
	int medie(std::vector<Bacterie> bacterii);

	void addBacterie(string denumire, int varsta, int tip);

};
#endif // !SERVICE_HEADER
#pragma once
