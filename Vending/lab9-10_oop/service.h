#include "repo.h"
#include "collection.h"
#include "repofile.h"
#include "exception.h"
#include <vector>
#include "validator.h"
#ifndef SERVICE_H
#define SERVICE_H

using namespace std;

class Service
{
private:
	RepoFile repo;
	Validator vali;
	Collection collection;

public:
	Service();
	Service(RepoFile repo)
	{
		this->repo = repo;
	}
	~Service();

	int colSize();
	int colgetElem(int poz);
	void colAddElem(TElem element);
	void coldDelElem(TElem element);
	int colNroc(TElem element);
	bool searchcol(TElem element);

	int getSize();
	Produs getElem(int poz);
	std::vector<Produs> getAll();
	void addElem(int cod, std::string nume, int pret);
	void delElem(int poz);
	int getPoz(Produs element);
};

#endif // !SERVICE_H
