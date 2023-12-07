#include "Repo.h"
#include "Exception.h"
#ifndef SERVICE_H
#define SERVICE_H

class Service
{
private:
	Repo repo;
public:
	Service();
	Service(Repo repo)
	{
		this->repo = repo;
	}
	~Service();

	std::vector<Rochie> criterii(string marime, string person);
	std::vector<Rochie> top3();
	void cumparare(int id);

	int getSize();
	std::vector<Rochie> getAll();
	Rochie getRochie(int poz);
	void updateRochie(int poz, int id, string denumire, string marime, string culoare, int nr, int pret, bool personabilizare);
};
#endif // !SERVICE_H
