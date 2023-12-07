#include "Rochii.h"
#include <vector>
#ifndef REPO_HEADER
#define REPO_HEADER

class Repo
{
private:
	std::vector<Rochie> rochii;
	string filename;
	void readfromfile();
	void writetofile();

public:
	Repo();
	Repo(string name);
	~Repo();

	int getSize();
	void updateRochie(int poz, const Rochie& c);
	Rochie getRochie(int poz);
	std::vector<Rochie> getAll();
};
#endif // !REPO_HEADER