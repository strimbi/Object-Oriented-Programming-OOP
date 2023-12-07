#include "entitate.h"
#include <vector>
#ifndef REPO_HEADER
#define REPO_HEADER

class Repo
{
private:
	std::vector<Produs> produse;

public:
	Repo();
	~Repo();

	bool findPoz(int poz);
	void addElem(const Produs& p);
	void delElem(int poz);
	int getSize();
	void update(int poz, const Produs& p);
	Produs getElem(int poz);
	std::vector<Produs> getAll();
};
#endif